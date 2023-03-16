/* File: Sphere.cpp
**
** Description: [DESCRIPTION]
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Sphere.hpp"

namespace RayTracer
{
    Sphere::Sphere(Maths::Vector<3> const& center, double radius) noexcept
        : _center(center), _radius(radius)
    {
    }

    Maths::Vector<3> const& Sphere::getCenter() const noexcept
    {
        return _center;
    }

    double Sphere::getRadius() const noexcept
    {
        return _radius;
    }

    void Sphere::setCenter(Maths::Vector<3> const& center) noexcept
    {
        _center = center;
    }

    void Sphere::setRadius(double radius) noexcept
    {
        _radius = radius;
    }

    bool Sphere::hit(Ray const& ray) noexcept
    {
        Maths::Vector<3>    oc = ray.getOrigin() - _center;
        double              a = ray.getDirection().dot(ray.getDirection());
        double              b = 2.0 * oc.dot(ray.getDirection());
        double              c = oc.dot(oc) - _radius * _radius;
        double              discriminant = b * b - 4 * a * c;

        return (discriminant > 0);
    }
}