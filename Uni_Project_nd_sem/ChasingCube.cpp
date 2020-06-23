
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

#include "ChasingCube.h"
#include "Structures.h"


ChasingCube::ChasingCube(double X, double Z){
    posX = X;
    posZ = Z;
    Width_ = 1.0;
    Height_ = 1.0;
    Length_ = 1.0;

    Speed = 5.0;
}


void ChasingCube::Draw(){
    double half_cube_size = 0.5 / 2.0;
    glPushMatrix();
    glTranslatef(posX+0.5f, 0.5f, posZ+0.5f);
    glScaled(Width_, Height_, Length_);

    // bottom
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // top
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
    }
    glEnd();

    // left
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // right
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // front
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // back
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
    }
    glEnd();
    glPopMatrix();
}

void ChasingCube::Move(float OffSetX, float OffSetZ){
    posX+=OffSetX;
    posZ+=OffSetZ;
}
