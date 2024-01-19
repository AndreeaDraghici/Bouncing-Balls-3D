#pragma once
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

class WindowManager {
public:
    /* variabile utilizate pentru stocarea dimensiunii ferestrei grafice */
    int width = 900 , height = 600;

    WindowManager(int w, int h) : width(w), height(h) {}

    void reshapeWindow(int width, int height);
};

#endif
