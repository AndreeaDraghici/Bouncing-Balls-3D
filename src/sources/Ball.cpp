#include "../headers/Ball.h"
#include <GL/glut.h>

// The draw method is responsible for drawing the ball.
void Ball::draw() {
    // Save the current matrix state.
    // This is necessary to avoid affecting other objects in the scene with the transformations applied to the ball.
    glPushMatrix();

    // Move the ball to its new position.
    // The translation is applied according to the ball's current coordinates.
    glTranslatef(ballPositionX, ballPositionY, ballPositionZ);

    // Set the color of the ball.
    // In this case, the ball will be red.
    glColor3f(1.0f, 0.0f, 0.0f); // RGB Color: Red

    // Draw the ball using a solid sphere.
    // The first value is the radius of the sphere, and the next two values are the number of segments
    // used to draw the sphere (latitude and longitude).
    glutSolidSphere(0.5f, 20, 20);

    // Restore the matrix state to what it was before with glPushMatrix.
    // This ensures that the transformations applied to the ball do not affect other parts of the scene.
    glPopMatrix();
}
