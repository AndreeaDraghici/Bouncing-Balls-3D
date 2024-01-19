#include "InputHandler.h"
#include <GL/glut.h> 

void InputHandler::handleKeyboardInput(unsigned char key, int x, int y) {

    //determinare tasta apasata
    switch (key) {
    case 27: // Escape key
        exit(0); // apasare tasta ESC iar programul se inchide
        break;
    case 'a': // Move left
        scene.ball.ballPositionX += 0.8; // pozitia bilei pe axa X se va incrementa 
        break;
    case 'd': // Move right
        scene.ball.ballPositionX -= 0.3; // pozitia bilei pe axa X se va decrementa
        break;
    case 'w': // Move up
        scene.ball.ballPositionY += 0.3; // pozitia bilei pe axa Y se va incrementa
        break;
    case 's': // Move down
        scene.ball.ballPositionY -= 0.3; // pozitia bilei pe axa Y se va decrementa
        break;
    case 'q': // Move forward
        scene.ball.ballPositionZ += 0.8; // pozitia bilei pe axa Z se va incrementa
        break;
    case 'e': // Move backward
        scene.ball.ballPositionZ -= 0.8; // pozitia bilei pe axa Z se va decrementa
        break;
    }
    // Make sure the scene is updated with the new ball position
    scene.update();
}

/* pentru tastele speciale */
void InputHandler::handleSpecialInput(int key, int x, int y) {

    // pentru a determina care tasta a fost apasata
    switch (key) {
    case GLUT_KEY_UP:
        scene.camera.cameraAngleX -= 0.8f;// se decrementeaza unghiul de rotatie al camerei in jurul axei X
        if (scene.camera.cameraAngleX < scene.camera.cameraMinimumX) {
            scene.camera.cameraAngleX = scene.camera.cameraMinimumX; // limita inferioară pe axa X
        }
        break;
    case GLUT_KEY_DOWN:
        scene.camera.cameraAngleX += 0.8f;// se incrementeaza unghiul de rotatie al camerei in jurul axei X
        if (scene.camera.cameraAngleX > scene.camera.cameraMaximumX) {
            scene.camera.cameraAngleX = scene.camera.cameraMaximumX; // limita superioară pe axa X
        }
        break;
    case GLUT_KEY_LEFT:
        scene.camera.cameraAngleY -= 0.8f; // se decrementeaza unghiul de rotatie al camerei in jurul axei Y
        if (scene.camera.cameraAngleY < scene.camera.cameraMinumumY) {
            scene.camera.cameraAngleY = scene.camera.cameraMinumumY; // limita inferioară pe axa Y
        }
        break;
    case GLUT_KEY_RIGHT:
        scene.camera.cameraAngleY += 0.8f; // se incrementeaza unghiul de rotatie al camerei in jurul axei Y
        if (scene.camera.cameraAngleY > scene.camera.cameraMaximumY) {
            scene.camera.cameraAngleY = scene.camera.cameraMaximumY; // limita superioară pe axa Y
        }
        break;
    default:
        break;
    }

    // Make sure the scene is updated with the new camera angles
    scene.update();
}