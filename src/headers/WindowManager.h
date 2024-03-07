// Pragma once is a non-standard but widely accepted directive
// that ensures the unique inclusion of this header file's content.
#pragma once

// Include guards prevent the multiple inclusion of the same header
// in a single compilation file.
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

// The WindowManager class is responsible for managing the graphical window.
// It provides functionalities for setting the window size and
// reconfiguring it when resized.
class WindowManager {
public:

    // Member variables to store the current dimensions of the graphical window.
    // These are initialized with default values of 900x600.
    int width, height;

    // Constructor for the WindowManager class, which allows the initialization
    // of the window's dimensions with specified values.
    // @param w The width of the window.
    // @param h The height of the window.
    WindowManager(int w, int h) : width(w), height(h) {}


    // The reshapeWindow method is called to update the OpenGL viewport
    // when the window is resized.
    // @param width The new width of the window.
    // @param height The new height of the window.
    void reshapeWindow(int width, int height);
};

#endif // WINDOW_MANAGER_H
