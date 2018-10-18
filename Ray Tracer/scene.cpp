#include "scene.h"

void Scene::addSphere(Sphere & sphere)
{
	spheres->push_back(sphere);
}

void Scene::render(int px, int py, std::string file)
{
	//Final colors array
	vec3** colors = new vec3*[px * py];
	int cIdx = 0;

	//Traverse starting from lower left hand corner
	for (int j = py - 1; j >= 0; j--) {
		for (int i = 0; i < px; i++) {
			//Convert pixel location to UV coordinates
			float u = float(i) / float(px);
			float v = float(j) / float(py);

			//Create ray through pixel
			ray r = ray(origin, lower_left_corner + u * horizontal + v * vertical);

			vec3* color = new vec3(255, 255, 255);

			//Determine if ray intersected any spheres
			for (int s = 0; s < spheres->size(); s++) {
				if (spheres->at(s).intersects(r)) {
					color = new vec3(255, 0, 0);

					break;
				}
			}

			colors[cIdx] = color;
			cIdx++;
		}
	}

	write_ppm(colors, px, py, file);

	delete[] colors;
}

void Scene::debug_camera()
{
	//Pixel dimensions
	const int nx = 200;
	const int ny = 100;

	//Final colors array
	vec3** colors = new vec3*[nx * ny];
	int cIdx = 0;

	//Traverse starting from lower left hand corner
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			//Convert pixel location to UV coordinates
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			//Create ray through pixel
			ray r = ray(origin, lower_left_corner + u * horizontal + v * vertical);

			//Calculate debug color at the pixel (pitch of Y axis)
			vec3 unit_dir = unit_vector(r.direction()); //Convert to unit vector [-1, 1]
			float t = 0.5 * (unit_dir.y() + 1); //Scale to [0, 1]

			//Determine color through linear interpolation
			vec3 blue = vec3(0, 0, 1);
			vec3 white = vec3(1, 1, 1);
			vec3 col = (1 - t) * white + t * blue;
			
			col *= 255;
			colors[cIdx] = &col;
			cIdx++;
		}
	}
	
	write_ppm(colors, nx, ny, "test.ppm");
	
	delete[] colors;
}
