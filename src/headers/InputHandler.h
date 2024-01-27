// Pragma once este o directivă non-standard, dar larg acceptată,
// care asigură includerea unică a acestui fișier header.
#pragma once

// Include guards previn includerea multiplă a acestui fișier header
// într-un singur fișier de compilare.
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

// Include header-ul Scene pentru a putea interacționa cu clasa Scene.
#include "Scene.h"

// Clasa InputHandler este responsabilă pentru gestionarea inputurilor de la tastatură
// și transmite aceste inputuri către scena pe care o controlează.
class InputHandler {
public:
    // Referință la obiectul Scene pe care InputHandler îl controlează.
    // Acest design permite ca InputHandler să modifice starea scenei în funcție de inputurile utilizatorului.
    Scene& scene;

    // Constructorul clasei InputHandler.
    // @param s O referință la o instanță a clasei Scene care va fi controlată de acest handler.
    InputHandler(Scene& s) : scene(s) {}

    // Metoda pentru a gestiona inputul de la tastatură (taste normale).
    // @param key Tasta apăsată.
    // @param x Poziția X a cursorului mouse-ului la momentul apăsării tastei.
    // @param y Poziția Y a cursorului mouse-ului la momentul apăsării tastei.
    void handleKeyboardInput(unsigned char key, int x, int y);

    // Metoda pentru a gestiona inputul de la tastatură (taste speciale, ex: săgeți).
    // @param key Tasta specială apăsată.
    // @param x Poziția X a cursorului mouse-ului la momentul apăsării tastei.
    // @param y Poziția Y a cursorului mouse-ului la momentul apăsării tastei.
    void handleSpecialInput(int key, int x, int y);
};

#endif // INPUT_HANDLER_H