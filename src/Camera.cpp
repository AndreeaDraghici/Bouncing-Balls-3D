#include "Camera.h"
#include <GL/glut.h>

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