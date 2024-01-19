#include <GL/glut.h>
#include "Scene.h"
#include "InputHandler.h"
#include "WindowManager.h"

Scene scene;
WindowManager windowManager(900, 600);
InputHandler inputHandler(scene);

void displayCallback() {
    scene.display();
}

void reshapeCallback(int width, int height) {
    scene.reshape(width, height);
}

void bouncingBallsCallback() {
    scene.bouncing_balls();
}

void keyboardCallback(unsigned char key, int x, int y) {
    inputHandler.handleKeyboardInput(key, x, y);
}

void specialInputCallback(int key, int x, int y) {
    inputHandler.handleSpecialInput(key, x, y);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {

    // initializare
    glutInit(&argc, argv);

    // setarea modului pentru afisare
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    // specificare dimensiune fereastra
    glutInitWindowSize(windowManager.width, windowManager.height);
    glutInitWindowPosition(100, 100);

    // creare fereastra cu numele specificat
    glutCreateWindow("Bile Saltarete - OpenGL");

    scene.initGL();


    // apelare functii 
    glutDisplayFunc(displayCallback);
    glutIdleFunc(bouncingBallsCallback);
    glutReshapeFunc(reshapeCallback);
    glutKeyboardFunc(keyboardCallback);
    glutSpecialFunc(specialInputCallback);


    // rulare program
    glutMainLoop();
    return 0;
}
