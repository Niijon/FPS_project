#include <iostream>


#include "MapBlocks.h"

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

void Floor::Draw(double size){
    double half_cube_size = size / 2.0;

        // bottom
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // top
        glColor3d(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glEnd();

        // left
        glColor3d(0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // right
        glColor3d(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // front
        glColor3d(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // back
        glColor3d(0.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glEnd();
}

void Wall::Draw(double size){
    double half_cube_size = size / 2.0;

        // bottom
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // top
        glColor3d(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glEnd();

        // left
        glColor3d(0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // right
        glColor3d(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // front
        glColor3d(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // back
        glColor3d(0.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glEnd();
}
