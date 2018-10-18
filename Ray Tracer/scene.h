#pragma once

#include <string>
#include <vector>
#include "vec3.h"
#include "ray.h"
#include "make_ppm.h"
#include "sphere.h"

class Scene
{
public:
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 origin;

	std::vector<Sphere>* spheres;

	/*
	Create a scene that initializes a camera with the passed dimensions
	llc = lower left corner
	horiz = horizontal length
	vert = vertical length
	*/
	Scene(vec3 llc, int horiz, int vert) { 
		lower_left_corner = llc; 
		horizontal = vec3(horiz, 0, 0);
		vertical = vec3(0, vert, 0);
		origin = vec3(0, 0, 0);

		spheres = new std::vector<Sphere>;
	}

	/*
	Create a scene that initializes a camera with the passed dimensions
	llc = lower left corner
	horiz = horizontal length
	vert = vertical length
	origin = origin of camera
	*/
	Scene(vec3 llc, int horiz, int vert, vec3 origin) {
		lower_left_corner = llc;
		horizontal = vec3(horiz, 0, 0);
		vertical = vec3(0, vert, 0);
		this->origin = origin;

		spheres = new std::vector<Sphere>;
	}

	/*
	Adds the passed sphere to the scene
	*/
	void addSphere(Sphere& sphere);

	/*
	Renders an image with the passed x and y pixel dimensions. 
	Writes the image to the file system with the passed path.
	*/
	void render(int px, int py, std::string file);

	/*
	Traces the path of the created camera by writing the
	current Y value as a pixel linearly interpolated between
	white and blue. This file is saved as "test.ppm"
	*/
	void debug_camera();
};

