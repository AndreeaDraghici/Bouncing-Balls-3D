// Pragma once is a non-standard but widely accepted directive
// that ensures this header file is included only once.
#pragma once

// Include guards prevent multiple inclusions of this header file
// in a single compilation file.
#ifndef CAMERA_H
#define CAMERA_H

// The Camera class is responsible for managing the position and orientation
// of the camera in a 3D environment.
class Camera {
public:
    // Variables for representing the camera's angles in a 3D coordinate system.
    // These angles determine the direction in which the camera is facing.
    float cameraAngleX, cameraAngleY, cameraAngleZ;

    // Variables for applying minimum and maximum movement limits of the camera.
    // These limits prevent the camera from moving outside certain areas.
    float cameraMinimumX, cameraMaximumX, cameraMinumumY, cameraMaximumY, cameraMinimumZ, cameraMaximumZ;

    // The constructor of the Camera class.
    // Initializes the camera's angles and movement limits to default values.
    Camera() : cameraAngleX(65.0f), cameraAngleY(10.5f), cameraAngleZ(30.0f),
        cameraMinimumX(-10.0f), cameraMaximumX(10.0f), cameraMinumumY(0.0f), cameraMaximumY(10.0f),
        cameraMinimumZ(-10.0f), cameraMaximumZ(10.0f) {}
};

#endif // CAMERA_H
