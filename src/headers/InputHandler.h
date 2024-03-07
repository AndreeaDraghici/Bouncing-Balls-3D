// Pragma once is a non-standard but widely accepted directive
// that ensures this header file is included only once.
#pragma once

// Include guards prevent multiple inclusions of this header file
// in a single compilation file.
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

// Includes the Scene header to interact with the Scene class.
#include "Scene.h"

// The InputHandler class is responsible for managing keyboard inputs
// and passing these inputs to the scene it controls.
class InputHandler {
public:
    // Reference to the Scene object that InputHandler controls.
    // This design allows the InputHandler to modify the scene's state based on user inputs.
    Scene& scene;

    // The constructor of the InputHandler class.
    // @param s A reference to an instance of the Scene class that will be controlled by this handler.
    InputHandler(Scene& s) : scene(s) {}

    // Method to handle keyboard input (normal keys).
    // @param key The key pressed.
    // @param x The X position of the mouse cursor at the time the key was pressed.
    // @param y The Y position of the mouse cursor at the time the key was pressed.
    void handleKeyboardInput(unsigned char key, int x, int y);

    // Method to handle keyboard input (special keys, e.g., arrows).
    // @param key The special key pressed.
    // @param x The X position of the mouse cursor at the time the key was pressed.
    // @param y The Y position of the mouse cursor at the time the key was pressed.
    void handleSpecialInput(int key, int x, int y);
};

#endif // INPUT_HANDLER_H
