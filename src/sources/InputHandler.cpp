#include "../headers/InputHandler.h"
#include <GL/glut.h> 

// Metoda handleKeyboardInput gestionează inputul de la tastatura.
void InputHandler::handleKeyboardInput(unsigned char key, int x, int y) {
    // Switch pe baza codului tastei apăsate.
    switch (key) {
    case 27: // Tasta Escape
        exit(0); // Închide programul când este apăsată tasta ESC.
        break;
    case 'a': // Mișcă spre stânga
        scene.ball.ballPositionX += 0.8; // Incrementează poziția bilei pe axa X.
        break;
    case 'd': // Mișcă spre dreapta
        scene.ball.ballPositionX -= 0.3; // Decrementează poziția bilei pe axa X.
        break;
    case 'w': // Mișcă în sus
        scene.ball.ballPositionY += 0.3; // Incrementează poziția bilei pe axa Y.
        break;
    case 's': // Mișcă în jos
        scene.ball.ballPositionY -= 0.3; // Decrementează poziția bilei pe axa Y.
        break;
    case 'q': // Mișcă înainte
        scene.ball.ballPositionZ += 0.8; // Incrementează poziția bilei pe axa Z.
        break;
    case 'e': // Mișcă înapoi
        scene.ball.ballPositionZ -= 0.8; // Decrementează poziția bilei pe axa Z.
        break;
    }

    // Actualizează scena pentru a reflecta noile poziții ale bilei.
    scene.update();
}

// Metoda handleSpecialInput gestionează inputul de la tastele speciale (săgeți).
void InputHandler::handleSpecialInput(int key, int x, int y) {
    // Switch pe baza codului tastei speciale apăsate.
    switch (key) {
    case GLUT_KEY_UP:
        // Decrementează unghiul camerei pe axa X.
        scene.camera.cameraAngleX -= 0.8f;
        // Asigură că unghiul nu depășește limita minimă.
        if (scene.camera.cameraAngleX < scene.camera.cameraMinimumX) {
            scene.camera.cameraAngleX = scene.camera.cameraMinimumX;
        }
        break;
    case GLUT_KEY_DOWN:
        // Incrementează unghiul camerei pe axa X.
        scene.camera.cameraAngleX += 0.8f;
        // Asigură că unghiul nu depășește limita maximă.
        if (scene.camera.cameraAngleX > scene.camera.cameraMaximumX) {
            scene.camera.cameraAngleX = scene.camera.cameraMaximumX;
        }
        break;
    case GLUT_KEY_LEFT:
        // Decrementează unghiul camerei pe axa Y.
        scene.camera.cameraAngleY -= 0.8f;
        // Asigură că unghiul nu depășește limita minimă.
        if (scene.camera.cameraAngleY < scene.camera.cameraMinumumY) {
            scene.camera.cameraAngleY = scene.camera.cameraMinumumY;
        }
        break;
    case GLUT_KEY_RIGHT:
        // Incrementează unghiul camerei pe axa Y.
        scene.camera.cameraAngleY += 0.8f;
        // Asigură că unghiul nu depășește limita maximă.
        if (scene.camera.cameraAngleY > scene.camera.cameraMaximumY) {
            scene.camera.cameraAngleY = scene.camera.cameraMaximumY;
        }
        break;
    default:
        break;
    }

    // Actualizează scena pentru a reflecta noile unghiuri ale camerei.
    scene.update();
}