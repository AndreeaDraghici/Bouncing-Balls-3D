// Pragma once is a non-standard but widely accepted directive
// that ensures this header file is included only once.
#pragma once

// Include guards prevent multiple inclusions of this header file
// in a single compilation file.
#ifndef BALL_H
#define BALL_H

// The Ball class is responsible for managing the state and graphical representation
// of a ball in a 3D environment.
class Ball {
public:
    // Variables for representing the ball's position in space.
    // These indicate the current location of the ball in XYZ coordinates.
    double ballPositionX, ballPositionY, ballPositionZ;

    // Variables for representing the dimensions of the "plane" on which the ball resides.
    // These can be used to determine the limits of the ball's movement.
    double widthPlaneOfBall, heightPlaneOfBall;

    // A boolean variable that indicates the direction of the ball's movement.
    // For example, it can indicate whether the ball is moving up or down.
    bool ballDirection;

    // The constructor for the Ball class.
    // Initializes the ball's position and the dimensions of the plane it resides on,
    // as well as the initial direction of movement.
    Ball() : ballPositionX(5.0), ballPositionY(5.0), ballPositionZ(5.0),
        widthPlaneOfBall(5.0), heightPlaneOfBall(8.5),
        ballDirection(true) {}


    // The draw method is responsible for drawing the ball in the OpenGL scene.
    // It uses the ball's coordinates to place it in the 3D scene.
    void draw();
};

#endif // BALL_H
