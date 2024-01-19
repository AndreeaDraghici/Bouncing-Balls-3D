#pragma once

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Scene.h"

class InputHandler {
public:
    Scene& scene;

    InputHandler(Scene& s) : scene(s) {}

    void handleKeyboardInput(unsigned char key, int x, int y);
    void handleSpecialInput(int key, int x, int y);
};

#endif
