#include <GL/glut.h>
#include "Scene.h"
#include "InputHandler.h"
#include "WindowManager.h"

// Crearea obiectelor pentru scena, managerul ferestrei și handlerul de input.
Scene scene;
WindowManager windowManager(900, 600);
InputHandler inputHandler(scene);

// Funcția de callback pentru afișarea scenei.
// Aceasta este chemată de fiecare dată când GLUT decide că scena trebuie redesenată.
void displayCallback() {
    scene.display(); // Afișează elementele scenei.
}

// Funcția de callback pentru redimensionarea ferestrei.
// Aceasta este apelată de GLUT atunci când fereastra este redimensionată.
void reshapeCallback(int width, int height) {
    scene.reshape(width, height); // Ajustează scena în funcție de noile dimensiuni ale ferestrei.
}

// Funcția de callback pentru actualizarea stării bilei.
// Aceasta este apelată în mod repetat de GLUT.
void bouncingBallsCallback() {
    scene.bouncing_balls(); // Actualizează logica bilei care sare.
}

// Funcția de callback pentru inputul de la tastatură.
// Aceasta este apelată de GLUT atunci când o tastă este apăsată.
void keyboardCallback(unsigned char key, int x, int y) {
    inputHandler.handleKeyboardInput(key, x, y); // Gestionează inputul de la tastatură.
}

// Funcția de callback pentru tastele speciale (săgeți, funcții, etc.).
// Aceasta este apelată de GLUT atunci când o tastă specială este apăsată.
void specialInputCallback(int key, int x, int y) {
    inputHandler.handleSpecialInput(key, x, y); // Gestionează inputul de la tastele speciale.
}

// Funcția principală: GLUT rulează ca o aplicație de consolă începând de la main().
int main(int argc, char** argv) {
    // Inițializează GLUT.
    glutInit(&argc, argv);

    // Setează modul de afișare (double buffering, RGBA color, depth test).
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    // Specifică dimensiunea inițială a ferestrei.
    glutInitWindowSize(windowManager.width, windowManager.height);
    // Poziționează fereastra la coordonatele (100, 100) pe ecran.
    glutInitWindowPosition(100, 100);

    // Creează fereastra cu titlul specificat.
    glutCreateWindow("Bile Saltarete - OpenGL");

    // Inițializează contextul OpenGL.
    scene.initGL();

    // Setează funcțiile de callback pentru diferitele evenimente.
    glutDisplayFunc(displayCallback); // Pentru afișarea scenei.
    glutIdleFunc(bouncingBallsCallback); // Pentru actualizarea continuă a scenei.
    glutReshapeFunc(reshapeCallback); // Pentru redimensionarea ferestrei.
    glutKeyboardFunc(keyboardCallback); // Pentru inputul de la tastatură.
    glutSpecialFunc(specialInputCallback); // Pentru tastele speciale.

    // Intră în bucla principală GLUT și începe procesarea evenimentelor.
    glutMainLoop();

    return 0; 
}
