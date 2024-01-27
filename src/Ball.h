// Pragma once este o directivă non-standard, dar larg acceptată,
// care asigură includerea unică a acestui fișier header.
#pragma once

// Include guards previn includerea multiplă a acestui fișier header
// într-un singur fișier de compilare.
#ifndef BALL_H
#define BALL_H

// Clasa Ball este responsabilă pentru gestionarea stării și a reprezentării grafice
// a unei bile într-un mediu 3D.
class Ball {
public:
    // Variabile pentru reprezentarea poziției bilei în spațiu.
    // Acestea indică locația curentă a bilei în coordonatele XYZ.
    double ballPositionX, ballPositionY, ballPositionZ;

    // Variabile pentru reprezentarea dimensiunii "planului" pe care se află bila.
    // Acestea pot fi folosite pentru a determina limitele mișcării bilei.
    double widthPlaneOfBall, heightPlaneOfBall;

    // Variabilă de tip bool care indică direcția de mișcare a bilei.
    // De exemplu, poate indica dacă bila se mișcă în sus sau în jos.
    bool ballDirection;

    // Constructorul clasei Ball.
    // Inițializează poziția bilei și dimensiunile planului pe care se află, 
    // precum și direcția inițială a mișcării.
    Ball() : ballPositionX(5.0), ballPositionY(5.0), ballPositionZ(5.0),
        widthPlaneOfBall(5.0), heightPlaneOfBall(8.5),
        ballDirection(true) {}


    // Metoda draw este responsabilă pentru desenarea bilei în scena OpenGL.
    // Aceasta utilizează coordonatele bilei pentru a o plasa în scena 3D.
    void draw();
};

#endif // BALL_H