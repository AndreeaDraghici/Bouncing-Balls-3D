#include "Scene.h"
#include <GL/glut.h>

/* initializarea contextului OpenGL */
void Scene::initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Setează culoarea de fundal la negru
    glShadeModel(GL_SMOOTH); // Setează modul de shading la smooth

    glEnable(GL_DEPTH_TEST); // Activează testul de adâncime
    glEnable(GL_LIGHTING); // Activează iluminarea
    glEnable(GL_LIGHT0); // Activează sursa de lumină 0

    GLfloat lightPosition[] = { 0.0f, 10.0f, 0.0f, 1.0f }; // Setează poziția sursei de lumină
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_COLOR_MATERIAL); // Activează urmărirea culorii pentru materiale
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

/* functie de afisare a obiectelor in fereastra */
void Scene::display(void) {
    // se curata buffer-ul de culoare 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // seteaza matricea de modelare si vizualizare 
    glMatrixMode(GL_MODELVIEW);//seteaza modul de transformare al matericei
    glLoadIdentity();//resetare matrice curenta la matricea identitate

    // folosita pentru a defini pozitia camerei cu ajutorul parametrilor de distanta , unghi de vedere si pozitia obiectului
    gluLookAt(-10 + camera.cameraAngleX, 9 + camera.cameraAngleY, -10 + camera.cameraAngleZ,
        ball.ballPositionX, ball.ballPositionY, ball.ballPositionZ,
        0, 6, 0);

    // Enable blending for the walls
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //specifica modul de amestecare intre pixelii suprapusi.

    // seteaza proprietatile pentru material
    GLfloat matAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // seteaza culoarea planului la albastru
    glVertex3f(-25, 0, -25);
    glVertex3f(-25, 0, 25);
    glVertex3f(25, 0, 25);
    glVertex3f(25, 0, -25);
    glEnd();

    glColor3f(0.0f, 1.0f, 1.0f); // seteaza culoarea planului la albastru deschis
    //desenare plan format din triunghiuri pentru a da senzatia de denivelare
    glBegin(GL_TRIANGLES);
    //pentru fiecare colt al triunghiului, coordonatele x și z sunt incrementate cu 0,5 pentru a desena triunghiuri mai mici in interiorul planului. 
    for (float x = -25; x < 25; x += 0.5) {
        for (float z = -25; z < 25; z += 0.5) {

            glVertex3f(x, 0, z); // este apelata pentru a specifica coordonatele fiecarui varf al triunghiului
            glVertex3f(x + 0.5, 0, z);
            glVertex3f(x, 0, z + 0.5);

            glVertex3f(x + 0.5, 0, z);
            glVertex3f(x + 0.5, 0, z + 0.5);
            glVertex3f(x, 0, z + 0.5);
        }
    }
    glEnd();

    // pereti
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // seteaza culoarea peretelui
    // valorile pentru peretele din dreapta sunt setate la -25 pentru a plasa peretele in spatele obiectelor existente in scena
    glVertex3f(-25, 0, -25);
    glVertex3f(-25, 25, -25);
    glVertex3f(25, 25, -25);
    glVertex3f(25, 0, -25);

    // valorile pentru peretele din spate sunt setate la -25 pentru a plasa peretele in spatele obiectelor existente in scena
    glVertex3f(-25, 0, -25);
    glVertex3f(-25, 0, 25);
    glVertex3f(-25, 25, 25);
    glVertex3f(-25, 25, -25);

    // valorile pentru peretele din stanga sunt setate la -25 pentru a plasa peretele in spatele obiectelor existente in scena
    glVertex3f(-25, 0, 25);
    glVertex3f(25, 0, 25);
    glVertex3f(25, 25, 25);
    glVertex3f(-25, 25, 25);
    glEnd();

    // desenare bile
    glTranslatef(7, ball.widthPlaneOfBall + 1.5, 4);
    glColor3f(1, 0, 1);//galben
    glutSolidSphere(1.9f, 50, 50);
    glEnd();

    glTranslatef(7, ball.widthPlaneOfBall + 1, 9);
    glColor3f(1, 1, 1); // alb
    glutSolidSphere(1.9f, 50, 50);
    glEnd();

    glPopMatrix();

    // schimbare buffer pentru a permite afisarea
    glutSwapBuffers();
}

void Scene::reshape(int width, int height) {
    if (height == 0) height = 1; // Prevenirea împărțirii la zero
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void Scene::update() {
    // Actualizarea logicii pentru bouncing ball
    if (ball.ballDirection) {
        ball.ballPositionY += 0.1f; // Deplasare în sus
    }
    else {
        ball.ballPositionY -= 0.1f; // Deplasare în jos
    }

    // Verificăm dacă bila atinge limitele superioară sau inferioară
    if (ball.ballPositionY > ball.heightPlaneOfBall || ball.ballPositionY < 0) {
        ball.ballDirection = !ball.ballDirection; // Schimbă direcția
    }

    // Redesenează scena
    glutPostRedisplay();
}

void Scene::bouncing_balls() {
    /* verificam daca mingea atinge marginea de sus sau de jos a ecranului */
    if (ball.widthPlaneOfBall == 0 || ball.widthPlaneOfBall == ball.heightPlaneOfBall) {
        //se inverseaza valoarea variabilei, iar mingea isi schimba directia
        ball.ballDirection ^= 1;
    }

    /* actualizeaza pozitia bilei */
    if (ball.ballDirection) {
        ball.widthPlaneOfBall += 0.5; // bila se ridica
    }
    else {
        ball.widthPlaneOfBall -= 0.5; // bila coboara
    }

    glutTimerFunc(30, Scene::timer, 0); // viteza de miscare.
}

// utilizata pentru a declansa redesenarea ecranului in urmatorul cadru de afisare
void Scene::timer(int v) {

    //indica faptul ca ecranul trebuie redesenat in urmatorul cadru de afisare
    glutPostRedisplay();

    //declanseaza o noua intrerupere de tip timer peste 16 milisecunde
    //apelare periodica a functiei timer pentru a ne asigura ca ecranul este actualiat la fiecare cadru de afisare, vizual fiind mai placut
    glutTimerFunc(16,  Scene::timer, 0);
}
