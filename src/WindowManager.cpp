#include "WindowManager.h"
#include <GL/glut.h>


/* apelata cand fereastra de afisare este redimensionata
   scop pentru a adapta proiectia proportiilor obiectului afisat pentru a nu se deforma in cazul schimbarii dimensiunii ferestrei */
void WindowManager::reshapeWindow(int w, int h) {
    // specificam noua zona de afisare a ferestrei, aceasta fiind impartita in regiuni de coordonate
    glViewport(0, 0, w, h);

    // se seteaza matricea de proiectie
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // se specifica campul vizual al camerei in grade, raportul de aspect al ferestrei, 
    // precum si distanta dintre planul apropiat si cel indepartat
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
}
