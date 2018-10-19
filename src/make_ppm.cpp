#include "make_ppm.h"

void write_ppm(vec3** colors, int width, int height, std::string fileLoc)
{
	std::ofstream outfile(fileLoc.c_str(), std::ofstream::trunc);

	if (LOG_LEVEL >= 1) {
		std::cout << "Writing " << width * height << " pixels to PPM at " << fileLoc << std::endl;
	}

	//Write header
	outfile << "P3\n" << width << " " << height << "\n255\n";

	//Write RGB color triplets
	for (int i = 0; i < width * height; i++) {
		vec3* c = colors[i];
		outfile << c->r() << " " << c->g() << " " << c->b() << "\n";
	}

	outfile.close();
}

void test_ppm()
{
	const int width = 100;
	const int height = 100;
	vec3** colors = new vec3*[width * height];

	for (int i = 0; i < width * height; i++) {
		colors[i] = new vec3(255, 0, 0);
	}

	write_ppm(colors, width, height, "test.ppm");
	delete[] colors;
}
