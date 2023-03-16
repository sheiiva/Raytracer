/* File: Ray.hpp
**
** Description: Declaration of the Ray class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Vector.hpp"

    namespace RayTracer
    {

        class Ray
        {
            public:
                Ray() noexcept = default;
                Ray(Maths::Vector<3> const& origin, Maths::Vector<3> const& direction) noexcept;
                Ray(Ray const& b) noexcept;
                Ray(Ray&& b) noexcept;
                ~Ray() noexcept = default;

                Ray& operator=(Ray const& rhs) noexcept;
                Ray& operator=(Ray&& rhs) noexcept;

                Maths::Vector<3> const& getOrigin() const noexcept;
                Maths::Vector<3> const& getDirection() const noexcept;

                void setOrigin(Maths::Vector<3> const& origin) noexcept;
                void setDirection(Maths::Vector<3> const& direction) noexcept;

            private:
                Maths::Vector<3> _origin;
                Maths::Vector<3> _direction;
        };

    } /* namespace RayTracer */

#endif /* !RAY_HPP_ */