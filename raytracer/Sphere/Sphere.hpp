/* File: Sphere.hpp
**
** Description: Declaration of the Sphere class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "Vector.hpp"
    #include "Ray.hpp"

    namespace RayTracer
    {

        class Sphere
        {
            public:
                Sphere() noexcept = default;
                Sphere(Maths::Vector<3> const& center, double radius) noexcept;
                Sphere(Sphere const& b) noexcept = default;
                Sphere(Sphere&& b) noexcept = default;
                ~Sphere() noexcept = default;

                Sphere& operator=(Sphere const& rhs) noexcept = default;
                Sphere& operator=(Sphere&& rhs) noexcept = default;

                // Getters
                Maths::Vector<3> const& getCenter() const noexcept;
                double getRadius() const noexcept;
                // Setters
                void setCenter(Maths::Vector<3> const& center) noexcept;
                void setRadius(double radius) noexcept;

                // Methods
                bool hit(Ray const& ray) noexcept;

            private:
                Maths::Vector<3>    _center;
                double              _radius = 0.;
        };

    } /* namespace RayTracer */

#endif /* !RAY_HPP_ */