// Pragma once is a non-standard but widely accepted directive
// that ensures this header file's content is included only once.
#pragma once

// Include guards prevent multiple inclusions of this header file
// in a single compilation file.
#ifndef SCENE_H
#define SCENE_H

// Include headers for the Camera and Ball classes.
#include "Camera.h"
#include "Ball.h"

// The Scene class represents the main scene for our OpenGL application.
// It includes objects for the camera and ball, and methods to manage the scene.
class Scene {
public:
    // Camera object to manage the positioning and orientation of the camera in the 3D scene.
    Camera camera;

    // Ball object representing the ball that moves within the scene.
    Ball ball;

    // The initGL method is used to initialize the state and settings of OpenGL.
    void initGL();

    // The display method is responsible for drawing and rendering the scene.
    void display();

    // This function draws balls in the 3D scene.
    void drawBalls();

    // The function creates two trees in the scene using generateTree, which is a function that draws a tree using cylinders for the trunk and spheres for the crown. 
    void drawTrees();

    // Function for drawing the ground plane.
    void drawPlanOfFloor();

    // Function for drawing walls.
    void drawWalls();

    // The reshape method is called when the display window is resized.
    // It adjusts the viewport and projection according to the new dimensions.
    void reshape(int width, int height);

    // The update method is used to update the state of the scene,
    // for example, the positions of objects, before rendering.
    void update();

    // The bouncing_balls method contains specific logic for the ball's movement in the scene.
    void bouncing_balls();

    // The static timer method is a callback for timer functionality in GLUT.
    // It is used to periodically update the scene.
    static void timer(int v);

    // Method used to visually generate a tree in a scene.
    void generateTree(double trunkHeight, double crownHeight, double radius);
};

#endif // SCENE_H
