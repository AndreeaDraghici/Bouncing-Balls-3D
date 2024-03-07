#include <GL/glut.h>
#include "../src/headers/Scene.h"
#include "../src/headers/InputHandler.h"
#include "../src/headers/WindowManager.h"

// Creating objects for the scene, window manager, and input handler.
Scene scene;
WindowManager windowManager(900, 600);
InputHandler inputHandler(scene);

// Callback function for scene display.
// This is called whenever GLUT determines that the scene needs to be redrawn.
void displayCallback() {
    scene.display(); // Displays the elements of the scene.
}

// Callback function for window resizing.
// This is called by GLUT when the window is resized.
void reshapeCallback(int width, int height) {
    scene.reshape(width, height); // Adjusts the scene based on the new window dimensions.
}

// Callback function for updating the state of the balls.
// This is called repeatedly by GLUT.
void bouncingBallsCallback() {
    scene.bouncing_balls(); // Updates the logic for the bouncing ball.
}

// Callback function for keyboard input.
// This is called by GLUT when a key is pressed.
void keyboardCallback(unsigned char key, int x, int y) {
    inputHandler.handleKeyboardInput(key, x, y); // Handles keyboard input.
}

// Callback function for special keys (arrows, function keys, etc.).
// This is called by GLUT when a special key is pressed.
void specialInputCallback(int key, int x, int y) {
    inputHandler.handleSpecialInput(key, x, y); // Handles input from special keys.
}

// Main function: GLUT runs as a console application starting from main().
int main(int argc, char** argv) {
    // Initializes GLUT.
    glutInit(&argc, argv);

    // Sets the display mode (double buffering, RGBA color, depth test).
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    // Specifies the initial size of the window.
    glutInitWindowSize(windowManager.width, windowManager.height);
    // Positions the window at the coordinates (100, 100) on the screen.
    glutInitWindowPosition(100, 100);

    // Creates the window with the specified title.
    glutCreateWindow("Bouncing Balls - OpenGL - Draghici Andreea");

    // Initializes the OpenGL context.
    scene.initGL();

    // Sets callback functions for different events.
    glutDisplayFunc(displayCallback); // For displaying the scene.
    glutIdleFunc(bouncingBallsCallback); // For continuous scene update.
    glutReshapeFunc(reshapeCallback); // For window resizing.
    glutKeyboardFunc(keyboardCallback); // For keyboard input.
    glutSpecialFunc(specialInputCallback); // For special keys.

    // Enters the GLUT main loop and starts processing events.
    glutMainLoop();

    return 0;
}
