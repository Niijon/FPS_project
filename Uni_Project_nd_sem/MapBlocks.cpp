#include <iostream>


#include "MapBlocks.h"

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

void Floor::Draw(){
    double half_cube_size = 1.0 / 2.0;
    glPushMatrix();

    glTranslated(-(0.0 - (size/2)),-1.0, -(0.0 - (size/2)));
    glScaled(Length_,Height_,Width_);
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
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
    }
    glEnd();

    // left
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // right
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // front
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    {
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    }
    glEnd();

    // back
    glColor3d(0.0, 1.0, 0.0);
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

void Wall::Draw(){
    double half_cube_size = 1.0 / 2.0;
    glPushMatrix();
    glTranslatef(posX+half_cube_size, 0.5f, posZ+half_cube_size);
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

Floor::Floor(){
    Width_ = 100.0f;
    Height_ = 1.0f;
    Length_ = 100.0f;
}

Floor::Floor(double _size){
    Width_ = _size;
    Length_ = _size;
    Height_ = 1.0f;
    size = _size;
}



Wall::Wall(){
    posX=0.0f;
    posZ=0.0f;
    Width_ = 1.0f;
    Height_ = 3.0f;
    Length_ = 1.0f;
}


Wall::Wall(float _posX, float _posZ){
    posX = _posX;
    posZ = _posZ;
    Width_ = 1.0f;
    Height_ = 3.0f;
    Length_ = 1.0f;
}


Vec2Param Wall::getGlobalBounds(){
    return Vec2Param(posX,posZ, Width_, Length_);
}

void CreateMap(Floor floor_){
    floor_.Draw();
}
