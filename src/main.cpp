#include <iostream>

#include "base/array_3d.hpp"
#include "base/color.hpp"
#include "base/ray.hpp"

using namespace raytrc;

Color getRayColor(const Ray &ray) {
    Vector3d unitVec = ray.direction().unit();
    double ratio = 0.5 * (unitVec.y() + 1.0);
    return (1.0 - ratio) * Color{1.0, 1.0, 1.0} + ratio * Color{0.5, 0.7, 1.0};
}

int main() {

    // Image dimensions
    double ar = 16.0 / 9.0;
    int imgWidth = 400;
    // Compute image height and ensure is at least 1
    int imgHeight = static_cast<int>(imgWidth / ar);
    imgHeight = (imgHeight < 1) ? 1 : imgHeight;

    // Camera
    double focalLength = 1.0;
    double viewportHeight = 2.0;
    double viewportWidth = viewportHeight * static_cast<double>(imgWidth)/imgHeight;
    auto cameraCenter = Vector3d(0, 0, 0);

    // Viewport direction vectors
    Vector3d uVwprt = Vector3d(viewportWidth, 0, 0);     // Horizontal direction
    Vector3d vVwprt = Vector3d(0, -viewportHeight, 0);   // Vertical direction

    // Viewport delta vectors
    Vector3d uVwprtDelta = uVwprt / imgWidth;
    Vector3d vVwprtDelta = vVwprt / imgHeight;

    // Compute location of the origin pixel
    Vector3d originVwprt = cameraCenter - Vector3d(0, 0, focalLength) - uVwprt/2.0 - vVwprt/2.0;
    Vector3d originPxl = originVwprt + uVwprtDelta/2.0 + vVwprtDelta/2.0;

    // Render

    std::cout << "P3\n" << imgWidth << ' ' << imgHeight << "\n255\n";

    for (int j = 0; j < imgHeight; ++j) {
        std::clog << "\rScanlines remaining: " << (imgHeight - j) << ' ' << std::flush;

        for (int i = 0; i < imgWidth; ++i) {
            Vector3d pxl = originPxl + (i * uVwprtDelta) + (j * vVwprtDelta);
            Vector3d rayDirection = pxl - cameraCenter;
            Ray ray(cameraCenter, rayDirection);
            Color pxlColor = getRayColor(ray);
            std::cout << pxlColor;
        }
    }

    std::clog << "\rDone.                 \n";
}