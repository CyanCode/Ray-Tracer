#pragma once

#include "vec3.h"
#include "ray.h"
#include "scene_object.h"

class Sphere : public SceneObject {
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
	Checks whether the passed ray intersects this Sphere. 
	If it intersects, the normal for the hit is returned. 
	Otherwise, nullptr is returned.
	*/
	vec3* intersects(ray& r) override;
};

