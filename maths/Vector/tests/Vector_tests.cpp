/* File: Vector_tests.cpp
**
** Description: [DESCRIPTION]
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <gtest/gtest.h>

#include "Vector.hpp"

TEST(Vector, DefaultConstructor)
{
    Maths::Vector<3> v;

    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
    EXPECT_EQ(v[2], 0);
}

TEST(Vector, SpeConstructor)
{
    Maths::Vector<3> v(1, 2, 3);

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(Vector, CopyConstructor)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(v1);

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}

TEST(Vector, MoveConstructor)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(std::move(v1));

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}

TEST(Vector, CopyAssignment)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2;

    v2 = v1;

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}

TEST(Vector, MoveAssignment)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2;

    v2 = std::move(v1);

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}

TEST(Vector, OperatorSquareBracket)
{
    Maths::Vector<3> v(1, 2, 3);

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(Vector, OperatorPlus)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);
    Maths::Vector<3> v3;

    v3 = v1 + v2;

    EXPECT_EQ(v3[0], 5);
    EXPECT_EQ(v3[1], 7);
    EXPECT_EQ(v3[2], 9);
}

TEST(Vector, OperatorPlusEqual)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);

    v1 += v2;

    EXPECT_EQ(v1[0], 5);
    EXPECT_EQ(v1[1], 7);
    EXPECT_EQ(v1[2], 9);
}

TEST(Vector, OperatorMinus)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);
    Maths::Vector<3> v3;

    v3 = v1 - v2;

    EXPECT_EQ(v3[0], -3);
    EXPECT_EQ(v3[1], -3);
    EXPECT_EQ(v3[2], -3);
}

TEST(Vector, OperatorMinusEqual)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);

    v1 -= v2;

    EXPECT_EQ(v1[0], -3);
    EXPECT_EQ(v1[1], -3);
    EXPECT_EQ(v1[2], -3);
}

TEST(Vector, OperatorMultiply)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);
    Maths::Vector<3> v3;

    v3 = v1 * v2;

    EXPECT_EQ(v3[0], 4);
    EXPECT_EQ(v3[1], 10);
    EXPECT_EQ(v3[2], 18);
}

TEST(Vector, OperatorMultiplyEqual)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);

    v1 *= v2;

    EXPECT_EQ(v1[0], 4);
    EXPECT_EQ(v1[1], 10);
    EXPECT_EQ(v1[2], 18);
}

TEST(Vector, OperatorDivide)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);
    Maths::Vector<3> v3;

    v3 = v1 / v2;

    EXPECT_EQ(v3[0], 0.25);
    EXPECT_EQ(v3[1], 0.4);
    EXPECT_EQ(v3[2], 0.5);
}

TEST(Vector, OperatorDivideEqual)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);

    v1 /= v2;

    EXPECT_EQ(v1[0], 0.25);
    EXPECT_EQ(v1[1], 0.4);
    EXPECT_EQ(v1[2], 0.5);
}

TEST(Vector, OperatorEqual)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(1, 2, 3);

    EXPECT_TRUE(v1 == v2);
}

TEST(Vector, OperatorNotEqual)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2(4, 5, 6);

    EXPECT_TRUE(v1 != v2);
}

TEST(Vector, OperatorMultiplyDouble)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2;

    v2 = v1 * 2;

    EXPECT_EQ(v2[0], 2);
    EXPECT_EQ(v2[1], 4);
    EXPECT_EQ(v2[2], 6);
}

TEST(Vector, OperatorMultiplyEqualDouble)
{
    Maths::Vector<3> v1(1, 2, 3);

    v1 *= 2;

    EXPECT_EQ(v1[0], 2);
    EXPECT_EQ(v1[1], 4);
    EXPECT_EQ(v1[2], 6);
}

TEST(Vector, OperatorDivideDouble)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<3> v2;

    v2 = v1 / 2;

    EXPECT_EQ(v2[0], 0.5);
    EXPECT_EQ(v2[1], 1);
    EXPECT_EQ(v2[2], 1.5);
}

TEST(Vector, OperatorDivideEqualDouble)
{
    Maths::Vector<3> v1(1, 2, 3);

    v1 /= 2;

    EXPECT_EQ(v1[0], 0.5);
    EXPECT_EQ(v1[1], 1);
    EXPECT_EQ(v1[2], 1.5);
}

TEST(Vector, Lenght)
{
    Maths::Vector<3> v1(1, 2, 3);
    Maths::Vector<6> v2(1, 2, 3, 4, 5, 6);

    EXPECT_EQ(v1.length(), 3);
    EXPECT_EQ(v2.length(), 6);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}