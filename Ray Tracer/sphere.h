#pragma once

#include "vec3.h"
#include "ray.h"

class Sphere
{
public:
	vec3 center;
	float radius;

	/*
	Create a sphere at the passed origin with the passed radius
	*/
	Sphere(vec3 center, float radius) {
		this->center = center;
		this->radius = radius;
	}

	/*
	Checks whether the passed ray intersects this Sphere
	*/
	bool intersects(ray& r);
};

