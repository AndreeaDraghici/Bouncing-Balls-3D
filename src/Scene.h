#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Ball.h"

class Scene {
public:
    Camera camera;
    Ball ball;

    void initGL();
    void display();
    void reshape(int width, int height);
    void update();
    void bouncing_balls();
    static void timer(int v);
};

#endif
