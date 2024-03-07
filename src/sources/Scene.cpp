#include "../headers/Scene.h"
#include <GL/glut.h>

/* OpenGL context initialization */
void Scene::initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Sets the background color to black
    glShadeModel(GL_SMOOTH); // Sets shading mode to smooth

    glEnable(GL_DEPTH_TEST); // Enables depth testing
    glEnable(GL_LIGHTING); // Enables lighting
    glEnable(GL_LIGHT0); // Enables light source 0

    GLfloat lightPosition[] = { 0.0f, 10.0f, 0.0f, 1.0f }; // Sets the light source position
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_COLOR_MATERIAL); // Enables color tracking for materials
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

/* Object rendering function */
void Scene::display(void) {
    // Clears the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the modeling and viewing matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Sets the camera position using distance parameters, viewing angle, and object position
    gluLookAt(-10 + camera.cameraAngleX, 9 + camera.cameraAngleY, -10 + camera.cameraAngleZ,
        ball.ballPositionX, ball.ballPositionY, ball.ballPositionZ,
        0, 1, 0);

    // Enables blending for walls
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Sets material properties
    GLfloat matAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);

    drawTrees();

    drawPlanOfFloor();

    drawWalls();

    drawBalls();

    // Swaps buffers to display the rendered image
    glutSwapBuffers();
}

/* This function draws balls in the 3D scene using translation to move to the specified location and glColor3f to set the color of each ball.
glutSolidSphere is used to create the balls with the specified radius and level of detail. */
void Scene::drawBalls() {
    // Drawing balls
    glPushMatrix(); // Corrected by adding glPushMatrix to ensure transformations don't affect subsequent objects
    glTranslatef(7, ball.widthPlaneOfBall + 1.5, 4);
    glColor3f(1, 0, 1); // Purple
    glutSolidSphere(1.9f, 50, 50);
    glPopMatrix(); // Added glPopMatrix here

    glPushMatrix(); // Corrected by adding glPushMatrix
    glTranslatef(7, ball.widthPlaneOfBall + 1, 9);
    glColor3f(1, 1, 1); // White
    glutSolidSphere(1.9f, 50, 50);
    glPopMatrix(); // Added glPopMatrix here
}

/* The function creates two trees in the scene using generateTree, which draws a tree using cylinders for the trunk and spheres for the crown.
glPushMatrix and glPopMatrix are used to ensure that transformations applied to one tree do not affect the rest of the scene. */
void Scene::drawTrees() {
    glPushMatrix();
    glTranslatef(-20, 0, -15); // Position for the first tree
    generateTree(10.0, 5.0, 6.0); // Trunk height increased to 10
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, 0, 15); // Position for the second tree
    generateTree(10.0, 5.0, 6.0); // Trunk height increased to 10
    glPopMatrix();
}

/* The ground plane is initially drawn as a large green-colored quad using glBegin(GL_QUADS) and glEnd().
Then, details are added in the form of darker green triangles to create a texture or an effect of uneven ground. */
void Scene::drawPlanOfFloor() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); // Sets the plane color to green
    glVertex3f(-25, 0, -25);
    glVertex3f(-25, 0, 25);
    glVertex3f(25, 0, 25);
    glVertex3f(25, 0, -25);
    glEnd();

    // Adds texture by drawing darker green triangles for an uneven ground effect
    glColor3f(0.2f, 0.5f, 0.0f); // Sets the triangles color to a darker green
    glBegin(GL_TRIANGLES);
    // Triangles are drawn by incrementing x and z coordinates within the plane to create a detailed texture
    for (float x = -25; x < 25; x += 0.5) {
        for (float z = -25; z < 25; z += 0.5) {
            glVertex3f(x, 0, z);
            glVertex3f(x + 0.5, 0, z);
            glVertex3f(x, 0, z + 0.5);

            glVertex3f(x + 0.5, 0, z);
            glVertex3f(x + 0.5, 0, z + 0.5);
            glVertex3f(x, 0, z + 0.5);
        }
    }
    glEnd();
}

/* Draws the room's walls using quads. Each wall is drawn separately, with glColor3f setting the color to blue.
Coordinates are set so the walls enclose the scene, creating a room or box effect. */
void Scene::drawWalls() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // Sets the wall color to blue
    // Right wall
    glVertex3f(-25, 0, -25);
    glVertex3f(-25, 25, -25);
    glVertex3f(25, 25, -25);
    glVertex3f(25, 0, -25);
    // Back wall
    glVertex3f(-25, 0, -25);
    glVertex3f(-25, 0, 25);
    glVertex3f(-25, 25, 25);
    glVertex3f(-25, 25, -25);
    // Left wall
    glVertex3f(-25, 0, 25);
    glVertex3f(25, 0, 25);
    glVertex3f(25, 25, 25);
    glVertex3f(-25, 25, 25);
    glEnd();
}

