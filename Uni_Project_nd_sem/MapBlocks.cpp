#include <iostream>


#include "MapBlocks.h"

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

void Floor::Draw(){
    double half_cube_size = 1.0 / 2.0;
    glPushMatrix();

    glTranslated(-15.0,-15.0,-0.0);
    glScaled(Length_,Width_,Height_);

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
    double half_cube_size = 10.0 / 2.0;
    glPushMatrix();
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

Floor::Floor(){
    Width_ = 100.0f;
    Height_ = 1.0f;
    Length_ = 100.0f;
}

bool Floor::CollisionDetection(){}

Wall::Wall(){}

bool Wall::CollisionDetection(){}

void CreateMap(Floor floor_){
    floor_.Draw();
}
