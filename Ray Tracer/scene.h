#pragma once

#include "vec3.h"
#include "ray.h"
#include "make_ppm.h"

class scene
{
public:
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 origin;

	/*
	Create a scene that initializes a camera with the passed dimensions
	llc = lower left corner
	horiz = horizontal length
	vert = vertical length
	*/
	scene(vec3 llc, int horiz, int vert) { 
		lower_left_corner = llc; 
		horizontal = vec3(horiz, 0, 0);
		vertical = vec3(0, vert, 0);
		origin = vec3(0, 0, 0);
	}

	/*
	Create a scene that initializes a camera with the passed dimensions
	llc = lower left corner
	horiz = horizontal length
	vert = vertical length
	origin = origin of camera
	*/
	scene(vec3 llc, int horiz, int vert, vec3 origin) {
		lower_left_corner = llc;
		horizontal = vec3(horiz, 0, 0);
		vertical = vec3(0, vert, 0);
		this->origin = origin;
	}

	/*
	Traces the path of the created camera by writing the
	current Y value as a pixel linearly interpolated between
	white and blue. This file is saved as "test.ppm"
	*/
	void debug_camera();
};

