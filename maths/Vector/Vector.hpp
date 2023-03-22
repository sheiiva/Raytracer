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

        /** \class Vector
         * @brief Template class representing a Vector of size N.
         * 
         * @tparam N Size of the Vector.
         */
        template <std::size_t N>
        class Vector
        {
            public:
                /** @name Constructor/Destructor
                 *
                 */
                ///@{
                /**
                 * @brief Construct a new Vector object of size N.
                 * 
                 */
                Vector() noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = 0;
                }

                /**
                 * @brief Construct a new Vector object of size N.
                 * 
                 * @param args List of arguments to initialize the vector.
                 */
                template<typename... Args>
                Vector(Args... args) noexcept
                {
                    static_assert(sizeof...(args) == N, "Incorrect number of arguments provided.");

                    std::array<double, N> temp = { static_cast<double>(args)... };
                    std::copy(temp.begin(), temp.end(), _data.begin());
                }

                /**
                 * @brief Construct a new Vector object of size N from \p b copy.
                 * 
                 * @param b Vector to copy.
                 */
                Vector(Vector const& b) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = b[i];
                }

                /**
                 * @brief Construct a new Vector object of size N from \p b move.
                 * 
                 * @param b Vector to move.
                 */
                Vector(Vector&& b) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = b[i];
                }

                /**
                 * @brief Destroy the Vector object.
                 * 
                 */
                ~Vector() noexcept = default;
                ///@}

                /** @name Operators
                 *
                 */
                ///@{
                /**
                 * @brief Copy assignment operator.
                 * 
                 * @param rhs Vector to copy.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = rhs[i];
                    return *this;
                }

                /**
                 * @brief Move assignment operator.
                 * 
                 * @param rhs Vector to move.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator=(Vector&& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] = rhs._data[i];
                    return *this;
                }

                /**
                 * @brief Compare two vectors.
                 * 
                 * @param rhs Vector to compare.
                 * @return `bool` `true` if the vectors are equal, `false` otherwise.
                 */
                bool operator==(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++) {
                        if (_data[i] != rhs._data[i])
                            return false;
                    }
                    return true;
                }

                /**
                 * @brief Compare two vectors.
                 * 
                 * @param rhs Vector to compare.
                 * @return `bool` `true` if the vectors are not equal, `false` otherwise.
                 */
                bool operator!=(Vector const& rhs) noexcept
                {
                    return !(*this == rhs);
                }

                /**
                 * @brief Add a vector to the current one.
                 * 
                 * @param rhs Vector to add.
                 * @return `Vector&` New vector.
                 */
                Vector operator+(Vector const& rhs) const noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] + rhs._data[i];
                    return result;
                }

                /**
                 * @brief Add a vector to the current one.
                 * 
                 * @param rhs Vector to add.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator+=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] += rhs._data[i];
                    return *this;
                }

                /**
                 * @brief Subtract a vector to the current one.
                 * 
                 * @param rhs Vector to subtract.
                 * @return `Vector&` New vector.
                 */
                Vector operator-(Vector const& rhs) const noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] - rhs._data[i];
                    return result;
                }

                /**
                 * @brief Subtract a vector to the current one.
                 * 
                 * @param rhs Vector to subtract.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator-=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] -= rhs._data[i];
                    return *this;
                }

                /**
                 * @brief Multiply a vector to the current one.
                 * 
                 * @param rhs Vector to multiply.
                 * @return `Vector&` New vector.
                 */
                Vector operator*(Vector const& rhs) const noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] * rhs._data[i];
                    return result;
                }

                /**
                 * @brief Multiply a vector to the current one.
                 * 
                 * @param rhs Vector to multiply.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator*=(Vector const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] *= rhs._data[i];
                    return *this;
                }

                /**
                 * @brief Divide a vector to the current one.
                 * 
                 * @param rhs Vector to divide.
                 * @return `Vector&` New vector.
                 */
                Vector operator/(Vector const& rhs) const
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] / rhs._data[i];
                    return result;
                }

                /**
                 * @brief Divide a vector to the current one.
                 * 
                 * @param rhs Vector to divide.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator/=(Vector const& rhs)
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] /= rhs._data[i];
                    return *this;
                }

                /**
                 * @brief Multiply a vector by a scalar.
                 * 
                 * @param rhs Scalar to multiply.
                 * @return `Vector&` New vector.
                 */
                Vector operator*(double const& rhs) const noexcept
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] * rhs;
                    return result;
                }

                /**
                 * @brief Multiply a vector by a scalar.
                 * 
                 * @param rhs Scalar to multiply.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator*=(double const& rhs) noexcept
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] *= rhs;
                    return *this;
                }

                /**
                 * @brief Divide a vector by a scalar.
                 * 
                 * @param rhs Scalar to divide.
                 * @return `Vector&` New vector.
                 */
                Vector operator/(double const& rhs) const
                {
                    Vector<N> result;

                    for (std::size_t i = 0; i < N; i++)
                        result._data[i] = _data[i] / rhs;
                    return result;
                }

                /**
                 * @brief Divide a vector by a scalar.
                 * 
                 * @param rhs Scalar to divide.
                 * @return `Vector&` Reference to the current vector.
                 */
                Vector& operator/=(double const& rhs)
                {
                    for (std::size_t i = 0; i < N; i++)
                        _data[i] /= rhs;
                    return *this;
                }
                ///@}

                /** @name Element access
                 *
                 */
                ///@{
                /**
                 * @brief Access the element at the given index.
                 * 
                 * @param index Index of the element to access.
                 * @return `double` Element at the given index.
                 */
                double operator[](std::size_t const& index) const noexcept
                {
                    return _data[index];
                }
                ///@}

                /** @name Capacity
                 *
                 */
                ///@{
                /**
                 * @brief Get the length of the vector.
                 * 
                 * @return `double` Length of the vector.
                 */
                std::size_t length() const noexcept
                {
                    return N;
                }
                ///@}

                /** @name Member functions
                 *
                 */
                ///@{
                /**
                 * @brief Get the norm of the vector.
                 * 
                 * @return `double` Norm of the vector.
                 */
                double dot(Vector const& rhs) const noexcept
                {
                    double result = 0;

                    for (std::size_t i = 0; i < N; i++)
                        result += _data[i] * rhs[i];
                    return result;
                }
                ///@}

            private:
                /// @brief Data of the vector.
                std::array<double, N> _data;
        };

    } /* namespace Maths */

#endif /* !VECTOR_HPP_ */