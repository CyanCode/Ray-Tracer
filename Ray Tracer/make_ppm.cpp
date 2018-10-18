#include "pch.h"
#include "make_ppm.h"

void write_ppm(color** colors, int width, int height, std::string fileLoc)
{
	std::ofstream outfile(fileLoc.c_str(), std::ofstream::trunc);

	if (LOG_LEVEL >= 1) {
		std::cout << "Writing " << width * height << " pixels to PPM at " << fileLoc << std::endl;
	}

	//Write header
	outfile << "P3\n" << width << " " << height << "\n255\n";

	//Write RGB color triplets
	for (int i = 0; i < width * height; i++) {
		color* c = colors[i];
		outfile << c->r << " " << c->g << " " << c->b << "\n";
	}

	outfile.close();
}

void test_ppm()
{
	const int width = 100;
	const int height = 100;
	color* colors[width * height];

	for (int i = 0; i < width * height; i++) {
		color* c = new color;
		c->r = 255;
		c->g = 0;
		c->b = 0;

		colors[i] = c;
	}

	write_ppm(colors, width, height, "test.ppm");
}