/* The reshape function is called automatically when the OpenGL window is resized. */
void Scene::reshape(int width, int height) {
    if (height == 0) height = 1; // Prevents division by zero
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    // Sets the viewport to cover the new window dimensions
    glViewport(0, 0, width, height);
    // Changes the matrix mode to GL_PROJECTION for setting up the projection camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Sets the perspective camera with a 45-degree field of view and near and far clipping distances
    gluPerspective(45.0, aspect, 0.1, 100.0);
    // Returns to the modelview matrix mode to control object positioning and camera view in the 3D scene
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* This method is used to update the vertical position (Y-axis) of the ball */
void Scene::update() {
    // Bouncing ball logic update
    if (ball.ballDirection) {
        ball.ballPositionY += 0.1f; // Move up
    }
    else {
        ball.ballPositionY -= 0.1f; // Move down
    }

    // Check if the ball reaches the upper or lower limits
    if (ball.ballPositionY > ball.heightPlaneOfBall || ball.ballPositionY < 0) {
        ball.ballDirection = !ball.ballDirection; // Change direction
    }

    // Redraw the scene
    glutPostRedisplay();
}

/* This method focuses on the ball's movement. It checks if the ball reaches the top or bottom edge of the screen. If so, it reverses the direction of the ball's movement. */
void Scene::bouncing_balls() {
    // Checks if the ball reaches the top or bottom edge of the screen and reverses direction if necessary
    if (ball.widthPlaneOfBall == 0 || ball.widthPlaneOfBall == ball.heightPlaneOfBall) {
        ball.ballDirection ^= 1; // Toggles the direction
    }

    // Updates the ball's position
    if (ball.ballDirection) {
        ball.widthPlaneOfBall += 0.5; // The ball moves upwards
    }
    else {
        ball.widthPlaneOfBall -= 0.5; // The ball moves downwards
    }

    // Sets a timer for movement speed
    glutTimerFunc(30, Scene::timer, 0);
}

// This method is used to trigger screen redraw in the next display frame
void Scene::timer(int v) {
    // Indicates that the screen needs to be redrawn in the next frame
    glutPostRedisplay();

    // Triggers a new timer interrupt after 16 milliseconds to ensure the screen is updated every frame, providing a smoother visual experience
    glutTimerFunc(16, Scene::timer, 0);
}

// Drawing a tree in the scene
void Scene::generateTree(double trunkHeight, double crownHeight, double radius) {
    // Drawing the trunk
    glColor3f(0.5, 0.35, 0.05); // Sets the color for drawing the tree trunk to a shade of brown, representing the trunk's color.
    GLUquadricObj* trunk = gluNewQuadric(); // Creates a new quadric object for drawing cylindrical shapes.
    gluQuadricDrawStyle(trunk, GLU_FILL); // Sets the drawing style to filled, making the shape solid.
    gluQuadricNormals(trunk, GLU_SMOOTH); // Sets normals to smooth for realistic lighting.

    glPushMatrix(); // Saves the current transformation matrix state.
    glRotatef(-90, 1.0, 0.0, 0.0); // Rotates the coordinate system to position the cylinder vertically.
    gluCylinder(trunk, radius / 2, radius / 4, trunkHeight, 20, 20); // Draws the cylinder representing the tree trunk.

    glPopMatrix(); // Restores the previously saved transformation matrix state.

    // Drawing the crown
    glColor3f(0.0, 0.5, 0.0); // Changes color to green for drawing the tree crown, representing foliage.
    GLUquadricObj* crown = gluNewQuadric(); // Creates a new quadric object for the crown.
    gluQuadricDrawStyle(crown, GLU_FILL); // Sets the drawing style to filled for the crown.
    gluQuadricNormals(crown, GLU_SMOOTH); // Sets normals to smooth for the crown.

    glPushMatrix(); // Saves the transformation matrix state again.
    glTranslatef(0, trunkHeight + crownHeight, 0); // Moves the crown to the top of the trunk, adding the trunk's height to the crown's position.

    gluSphere(crown, radius, 20 * 2, 20); // Draws a sphere representing the tree crown.

    glPopMatrix(); // Restores the transformation matrix state, maintaining position changes only for the crown.
}
