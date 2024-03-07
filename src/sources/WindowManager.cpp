#include "../headers/WindowManager.h"
#include <GL/glut.h>

/// This method is called when the display window is resized.
// Its purpose is to adjust the projection of displayed objects' proportions to avoid their distortion when the window size changes.
void WindowManager::reshapeWindow(int w, int h) {
    // Set the new display area of the window.
    // This is achieved by defining a new viewport that covers
    // the entire window, even when the window dimensions change.
    // The parameters for glViewport are (x, y, width, height),
    // where x and y define the bottom-left corner of the new viewport.
    glViewport(0, 0, w, h);

    // Change the current matrix to the projection matrix.
    // This is used to define how objects are projected into 2D space.
    glMatrixMode(GL_PROJECTION);

    // Reset the projection matrix to the identity matrix.
    // This is like "erasing" any previous transformation applied to this matrix.
    glLoadIdentity();

    // Define the perspective projection for our scene.
    // gluPerspective requires (field of view angle in degrees, aspect ratio, near clip, far clip).
    // The aspect ratio is calculated as the ratio between the window's width and height
    // to maintain the correct proportions of the displayed objects.
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
}
