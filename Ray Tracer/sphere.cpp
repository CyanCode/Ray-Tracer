#include "sphere.h"

bool Sphere::intersects(ray & r) {
	//vector from ray origin to sphere center
	vec3 oc = r.origin() - center;

	//A = ray origin
	//B = ray direction
	//C = sphere origin
	//R = sphere radius
	//t^2 * dot(B, B) + 2 * t * dot(B, A - c) + dot(A - C, A - C) - R^2 = 0
	//Solve for number of roots (t)
	//t > 0 = intersection

	//float a = dot(r.direction(), r.direction());
	float rayDirLength = r.direction().length();
	float ocLength = oc.length();

	float a = rayDirLength * rayDirLength;
	float b = 2 * dot(oc, r.direction());
	float c = ocLength * ocLength - radius * radius;
	float discriminant = b * b - 4 * a * c;

	return discriminant > 0;
}
