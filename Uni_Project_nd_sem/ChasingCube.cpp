
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

#include "ChasingCube.h"


ChasingCube::ChasingCube(double X, double Z){
    posX = X;
    posZ = Z;
    Width_ = 1.0;
    Height_ = 1.0;
    Length_ = 1.0;
    if(posX<1)
        IsViable = false;

    Speed = 0.01;
}


void ChasingCube::Draw(){
    double half_cube_size = 0.5 / 2.0;
    glPushMatrix();
    glTranslatef(posX+0.5, 0.0f, posZ+0.5);
    glScaled(Width_, Height_, Length_);

    // bottom
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    {
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // top
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    {
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
    }
    glEnd();

    // left
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    {
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // right
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    {
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // front
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    {
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // back
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
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
    posX-=OffSetX*Speed;
    posZ-=OffSetZ*Speed;
}

bool ChasingCube::getViability(){
    return IsViable;
}

Vec2d ChasingCube::getPosition(){
    return Vec2d((int)posX,(int)posZ);
}
