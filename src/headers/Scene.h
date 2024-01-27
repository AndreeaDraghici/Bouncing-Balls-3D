// Pragma once este o directivă non-standard, dar larg acceptată,
// care asigură includerea unică a conținutului acestui fișier header.
#pragma once

// Include guards previn includerea multiplă a acestui fișier header
// într-un singur fișier de compilare.
#ifndef SCENE_H
#define SCENE_H

// Includem header-ele pentru clasele Camera și Ball.
#include "Camera.h"
#include "Ball.h"

// Clasa Scene reprezintă scena principală pentru aplicația noastră OpenGL.
// Ea include obiecte pentru camera și bila, și metode pentru a gestiona scena.
class Scene {
public:
    // Obiect Camera pentru a gestiona poziționarea și orientarea camerei în scena 3D.
    Camera camera;

    // Obiect Ball care reprezintă bila care se deplasează în cadrul scenei.
    Ball ball;

    // Metoda initGL este folosită pentru a inițializa starea și setările OpenGL.
    void initGL();

    // Metoda display este responsabilă pentru a desena și reda scena.
    void display();

    // Această funcție desenează bile în scena 3D.
    void drawBalls();

    // Funcția creează doi copaci în scena folosind generateTree, care este o funcție ce desenează un copac folosind cilindri pentru trunchi și sfere pentru coroană. 
    void drawTrees();

    // Funcție pentru desenat planul solului.
    void drawPlanOfFloor();

    // Funcție pentur desenrarea pereților. 
    void drawWalls();

    // Metoda reshape este apelată atunci când fereastra de afișare este redimensionată.
    // Ajustează viewport-ul și proiecția în funcție de noile dimensiuni.
    void reshape(int width, int height);

    // Metoda update este utilizată pentru a actualiza starea scenei,
    // de exemplu, pozițiile obiectelor, înainte de redare.
    void update();

    // Metoda bouncing_balls conține logica specifică pentru mișcarea bilei în scena.
    void bouncing_balls();

    // Metoda statică timer este un callback pentru funcționalitatea de timer în GLUT.
    // Aceasta este utilizată pentru a actualiza scena periodic.
    static void timer(int v);

    //Metoda folosită pentru a genera vizual un copac într-o scenă 
    void generateTree(double trunkHeight, double crownHeight, double radius);
};

#endif // SCENE_H