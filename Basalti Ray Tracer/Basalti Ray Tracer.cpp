#include <iostream>

#include "Tracer.h"
#include "Ray.h"
#include "Vec3.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

using namespace std;

void renderScene(const Sphere* sphere, const Cube* cube, const Cylinder* cylinder,
    const Vec3& cameraPos, const Vec3& lightPos, int width, int height) {
    if (sphere) {
        render(*sphere, cameraPos, lightPos, width, height);
    }
    else if (cube) {
        render(*cube, cameraPos, lightPos, width, height);
    }
    else if (cylinder) {
        render(*cylinder, cameraPos, lightPos, width, height);
    }
}

int main() {
    int width = 1920, height = 1080;

    Vec3 cameraPos(0, 0, -5);
    Vec3 lightPos(5, 4, -5);

    while (true) {
        cout << "Enter number of object to render:\n1, 2, 3 or 0 to exit\n\n";
        cout << "1. Sphere\n";
        cout << "2. Cube\n";
        cout << "3. Cylinder\n";
        cout << "\nEnter number: ";
        int num;
        cin >> num;

        Sphere* sphere = nullptr;
        Cube* cube = nullptr;
        Cylinder* cylinder = nullptr;

        switch (num) {
        case 1:
            sphere = new Sphere(Vec3(0, 0, 0), 1.0);
            break;
        case 2:
            cube = new Cube(Vec3(0, 0, 0), 1.0);
            break;
        case 3:
            cylinder = new Cylinder(Vec3(0, 0, 0), 0.75, 1.5);
            break;
        default:
            cout << "Exiting program.\n";
            return 0;
        }

        renderScene(sphere, cube, cylinder, cameraPos, lightPos, width, height);

        delete sphere;
        delete cube;
        delete cylinder;

        cout << "Rendering complete. Output saved to image.ppm.\n" << endl;
    }

    return 0;
}