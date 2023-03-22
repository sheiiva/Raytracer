/* File: Camera_tests.cpp
**
** Description: [DESCRIPTION]
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <gtest/gtest.h>

#include "Camera.hpp"

TEST(Camera, DefaultConstructor)
{
    RayTracer::Camera c;

    EXPECT_EQ(c.getOrigin()[0], 0);
    EXPECT_EQ(c.getOrigin()[1], 0);
    EXPECT_EQ(c.getOrigin()[2], 0);
    EXPECT_EQ(c.getHorizontal()[0], 0);
    EXPECT_EQ(c.getHorizontal()[1], 0);
    EXPECT_EQ(c.getHorizontal()[2], 0);
    EXPECT_EQ(c.getVertical()[0], 0);
    EXPECT_EQ(c.getVertical()[1], 0);
    EXPECT_EQ(c.getVertical()[2], 0);
    EXPECT_EQ(c.getLowerLeftCorner()[0], 0);
    EXPECT_EQ(c.getLowerLeftCorner()[1], 0);
    EXPECT_EQ(c.getLowerLeftCorner()[2], 0);
}

TEST(Camera, CopyConstructor)
{
    RayTracer::Camera c1;

    c1.setOrigin(Maths::Vector<3>(1, 2, 3));
    c1.setHorizontal(Maths::Vector<3>(4, 5, 6));
    c1.setVertical(Maths::Vector<3>(7, 8, 9));
    c1.setLowerLeftCorner(Maths::Vector<3>(10, 11, 12));

    RayTracer::Camera c2(c1);

    EXPECT_EQ(c2.getOrigin()[0], 1);
    EXPECT_EQ(c2.getOrigin()[1], 2);
    EXPECT_EQ(c2.getOrigin()[2], 3);
    EXPECT_EQ(c2.getHorizontal()[0], 4);
    EXPECT_EQ(c2.getHorizontal()[1], 5);
    EXPECT_EQ(c2.getHorizontal()[2], 6);
    EXPECT_EQ(c2.getVertical()[0], 7);
    EXPECT_EQ(c2.getVertical()[1], 8);
    EXPECT_EQ(c2.getVertical()[2], 9);
    EXPECT_EQ(c2.getLowerLeftCorner()[0], 10);
    EXPECT_EQ(c2.getLowerLeftCorner()[1], 11);
    EXPECT_EQ(c2.getLowerLeftCorner()[2], 12);
}

TEST(Camera, MoveConstructor)
{
    RayTracer::Camera c1;

    c1.setOrigin(Maths::Vector<3>(1, 2, 3));
    c1.setHorizontal(Maths::Vector<3>(4, 5, 6));
    c1.setVertical(Maths::Vector<3>(7, 8, 9));
    c1.setLowerLeftCorner(Maths::Vector<3>(10, 11, 12));

    RayTracer::Camera c2(std::move(c1));

    EXPECT_EQ(c2.getOrigin()[0], 1);
    EXPECT_EQ(c2.getOrigin()[1], 2);
    EXPECT_EQ(c2.getOrigin()[2], 3);
    EXPECT_EQ(c2.getHorizontal()[0], 4);
    EXPECT_EQ(c2.getHorizontal()[1], 5);
    EXPECT_EQ(c2.getHorizontal()[2], 6);
    EXPECT_EQ(c2.getVertical()[0], 7);
    EXPECT_EQ(c2.getVertical()[1], 8);
    EXPECT_EQ(c2.getVertical()[2], 9);
    EXPECT_EQ(c2.getLowerLeftCorner()[0], 10);
    EXPECT_EQ(c2.getLowerLeftCorner()[1], 11);
    EXPECT_EQ(c2.getLowerLeftCorner()[2], 12);
}

TEST(Camera, CopyAssignment)
{
    RayTracer::Camera c1;

    c1.setOrigin(Maths::Vector<3>(1, 2, 3));
    c1.setHorizontal(Maths::Vector<3>(4, 5, 6));
    c1.setVertical(Maths::Vector<3>(7, 8, 9));
    c1.setLowerLeftCorner(Maths::Vector<3>(10, 11, 12));

    RayTracer::Camera c2;

    c2 = c1;

    EXPECT_EQ(c2.getOrigin()[0], 1);
    EXPECT_EQ(c2.getOrigin()[1], 2);
    EXPECT_EQ(c2.getOrigin()[2], 3);
    EXPECT_EQ(c2.getHorizontal()[0], 4);
    EXPECT_EQ(c2.getHorizontal()[1], 5);
    EXPECT_EQ(c2.getHorizontal()[2], 6);
    EXPECT_EQ(c2.getVertical()[0], 7);
    EXPECT_EQ(c2.getVertical()[1], 8);
    EXPECT_EQ(c2.getVertical()[2], 9);
    EXPECT_EQ(c2.getLowerLeftCorner()[0], 10);
    EXPECT_EQ(c2.getLowerLeftCorner()[1], 11);
    EXPECT_EQ(c2.getLowerLeftCorner()[2], 12);
}

TEST(Camera, MoveAssignment)
{
    RayTracer::Camera c1;

    c1.setOrigin(Maths::Vector<3>(1, 2, 3));
    c1.setHorizontal(Maths::Vector<3>(4, 5, 6));
    c1.setVertical(Maths::Vector<3>(7, 8, 9));
    c1.setLowerLeftCorner(Maths::Vector<3>(10, 11, 12));

    RayTracer::Camera c2;

    c2 = std::move(c1);

    EXPECT_EQ(c2.getOrigin()[0], 1);
    EXPECT_EQ(c2.getOrigin()[1], 2);
    EXPECT_EQ(c2.getOrigin()[2], 3);
    EXPECT_EQ(c2.getHorizontal()[0], 4);
    EXPECT_EQ(c2.getHorizontal()[1], 5);
    EXPECT_EQ(c2.getHorizontal()[2], 6);
    EXPECT_EQ(c2.getVertical()[0], 7);
    EXPECT_EQ(c2.getVertical()[1], 8);
    EXPECT_EQ(c2.getVertical()[2], 9);
    EXPECT_EQ(c2.getLowerLeftCorner()[0], 10);
    EXPECT_EQ(c2.getLowerLeftCorner()[1], 11);
    EXPECT_EQ(c2.getLowerLeftCorner()[2], 12);
}

TEST(Camera, GetOrigin)
{
    RayTracer::Camera c;

    c.setOrigin(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getOrigin()[0], 1);
    EXPECT_EQ(c.getOrigin()[1], 2);
    EXPECT_EQ(c.getOrigin()[2], 3);
}

TEST(Camera, GetHorizontal)
{
    RayTracer::Camera c;

    c.setHorizontal(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getHorizontal()[0], 1);
    EXPECT_EQ(c.getHorizontal()[1], 2);
    EXPECT_EQ(c.getHorizontal()[2], 3);
}

TEST(Camera, GetVertical)
{
    RayTracer::Camera c;

    c.setVertical(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getVertical()[0], 1);
    EXPECT_EQ(c.getVertical()[1], 2);
    EXPECT_EQ(c.getVertical()[2], 3);
}

TEST(Camera, GetLowerLeftCorner)
{
    RayTracer::Camera c;

    c.setLowerLeftCorner(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getLowerLeftCorner()[0], 1);
    EXPECT_EQ(c.getLowerLeftCorner()[1], 2);
    EXPECT_EQ(c.getLowerLeftCorner()[2], 3);
}

TEST(Camera, SetOrigin)
{
    RayTracer::Camera c;

    c.setOrigin(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getOrigin()[0], 1);
    EXPECT_EQ(c.getOrigin()[1], 2);
    EXPECT_EQ(c.getOrigin()[2], 3);
}

TEST(Camera, SetHorizontal)
{
    RayTracer::Camera c;

    c.setHorizontal(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getHorizontal()[0], 1);
    EXPECT_EQ(c.getHorizontal()[1], 2);
    EXPECT_EQ(c.getHorizontal()[2], 3);
}

TEST(Camera, SetVertical)
{
    RayTracer::Camera c;

    c.setVertical(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getVertical()[0], 1);
    EXPECT_EQ(c.getVertical()[1], 2);
    EXPECT_EQ(c.getVertical()[2], 3);
}

TEST(Camera, SetLowerLeftCorner)
{
    RayTracer::Camera c;

    c.setLowerLeftCorner(Maths::Vector<3>(1, 2, 3));

    EXPECT_EQ(c.getLowerLeftCorner()[0], 1);
    EXPECT_EQ(c.getLowerLeftCorner()[1], 2);
    EXPECT_EQ(c.getLowerLeftCorner()[2], 3);
}

TEST(Camera, Ray)
{
    RayTracer::Camera c;

    c.setOrigin(Maths::Vector<3>(1, 2, 3));
    c.setHorizontal(Maths::Vector<3>(4, 5, 6));
    c.setVertical(Maths::Vector<3>(7, 8, 9));
    c.setLowerLeftCorner(Maths::Vector<3>(10, 11, 12));

    RayTracer::Ray r = c.ray(0.5, 0.5);

    EXPECT_EQ(r.getOrigin()[0], 1);
    EXPECT_EQ(r.getOrigin()[1], 2);
    EXPECT_EQ(r.getOrigin()[2], 3);
    EXPECT_EQ(r.getDirection()[0], 10 + 4 * 0.5 + 7 * 0.5 - 1);
    EXPECT_EQ(r.getDirection()[1], 11 + 5 * 0.5 + 8 * 0.5 - 2);
    EXPECT_EQ(r.getDirection()[2], 12 + 6 * 0.5 + 9 * 0.5 - 3);
}