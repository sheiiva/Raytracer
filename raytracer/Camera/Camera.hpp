/* File: Camera.hpp
**
** Description: Definition of the Camera class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Vector.hpp"
    #include "Ray.hpp"

    namespace RayTracer
    {

        class Camera
        {
            public:
                Camera() noexcept = default;
                Camera(Camera const& b) noexcept = default;
                Camera(Camera&& b) noexcept = default;
                ~Camera() noexcept = default;

                Camera& operator=(Camera const& rhs) noexcept = default;
                Camera& operator=(Camera&& rhs) noexcept = default;

                // Getters
                Maths::Vector<3> const& getOrigin() const noexcept;
                Maths::Vector<3> const& getHorizontal() const noexcept;
                Maths::Vector<3> const& getVertical() const noexcept;
                Maths::Vector<3> const& getLowerLeftCorner() const noexcept;

                // Setters
                void setOrigin(Maths::Vector<3> const& origin) noexcept;
                void setHorizontal(Maths::Vector<3> const& horizontal) noexcept;
                void setVertical(Maths::Vector<3> const& vertical) noexcept;
                void setLowerLeftCorner(Maths::Vector<3> const& lowerLeftCorner) noexcept;

                // Methods
                Ray ray(double u, double v) const noexcept;

            private:
                Maths::Vector<3>    _origin;
                Maths::Vector<3>    _horizontal;
                Maths::Vector<3>    _vertical;
                Maths::Vector<3>    _lowerLeftCorner;
        };

    } /* namespace RayTracer */

#endif /* !CAMERA_HPP_ */