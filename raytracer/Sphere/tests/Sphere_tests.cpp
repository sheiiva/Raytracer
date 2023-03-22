/* File: Sphere_tests.cpp
**
** Description: Tests for the Sphere class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <gtest/gtest.h>

#include "Sphere.hpp"

TEST(Sphere, DefaultConstructor)
{
    RayTracer::Sphere s;

    EXPECT_EQ(s.getCenter()[0], 0);
    EXPECT_EQ(s.getCenter()[1], 0);
    EXPECT_EQ(s.getCenter()[2], 0);
    EXPECT_EQ(s.getRadius(), 0);
}

TEST(Sphere, SpeConstructor)
{
    RayTracer::Sphere s(Maths::Vector<3>(1, 2, 3), 4);

    EXPECT_EQ(s.getCenter()[0], 1);
    EXPECT_EQ(s.getCenter()[1], 2);
    EXPECT_EQ(s.getCenter()[2], 3);
    EXPECT_EQ(s.getRadius(), 4);
}

TEST(Sphere, CopyConstructor)
{
    RayTracer::Sphere s1(Maths::Vector<3>(1, 2, 3), 4);
    RayTracer::Sphere s2(s1);

    EXPECT_EQ(s2.getCenter()[0], 1);
    EXPECT_EQ(s2.getCenter()[1], 2);
    EXPECT_EQ(s2.getCenter()[2], 3);
    EXPECT_EQ(s2.getRadius(), 4);
}

TEST(Sphere, MoveConstructor)
{
    RayTracer::Sphere s1(Maths::Vector<3>(1, 2, 3), 4);
    RayTracer::Sphere s2(std::move(s1));

    EXPECT_EQ(s2.getCenter()[0], 1);
    EXPECT_EQ(s2.getCenter()[1], 2);
    EXPECT_EQ(s2.getCenter()[2], 3);
    EXPECT_EQ(s2.getRadius(), 4);
}

TEST(Sphere, CopyAssignment)
{
    RayTracer::Sphere s1(Maths::Vector<3>(1, 2, 3), 4);
    RayTracer::Sphere s2;

    s2 = s1;

    EXPECT_EQ(s2.getCenter()[0], 1);
    EXPECT_EQ(s2.getCenter()[1], 2);
    EXPECT_EQ(s2.getCenter()[2], 3);
    EXPECT_EQ(s2.getRadius(), 4);
}

TEST(Sphere, MoveAssignment)
{
    RayTracer::Sphere s1(Maths::Vector<3>(1, 2, 3), 4);
    RayTracer::Sphere s2;

    s2 = std::move(s1);

    EXPECT_EQ(s2.getCenter()[0], 1);
    EXPECT_EQ(s2.getCenter()[1], 2);
    EXPECT_EQ(s2.getCenter()[2], 3);
    EXPECT_EQ(s2.getRadius(), 4);
}

TEST(Sphere, GetCenter)
{
    RayTracer::Sphere s(Maths::Vector<3>(1, 2, 3), 4);

    EXPECT_EQ(s.getCenter()[0], 1);
    EXPECT_EQ(s.getCenter()[1], 2);
    EXPECT_EQ(s.getCenter()[2], 3);
}

TEST(Sphere, GetRadius)
{
    RayTracer::Sphere s(Maths::Vector<3>(1, 2, 3), 4);

    EXPECT_EQ(s.getRadius(), 4);
}

TEST(Sphere, SetCenter)
{
    RayTracer::Sphere s;

    s.setCenter(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(s.getCenter()[0], 1);
    EXPECT_EQ(s.getCenter()[1], 2);
    EXPECT_EQ(s.getCenter()[2], 3);
}

TEST(Sphere, SetRadius)
{
    RayTracer::Sphere s;

    s.setRadius(4);

    EXPECT_EQ(s.getRadius(), 4);
}

TEST(Sphere, HitTrueCase)
{
    RayTracer::Sphere s(Maths::Vector<3>(0, 0, 0), 1);
    RayTracer::Ray r(Maths::Vector<3>(0, 0, -5), Maths::Vector<3>(0, 0, 1));

    EXPECT_TRUE(s.hit(r));
}

TEST(Sphere, HitFalseCase)
{
    RayTracer::Sphere s(Maths::Vector<3>(0, 0, 0), 1);
    RayTracer::Ray r(Maths::Vector<3>(0, 0, -5), Maths::Vector<3>(0, 1, 0));

    EXPECT_FALSE(s.hit(r));
}