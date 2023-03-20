/* File: main.cpp
**
** Description: Main file
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <iostream>

#include "Camera.hpp"
#include "Sphere.hpp"

int SIZE = 200;

int main()
{
    RayTracer::Camera cam;
    RayTracer::Sphere s(Maths::Vector<3>(0, 0, 20), 1);

    std::cout << "P3" << std::endl; // PPM header to set ASCII mode
    std::cout << SIZE << " " << SIZE << std::endl; // PPM header to set image size
    std::cout << "255" << std::endl; // PPM header to set max color value

    cam.setHorizontal(Maths::Vector<3>(10, 0, 0));
    cam.setVertical(Maths::Vector<3>(0, 10, 0));
    cam.setLowerLeftCorner(Maths::Vector<3>(0, -5, 10));

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            double u = double(i) / SIZE;
            double v = double(j) / SIZE;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hit(r)) {
                std::cout << "255 0 0" << std::endl;
            } else {
                std::cout << "0 0 0" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}