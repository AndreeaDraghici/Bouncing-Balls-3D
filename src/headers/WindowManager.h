// Pragma once este o directivă non-standard, dar larg acceptată,
// care asigură includerea unică a conținutului fișierului header.
#pragma once

// Include guards previn includerea multiplă a aceluiași header
// într-un singur fișier de compilare.
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

// Clasa WindowManager este responsabilă pentru gestionarea ferestrei grafice.
// Acesta oferă funcționalități pentru setarea dimensiunii ferestrei și
// reconfigurarea acesteia atunci când este redimensionată.
class WindowManager {
public:

    // Variabile membru pentru a stoca dimensiunile actuale ale ferestrei grafice.
    // Acestea sunt inițializate cu valori implicite de 900x600.
    int width, height;

    // Constructorul clasei WindowManager, care permite inițializarea
    // dimensiunilor ferestrei cu valori specificate.
    // @param w Lățimea ferestrei.
    // @param h Înălțimea ferestrei.
    WindowManager(int w, int h) : width(w), height(h) {}


    // Metoda reshapeWindow este chemată pentru a actualiza viewport-ul OpenGL
    // atunci când fereastra este redimensionată.
    // @param width Noua lățime a ferestrei.
    // @param height Noua înălțime a ferestrei.
    void reshapeWindow(int width, int height);
};

#endif
