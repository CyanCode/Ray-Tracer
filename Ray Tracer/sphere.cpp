#include "sphere.h"

vec3* Sphere::intersects(ray & r) {
	//vector from ray origin to sphere center
	vec3 oc = r.origin() - center;

	//A = ray origin
	//B = ray direction
	//C = sphere origin
	//R = sphere radius
	//t^2 * dot(B, B) + 2 * t * dot(B, A - c) + dot(A - C, A - C) - R^2 = 0
	//Solve for number of roots (t)
	//t > 0 = intersection

	float rayDirLength = r.direction().length();
	float ocLength = oc.length();

	float a = rayDirLength * rayDirLength;
	float b = 2 * dot(oc, r.direction());
	float c = ocLength * ocLength - radius * radius;
	float discriminant = b * b - 4 * a * c;

	if (discriminant > 0) { //Intersection
		float nt = (-b - sqrt(discriminant)) / (2.0 * a);
		vec3* normal = new vec3;
		*normal = unit_vector(r.point_at_param(nt) - r.origin());
		
		//Normalize [-1, 1] -> [0, 1]
		*normal += vec3(1, 1, 1);
		*normal *= 0.5;

		return normal;
	}

	return nullptr;
}
