// Ray Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "make_ppm.h"
#include "vec3.h"
#include "scene.h"
#include <iostream>

int main()
{
	scene* s = new scene(vec3(-2, -1, -1), 4, 2);
	s->debug_camera();
}
