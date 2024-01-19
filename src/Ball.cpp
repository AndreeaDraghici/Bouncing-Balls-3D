#include "Ball.h"
#include <GL/glut.h>

void Ball::updatePosition() {
    // Actualizăm poziția bilei în funcție de direcția acesteia
    if (ballDirection) {
        ballPositionX += 0.1;
        ballPositionY += 0.1;
        ballPositionZ += 0.1;
    }
    else {
        ballPositionX -= 0.1;
        ballPositionY -= 0.1;
        ballPositionZ -= 0.1;
    }

    // Vom verifica dacă bila a atins limitele spațiului de mișcare
    if (ballPositionX > 10 || ballPositionX < -10) ballDirection = !ballDirection;
    if (ballPositionY > 10 || ballPositionY < -10) ballDirection = !ballDirection;
    if (ballPositionZ > 10 || ballPositionZ < -10) ballDirection = !ballDirection;
}

void Ball::draw() {
    // Salvăm starea matricei curente și aplicăm transformări
    glPushMatrix();
    // Mutăm bila în noua poziție
    glTranslatef(ballPositionX, ballPositionY, ballPositionZ);

    // Setăm culoarea bilei
    glColor3f(1.0f, 0.0f, 0.0f); // bila roșie

    // Desenăm bila cu raza de 0.5 și cu 20 de segmente în jurul axelor latitudinii și longitudinii
    glutSolidSphere(0.5f, 20, 20);

    // Restaurăm starea matricei
    glPopMatrix();
}
