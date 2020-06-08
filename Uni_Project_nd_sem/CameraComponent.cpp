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
    CameraSpeed = 0.2f;
    Pitch = 0.0f;
    Yaw = 0.0f;
}


void Camera::SetView(){
    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 0.0,
//              0.0, 0.0, 1.0,
//              0.0, 1.0,0.0);
}

void Camera::MoveForward(float Del_){
//    float viewX = CameraTarget.x - CameraPos.x;
//    float viewY = CameraTarget.y - CameraPos.y;
//    float viewZ = CameraTarget.z - CameraPos.z;
//    //float matrix[16];glGetFloatv(GL_MODELVIEW_MATRIX, matrix);

//    CameraPos.x += viewX * factor * Del_ * 0.00001f * CameraSpeed;
//    CameraPos.y += viewY * factor * Del_ * 0.00001f * CameraSpeed;
//    CameraPos.z += viewZ * factor * Del_ * 0.00001f * CameraSpeed;

//    CameraTarget.x += viewX * factor * Del_ * 0.00001f * CameraSpeed;
//    CameraTarget.y += viewY * factor * Del_ * 0.00001f * CameraSpeed;
//    CameraTarget.z += viewZ * factor * Del_ * 0.00001f * CameraSpeed;

//    float viewX = -CameraTarget.x + CameraPos.x;
//    float viewY = -CameraTarget.y + CameraPos.y;
//    float viewZ = -CameraTarget.z + CameraPos.z;


//    CameraPos.x += CameraSpeed * CameraTarget.x * Del_;
//    CameraPos.y += CameraSpeed * CameraTarget.y * Del_;
//    CameraPos.z += CameraSpeed * CameraTarget.z * Del_;


    float StepZ = -(Del_* CameraSpeed * sin((Yaw+90)*TO_RADIANS));
    float StepX = Del_* CameraSpeed * cos((Yaw+90)*TO_RADIANS);

    CameraPos.z += StepZ;
    CameraPos.x += StepX;
    glTranslatef(-StepX, 0.0, -StepZ);
    std::cout << " " << StepZ << " " << CameraPos.z << std::endl;
}

void Camera::MoveBackwards(float Del_){
    float StepX = Del_* CameraSpeed * cos((Yaw+270)*TO_RADIANS);
    float StepZ = -(Del_* CameraSpeed * sin((Yaw+270)*TO_RADIANS));
    CameraPos.x += StepX;
    CameraPos.z += StepZ;
    glTranslatef(-StepX, 0.0, -StepZ);
    std::cout << StepZ << " " << CameraPos.z << std::endl;
}


void Camera::StrafeRight(float Del_){
    //StepX
    float StepX = Del_* CameraSpeed * cos((Yaw)*TO_RADIANS);
    float StepZ = -(Del_* CameraSpeed * sin((Yaw)*TO_RADIANS));
    CameraPos.x += StepX;
    CameraPos.z += StepZ;
//    float x = ((CameraTarget.y * CameraUp.z) - (CameraTarget.z * CameraUp.y));
//    float y = ((CameraTarget.z * CameraUp.x) - (CameraTarget.x * CameraUp.z));
//    float z = ((CameraTarget.x * CameraUp.y) - (CameraTarget.y * CameraUp.x));

//    float magnitude = sqrt( (x * x) + (y * y) + (z * z) );

//    x /= magnitude;
//    y /= magnitude;
//    z /= magnitude;

//    CameraPos.x += x * Del_ * 0.00008f  * CameraSpeed;
//    CameraPos.y += y *  Del_ * 0.00008f  * CameraSpeed;
//    CameraPos.z += z *  Del_ * 0.00008f  * CameraSpeed;

    glTranslatef(-StepX, 0.0, -StepZ);
}

void Camera::StrafeLeft(float Del_){
    float StepX = Del_* CameraSpeed * cos((Yaw+180)*TO_RADIANS);
    float StepZ = -(Del_* CameraSpeed * sin((Yaw+180)*TO_RADIANS));
    CameraPos.x += StepX;
    CameraPos.z += StepZ;

    glTranslatef(-StepX, 0.0, -StepZ);
}

void Camera::UpdateCam(){
    glRotatef(-Pitch, 1.0, 0.0, 0.0);
    glRotatef(-Yaw, 0.0, 1.0, 0.0);


}


//void Camera::RotateCam(vec3d angles,float Del_){
//    CameraAngle += Del_ * 0.00008f * factor;
//    xAngle = sin(CameraAngle);
//    zAngle = -cos(CameraAngle);
//}
