#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "debug.h"
#include "vec3.h"

/*
Write a PPM file to the disk at the path specified. Colors have 
a max length of 255.
Color array should be formatted in row first, column second order.
*/
void write_ppm(vec3** colors, int width, int height, std::string fileLoc);

/*
Writes a file named "test.ppm" to the file system at the application's 
current execution location. The image is filled with red.
*/
void test_ppm();