/* File: Ray.cpp
**
** Description: Declaration of the Ray class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Ray.hpp"

namespace RayTracer
{

    Ray::Ray(Maths::Vector<3> const& origin, Maths::Vector<3> const& direction) noexcept
        : _origin(origin), _direction(direction)
    {
    }

    Ray::Ray(Ray const& b) noexcept
        : _origin(b.getOrigin()), _direction(b.getDirection())
    {
    }

    Ray::Ray(Ray&& b) noexcept
        : _origin(std::move(b.getOrigin())), _direction(std::move(b.getDirection()))
    {
    }

    Ray& Ray::operator=(Ray const& rhs) noexcept
    {
        _origin = rhs.getOrigin();
        _direction = rhs.getDirection();
        return *this;
    }

    Ray& Ray::operator=(Ray&& rhs) noexcept
    {
        _origin = std::move(rhs.getOrigin());
        _direction = std::move(rhs.getDirection());
        return *this;
    }

    Maths::Vector<3> const& Ray::getOrigin() const noexcept
    {
        return _origin;
    }

    Maths::Vector<3> const& Ray::getDirection() const noexcept
    {
        return _direction;
    }

    void Ray::setOrigin(Maths::Vector<3> const& origin) noexcept
    {
        _origin = origin;
    }

    void Ray::setDirection(Maths::Vector<3> const& direction) noexcept
    {
        _direction = direction;
    }

} /* namespace RayTracer */