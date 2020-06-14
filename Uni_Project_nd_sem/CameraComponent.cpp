#include <iostream>
#include <math.h>

#include "CameraComponent.h"

#include <GL/glu.h>
#include <GL/gl.h>
#define TO_RADIANS 3.14/180.0


Camera::Camera(vec3d CameraPos_, vec3d CameraTarget_, vec3d CameraUp_, float CameraSpeed_, float CameraAngle_){
    CameraPos = CameraPos_;
    CameraTarget = CameraTarget_;
    CameraUp = CameraUp_;
    CameraSpeed = CameraSpeed_;
    Pitch = CameraAngle_;
    Yaw = CameraAngle_;
}

Camera::Camera(){
    CameraPos.x = 0.0;
    CameraPos.y = 0.0;
    CameraPos.z = 0.0;
    CameraTarget.x = 0.0f;
    CameraTarget.y = 0.0f;
    CameraTarget.z = -1.0f;
    CameraUp.x = 0.0f;
    CameraUp.y = 1.0f;
    CameraUp.z = 0.0f;
    CameraSpeed = 0.1f;
    Pitch = 0.0f;
    Yaw = 0.0f;
}


void Camera::SetView(){
    glMatrixMode(GL_MODELVIEW);
}
void Camera::MoveForward(float Del_){

    float StepZ = -(Del_* CameraSpeed * sin((Yaw+90)*TO_RADIANS));
    float StepX = Del_* CameraSpeed * cos((Yaw+90)*TO_RADIANS);

    CameraPos.z += StepZ;
    CameraPos.x += StepX;
}

void Camera::MoveBackwards(float Del_){
    float StepX = Del_* CameraSpeed * cos((Yaw+270)*TO_RADIANS);
    float StepZ = -(Del_* CameraSpeed * sin((Yaw+270)*TO_RADIANS));
    CameraPos.x += StepX;
    CameraPos.z += StepZ;
}


void Camera::StrafeRight(float Del_){
    //StepX
    float StepX = Del_* CameraSpeed * cos((Yaw)*TO_RADIANS);
    float StepZ = -(Del_* CameraSpeed * sin((Yaw)*TO_RADIANS));
    CameraPos.x += StepX;
    CameraPos.z += StepZ;
}

void Camera::StrafeLeft(float Del_){
    float StepX = Del_* CameraSpeed * cos((Yaw+180)*TO_RADIANS);
    float StepZ = -(Del_* CameraSpeed * sin((Yaw+180)*TO_RADIANS));
    CameraPos.x += StepX;
    CameraPos.z += StepZ;
}

void Camera::UpdateCam(){
    glLoadIdentity();
    glRotatef(-Pitch, 1.0, 0.0, 0.0);
    glRotatef(-Yaw, 0.0, 1.0, 0.0);
    glTranslatef(-CameraPos.x, 0.0, -CameraPos.z);
}


void Camera::RotateCam(float x, float y){
    int subx = x;
    int suby = y;

    float StepYaw = (float)subx/10.0;
    float StepPitch = (float)suby/10.0;

    Yaw-=StepYaw;
    Pitch-=StepPitch;

    if(Pitch>70.0){
        Pitch = 70.0;
    }
    if(Pitch<-60.0){
        Pitch = -60.0;
    }
}
