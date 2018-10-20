#include "make_ppm.h"
#include "scene.h"

int main()
{
    Scene* scene = new Scene(vec3(-2, -1, -1), 4, 2);
    Sphere* sphere = new Sphere(vec3(0, 0, -1), 0.5);
    //Sphere* s2 = new Sphere(vec3(1, 0.5, -1), 0.25);

    scene->setBackgroundGradient(vec3(0, 0, 255), vec3(255, 255, 255));
    scene->addSceneObject(*sphere);
    //scene->addSceneObject(*s2);
    scene->render(400, 200, "out.ppm");
}
