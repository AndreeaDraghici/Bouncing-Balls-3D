#include "Camera.h"
#include <GL/glut.h>

void Camera::applyView() {
    gluLookAt(-10 + cameraAngleX, 9 + cameraAngleY, -10 + cameraAngleZ,
        5, 5, 5, // Assuming the ball's initial position
        0, 1, 0);
}

void Camera::updateCameraPosition(int key) {
    // This method should be called whenever a special key (arrow key) is pressed
    switch (key) {
    case GLUT_KEY_UP:
        cameraAngleX -= 0.8f;
        if (cameraAngleX < cameraMinimumX) cameraAngleX = cameraMinimumX;
        break;
    case GLUT_KEY_DOWN:
        cameraAngleX += 0.8f;
        if (cameraAngleX > cameraMaximumX) cameraAngleX = cameraMaximumX;
        break;
    case GLUT_KEY_LEFT:
        cameraAngleY -= 0.8f;
        if (cameraAngleY < cameraMinumumY) cameraAngleY = cameraMinumumY;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngleY += 0.8f;
        if (cameraAngleY > cameraMaximumY) cameraAngleY = cameraMaximumY;
        break;
        // Add cases for zooming in and out if needed
    }
}