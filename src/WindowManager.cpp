#include "WindowManager.h"
#include <GL/glut.h>


/// Această metodă este apelată când fereastra de afișare este redimensionată.
// Scopul ei este de a adapta proiecția proporțiilor obiectelor afișate pentru a evita deformarea acestora în cazul schimbării dimensiunii ferestrei.
void WindowManager::reshapeWindow(int w, int h) {

     // Setăm noua zonă de afișare a ferestrei.
     // Acest lucru este realizat prin definirea unui nou viewport care acoperă
     // întreaga fereastră, chiar și atunci când dimensiunile ferestrei se schimbă.
     // Parametrii glViewport sunt (x, y, width, height),
     // unde x și y definesc colțul stânga-jos al noului viewport.
    glViewport(0, 0, w, h);

    // Schimbăm matricea curentă în matricea de proiecție.
    // Aceasta este folosită pentru a defini cum obiectele sunt proiectate în spațiul 2D.
    glMatrixMode(GL_PROJECTION);

    // Resetăm matricea de proiecție la matricea identitate.
    // Aceasta este ca și cum am "șterge" orice transformare anterioară aplicată acestei matrice.
    glLoadIdentity();

     // Definim proiecția perspectivă pentru scena noastră.
     // gluPerspective necesită (unghiul de vedere în grade, aspect ratio, near clip, far clip).
     // Aspect ratio-ul este calculat ca raportul dintre lățime și înălțimea ferestrei
     // pentru a menține proporțiile corecte ale obiectelor afișate.
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
}
