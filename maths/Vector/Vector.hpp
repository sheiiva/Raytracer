/* File: Vector.hpp
**
** Description: Declaration and definition of the Vector class of size N
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef VECTOR_HPP_
    #define VECTOR_HPP_

    #include <array>
    #include <cstddef>
    #include <stdarg.h>

    namespace Maths
    {

        template <std::size_t N>
        class Vector
        {
            public:
                Vector() noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = 0;
                }

                template<typename... Args>
                Vector(Args... args) noexcept
                {
                    static_assert(sizeof...(args) == N, "Incorrect number of arguments provided.");

                    std::array<double, N> temp = { static_cast<double>(args)... };
                    std::copy(temp.begin(), temp.end(), _data.begin());
                }

                Vector(Vector const& b) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = b[i];
                }

                Vector(Vector&& b) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = b[i];
                }

                ~Vector() noexcept = default;
        
                Vector& operator=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = rhs[i];
                    return *this;
                }

                Vector& operator=(Vector&& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = rhs._data[i];
                    return *this;
                }

                double operator[](std::size_t const& index) const noexcept
                {
                    return _data[index];
                }

                bool operator==(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++) {
                        if (_data[i] != rhs._data[i])
                            return false;
                    }
                    return true;
                }

                bool operator!=(Vector const& rhs) noexcept
                {
                    return !(*this == rhs);
                }

                Vector operator+(Vector const& rhs) noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] + rhs._data[i];
                    return result;
                }

                Vector& operator+=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] += rhs._data[i];
                    return *this;
                }

                Vector operator-(Vector const& rhs) noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] - rhs._data[i];
                    return result;
                }

                Vector& operator-=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] -= rhs._data[i];
                    return *this;
                }

                Vector operator*(Vector const& rhs) noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] * rhs._data[i];
                    return result;
                }

                Vector& operator*=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] *= rhs._data[i];
                    return *this;
                }

                Vector operator/(Vector const& rhs)
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] / rhs._data[i];
                    return result;
                }

                Vector& operator/=(Vector const& rhs)
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] /= rhs._data[i];
                    return *this;
                }

                Vector operator*(double const& rhs) noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] * rhs;
                    return result;
                }

                Vector& operator*=(double const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] *= rhs;
                    return *this;
                }

                Vector operator/(double const& rhs)
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] / rhs;
                    return result;
                }

                Vector& operator/=(double const& rhs)
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] /= rhs;
                    return *this;
                }

            public:
                std::size_t length() const noexcept { return N; }

                double dot(Vector const& rhs) const noexcept
                {
                    double result = 0;

                    for (std::size_t i = 0; i < N; i++)
                        result += _data[i] * rhs[i];
                    return result;
                }

            private:
                std::array<double, N> _data;
        };

    } /* namespace Maths */

#endif /* !VECTOR_HPP_ */