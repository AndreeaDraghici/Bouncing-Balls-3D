#include "Ball.h"
#include <GL/glut.h>

// Metoda draw este responsabilă pentru desenarea bilei.
void Ball::draw() {
    // Salvăm starea matricei curente.
    // Acest lucru este necesar pentru a nu afecta alte obiecte din scena cu transformările aplicate bilei.
    glPushMatrix();

    // Mutăm bila în noua poziție.
    // Translația este aplicată în conformitate cu coordonatele actuale ale bilei.
    glTranslatef(ballPositionX, ballPositionY, ballPositionZ);

    // Setăm culoarea bilei.
    // În acest caz, bila va fi roșie.
    glColor3f(1.0f, 0.0f, 0.0f); // RGB Color: Red

    // Desenăm bila folosind o sferă solidă.
    // Prima valoare este raza sferei, iar următoarele două valori sunt numărul de segmente
    // utilizate pentru a desena sfera (latitudine și longitudine).
    glutSolidSphere(0.5f, 20, 20);

    // Restaurăm starea matricei la cea salvată anterior cu glPushMatrix.
    // Acest lucru asigură că transformările aplicate bilei nu influențează alte părți ale scenei.
    glPopMatrix();
}