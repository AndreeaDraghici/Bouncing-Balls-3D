#pragma once

#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:

    /* reprezinta unghiurile camerei intr-un sistem de coordonate 3D */
    float cameraAngleX, cameraAngleY, cameraAngleZ;

    // aplicarea unor limite minimale – constringeri ale miscarii camerei
    float cameraMinimumX, cameraMaximumX, cameraMinumumY, cameraMaximumY, cameraMinimumZ, cameraMaximumZ;

    Camera() : cameraAngleX(65.0f), cameraAngleY(10.5f), cameraAngleZ(30.0f),
        cameraMinimumX(-10.0f), cameraMaximumX(10.0f), cameraMinumumY(0.0f), cameraMaximumY(10.0f),
        cameraMinimumZ(-10.0f), cameraMaximumZ(10.0f) {}

    void applyView();
    void updateCameraPosition(int key);
};

#endif
