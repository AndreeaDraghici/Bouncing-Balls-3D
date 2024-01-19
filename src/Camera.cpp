#include "Camera.h"
#include <GL/glut.h>

// Metoda applyView setează viziunea (perspectiva) camerei în scena 3D.
void Camera::applyView() {
    // Funcția gluLookAt definește poziția camerei, punctul către care privește camera
    // și orientarea camerei (de exemplu, care parte este sus).
    // Parametrii sunt (eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz).

    // eyex, eyey, eyez - Poziția camerei în spațiu.
    // În acest caz, poziția camerei este ajustată în funcție de unghiurile camerei.
    gluLookAt(-10 + cameraAngleX, 9 + cameraAngleY, -10 + cameraAngleZ,
        5, 5, 5, // Presupunem că poziția inițială a bilei este (5, 5, 5).
        0, 1, 0); // Orientarea camerei, (0, 1, 0) înseamnă că Y este sus.
}

// Metoda updateCameraPosition actualizează unghiurile camerei în funcție de inputul de la tastatură.
void Camera::updateCameraPosition(int key) {
    // Această metodă este chemată atunci când o tastă specială (de exemplu, săgeată) este apăsată.

    // Switch pe baza codului tastei apăsate.
    switch (key) {
    case GLUT_KEY_UP:
        // Decrementează unghiul camerei pe axa X.
        cameraAngleX -= 0.8f;
        // Verifică dacă noul unghi este sub minimul permis și ajustează dacă este necesar.
        if (cameraAngleX < cameraMinimumX) {
            cameraAngleX = cameraMinimumX;
        }
        break;
    case GLUT_KEY_DOWN:
        // Incrementează unghiul camerei pe axa X.
        cameraAngleX += 0.8f;
        // Verifică dacă noul unghi este peste maximul permis și ajustează dacă este necesar.
        if (cameraAngleX > cameraMaximumX) {
            cameraAngleX = cameraMaximumX;
        }
        break;
    case GLUT_KEY_LEFT:
        // Decrementează unghiul camerei pe axa Y.
        cameraAngleY -= 0.8f;
        // Verifică dacă noul unghi este sub minimul permis și ajustează dacă este necesar.
        if (cameraAngleY < cameraMinumumY) {
            cameraAngleY = cameraMinumumY;
        }
        break;
    case GLUT_KEY_RIGHT:
        // Incrementează unghiul camerei pe axa Y.
        cameraAngleY += 0.8f;
        // Verifică dacă noul unghi este peste maximul permis și ajustează dacă este necesar.
        if (cameraAngleY > cameraMaximumY) {
            cameraAngleY = cameraMaximumY;
        }
        break;
    }
}