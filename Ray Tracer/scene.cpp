#include "scene.h"

void scene::debug_camera()
{
	//Pixel dimensions
	const int nx = 200;
	const int ny = 100;

	//Final colors array
	color* colors[nx * ny];
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
			
			color* c = new color;
			c->r = int(col.r() * 255);
			c->g = int(col.g() * 255);
			c->b = int(col.b() * 255);

			colors[cIdx] = c;

			cIdx++;
		}
	}
	
	write_ppm(colors, nx, ny, "test.ppm");
}
