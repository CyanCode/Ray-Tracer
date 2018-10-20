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

	std::vector<SceneObject*>* sceneObjects;

	/*
	Create a scene that initializes a camera with the passed dimensions
	llc = lower left corner
	horiz = horizontal length
	vert = vertical length
	origin = origin of camera
	*/
	Scene(vec3 llc, int horiz, int vert, vec3 origin = vec3(0, 0, 0)) {
		lower_left_corner = llc;
		horizontal = vec3(horiz, 0, 0);
		vertical = vec3(0, vert, 0);
		this->origin = origin;

		sceneObjects = new std::vector<SceneObject*>;

		setBackgroundGradient(vec3(1, 1, 1), vec3(1, 1, 1));
	}

	/*
	 * Adds an arbitrary object to the scene
	 */
	void addSceneObject(SceneObject& so);

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

	/*
	Sets the background color gradient of the scene. By default 
	the scene is white.
	*/
	void setBackgroundGradient(vec3 startCol, vec3 endCol) {
		this->bgStartCol = startCol;
		this->bgEndCol = endCol;
	}
private:
	vec3 bgStartCol;
	vec3 bgEndCol;

	/*
	Gets the background color at the passed ray. Ray should fire 
	through pixel on screen into 3D space.
	*/
	vec3* getBackgroundColorAt(ray& r);
};

