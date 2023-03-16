/* File: Ray_tests.cpp
**
** Description: [DESCRIPTION]
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <gtest/gtest.h>

#include "Ray.hpp"

TEST(Ray, DefaultConstructor)
{
    RayTracer::Ray r;

    EXPECT_EQ(r.getOrigin()[0], 0);
    EXPECT_EQ(r.getOrigin()[1], 0);
    EXPECT_EQ(r.getOrigin()[2], 0);
    EXPECT_EQ(r.getDirection()[0], 0);
    EXPECT_EQ(r.getDirection()[1], 0);
    EXPECT_EQ(r.getDirection()[2], 0);
}

TEST(Ray, SpeConstructor)
{
    RayTracer::Ray r(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));

    EXPECT_EQ(r.getOrigin()[0], 1);
    EXPECT_EQ(r.getOrigin()[1], 2);
    EXPECT_EQ(r.getOrigin()[2], 3);
    EXPECT_EQ(r.getDirection()[0], 4);
    EXPECT_EQ(r.getDirection()[1], 5);
    EXPECT_EQ(r.getDirection()[2], 6);
}

TEST(Ray, CopyConstructor)
{
    RayTracer::Ray r1(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));
    RayTracer::Ray r2(r1);

    EXPECT_EQ(r2.getOrigin()[0], 1);
    EXPECT_EQ(r2.getOrigin()[1], 2);
    EXPECT_EQ(r2.getOrigin()[2], 3);
    EXPECT_EQ(r2.getDirection()[0], 4);
    EXPECT_EQ(r2.getDirection()[1], 5);
    EXPECT_EQ(r2.getDirection()[2], 6);
}

TEST(Ray, MoveConstructor)
{
    RayTracer::Ray r1(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));
    RayTracer::Ray r2(std::move(r1));

    EXPECT_EQ(r2.getOrigin()[0], 1);
    EXPECT_EQ(r2.getOrigin()[1], 2);
    EXPECT_EQ(r2.getOrigin()[2], 3);
    EXPECT_EQ(r2.getDirection()[0], 4);
    EXPECT_EQ(r2.getDirection()[1], 5);
    EXPECT_EQ(r2.getDirection()[2], 6);
}

TEST(Ray, CopyAssignment)
{
    RayTracer::Ray r1(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));
    RayTracer::Ray r2;

    r2 = r1;

    EXPECT_EQ(r2.getOrigin()[0], 1);
    EXPECT_EQ(r2.getOrigin()[1], 2);
    EXPECT_EQ(r2.getOrigin()[2], 3);
    EXPECT_EQ(r2.getDirection()[0], 4);
    EXPECT_EQ(r2.getDirection()[1], 5);
    EXPECT_EQ(r2.getDirection()[2], 6);
}

TEST(Ray, MoveAssignment)
{
    RayTracer::Ray r1(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));
    RayTracer::Ray r2;

    r2 = std::move(r1);

    EXPECT_EQ(r2.getOrigin()[0], 1);
    EXPECT_EQ(r2.getOrigin()[1], 2);
    EXPECT_EQ(r2.getOrigin()[2], 3);
    EXPECT_EQ(r2.getDirection()[0], 4);
    EXPECT_EQ(r2.getDirection()[1], 5);
    EXPECT_EQ(r2.getDirection()[2], 6);
}

TEST(Ray, GetOrigin)
{
    RayTracer::Ray r(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));

    EXPECT_EQ(r.getOrigin()[0], 1);
    EXPECT_EQ(r.getOrigin()[1], 2);
    EXPECT_EQ(r.getOrigin()[2], 3);
}

TEST(Ray, GetDirection)
{
    RayTracer::Ray r(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));

    EXPECT_EQ(r.getDirection()[0], 4);
    EXPECT_EQ(r.getDirection()[1], 5);
    EXPECT_EQ(r.getDirection()[2], 6);
}

TEST(Ray, SetOrigin)
{
    RayTracer::Ray r(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));

    r.setOrigin(Maths::Vector<3>(7, 8, 9));

    EXPECT_EQ(r.getOrigin()[0], 7);
    EXPECT_EQ(r.getOrigin()[1], 8);
    EXPECT_EQ(r.getOrigin()[2], 9);
}

TEST(Ray, SetDirection)
{
    RayTracer::Ray r(Maths::Vector<3>(1, 2, 3), Maths::Vector<3>(4, 5, 6));

    r.setDirection(Maths::Vector<3>(7, 8, 9));

    EXPECT_EQ(r.getDirection()[0], 7);
    EXPECT_EQ(r.getDirection()[1], 8);
    EXPECT_EQ(r.getDirection()[2], 9);
}