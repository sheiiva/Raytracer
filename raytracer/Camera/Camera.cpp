/* File: Camera.cpp
**
** Description: Declaration of the Camera class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Camera.hpp"

namespace RayTracer
{
    Maths::Vector<3> const& Camera::getOrigin() const noexcept
    {
        return _origin;
    }

    Maths::Vector<3> const& Camera::getHorizontal() const noexcept
    {
        return _horizontal;
    }

    Maths::Vector<3> const& Camera::getVertical() const noexcept
    {
        return _vertical;
    }

    Maths::Vector<3> const& Camera::getLowerLeftCorner() const noexcept
    {
        return _lowerLeftCorner;
    }

    void Camera::setOrigin(Maths::Vector<3> const& origin) noexcept
    {
        _origin = origin;
    }

    void Camera::setHorizontal(Maths::Vector<3> const& horizontal) noexcept
    {
        _horizontal = horizontal;
    }

    void Camera::setVertical(Maths::Vector<3> const& vertical) noexcept
    {
        _vertical = vertical;
    }

    void Camera::setLowerLeftCorner(Maths::Vector<3> const& lowerLeftCorner) noexcept
    {
        _lowerLeftCorner = lowerLeftCorner;
    }

    Ray Camera::ray(double u, double v) const noexcept
    {
        Maths::Vector<3> direction = _lowerLeftCorner + (_horizontal * u) + (_vertical * v);

        return Ray(_origin, direction - _origin);
    }

}