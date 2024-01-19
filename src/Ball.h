#pragma once

#ifndef BALL_H
#define BALL_H

class Ball {
public:
    /* reprezinta pozitia unei bile în spatiu */
    double ballPositionX, ballPositionY, ballPositionZ;
    double widthPlaneOfBall, heightPlaneOfBall;

    /* este o variabila de tip bool care indica directia de miscare a formei geometrice */
    bool ballDirection;

    Ball() : ballPositionX(5.0), ballPositionY(5.0), ballPositionZ(5.0),
        widthPlaneOfBall(5.0), heightPlaneOfBall(8.5),
        ballDirection(true) {}

    void updatePosition();
    void draw();
};

#endif
