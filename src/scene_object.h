//
// Created by Walker C on 10/18/2018.
//

#pragma once

#include "ray.h"

/*
 * Represents an object that can be added to a Scene instance
 */
class SceneObject {
public:
    virtual vec3* intersects(ray& r) = 0;
};