# Ray-Tracer

A simple ray tracer written from scratch in C++ without the use of any third-party libraries. This ray tracer features the creation of a "scene" in 3D space that can render some abstract set of objects. Currently spheres and planes are supported.

Example code:

    Scene* scene = new Scene(vec3(-2, -1, -1), 4, 2);
    
    Sphere* sphere = new Sphere(vec3(0, 0, -1), 0.5);
    Sphere* s2 = new Sphere(vec3(1, 0.5, -1), 0.25);
    
    scene->setBackgroundGradient(vec3(0, 0, 255), vec3(255, 255, 255));
    scene->addSceneObject(*sphere);
    scene->addSceneObject(*s2);
    
    scene->render(400, 200, "out.ppm");

This renders a 400x200 image of two spheres in 3D space with a blue to white gradient background. The image is saved as "out.ppm" which is a simple image file type.

This ray tracer was created after reading Peter Shirley&#39;s: [Ray Tracing in One Weekend](http://in1weekend.blogspot.com/2016/01/ray-tracing-in-one-weekend.html "Ray Tracing in One Weekend"), though the code is entirely original.
