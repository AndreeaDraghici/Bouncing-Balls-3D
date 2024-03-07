#include "../headers/InputHandler.h"
#include <GL/glut.h>

// The handleKeyboardInput method manages input from the keyboard.
void InputHandler::handleKeyboardInput(unsigned char key, int x, int y) {
    // Switch based on the pressed key code.
    switch (key) {
    case 27: // Escape key
        exit(0); // Exits the program when ESC key is pressed.
        break;
    case 'a': // Move left
        scene.ball.ballPositionX -= 0.8; // Decrements the ball's position on the X axis.
        break;
    case 'd': // Move right
        scene.ball.ballPositionX += 0.8; // Increments the ball's position on the X axis.
        break;
    case 'w': // Move up
        scene.ball.ballPositionY += 0.8; // Increments the ball's position on the Y axis.
        break;
    case 's': // Move down
        scene.ball.ballPositionY -= 0.8; // Decrements the ball's position on the Y axis.
        break;
    case 'q': // Move forward
        scene.ball.ballPositionZ -= 0.8; // Decrements the ball's position on the Z axis.
        break;
    case 'e': // Move backward
        scene.ball.ballPositionZ += 0.8; // Increments the ball's position on the Z axis.
        break;
    }

    // Refreshes the scene to reflect the new positions of the ball.
    scene.update();
}

// The handleSpecialInput method manages input from special keys (e.g., arrow keys).
void InputHandler::handleSpecialInput(int key, int x, int y) {
    // Switch based on the pressed special key code.
    switch (key) {
    case GLUT_KEY_UP:
        // Decrease camera angle on the X axis.
        scene.camera.cameraAngleX -= 0.8f;
        // Ensure the angle does not go below the minimum limit.
        if (scene.camera.cameraAngleX < scene.camera.cameraMinimumX) {
            scene.camera.cameraAngleX = scene.camera.cameraMinimumX;
        }
        break;
    case GLUT_KEY_DOWN:
        // Increase camera angle on the X axis.
        scene.camera.cameraAngleX += 0.8f;
        // Ensure the angle does not exceed the maximum limit.
        if (scene.camera.cameraAngleX > scene.camera.cameraMaximumX) {
            scene.camera.cameraAngleX = scene.camera.cameraMaximumX;
        }
        break;
    case GLUT_KEY_LEFT:
        // Decrease camera angle on the Y axis.
        scene.camera.cameraAngleY -= 0.8f;
        // Ensure the angle does not go below the minimum limit.
        if (scene.camera.cameraAngleY < scene.camera.cameraMinumumY) {
            scene.camera.cameraAngleY = scene.camera.cameraMinumumY;
        }
        break;
    case GLUT_KEY_RIGHT:
        // Increase camera angle on the Y axis.
        scene.camera.cameraAngleY += 0.8f;
        // Ensure the angle does not exceed the maximum limit.
        if (scene.camera.cameraAngleY > scene.camera.cameraMaximumY) {
            scene.camera.cameraAngleY = scene.camera.cameraMaximumY;
        }
        break;
    default:
        break;
    }

    // Refreshes the scene to reflect the new angles of the camera.
    scene.update();
}
