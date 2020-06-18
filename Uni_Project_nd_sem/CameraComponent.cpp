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
    CameraSpeed = 0.05f;
    Pitch = 0.0f;
    Yaw = 0.0f;
    StepX = 0;
    StepZ = 0;
}


void Camera::SetView(){
    glMatrixMode(GL_MODELVIEW);
}
void Camera::MoveForward(float Del_){
    StepZ += -(Del_* CameraSpeed * sin((Yaw+90)*TO_RADIANS));
    StepX += Del_* CameraSpeed * cos((Yaw+90)*TO_RADIANS);
    std::cout << CameraPos.x << " " << CameraPos.z << std::endl;
}

void Camera::MoveBackwards(float Del_){
    StepX += Del_* CameraSpeed * cos((Yaw+270)*TO_RADIANS);
    StepZ += -(Del_* CameraSpeed * sin((Yaw+270)*TO_RADIANS));
    std::cout << CameraPos.x << " " << CameraPos.z << std::endl;
}


void Camera::StrafeRight(float Del_){
    StepX += Del_* CameraSpeed * cos((Yaw)*TO_RADIANS);
    StepZ += -(Del_* CameraSpeed * sin((Yaw)*TO_RADIANS));
    std::cout << CameraPos.x << " " << CameraPos.z << std::endl;
}

void Camera::StrafeLeft(float Del_){
    StepX += Del_* CameraSpeed * cos((Yaw+180)*TO_RADIANS);
    StepZ += -(Del_* CameraSpeed * sin((Yaw+180)*TO_RADIANS));
    std::cout << CameraPos.x << " " << CameraPos.z << std::endl;
}

void Camera::UpdateCam(){
//    CameraPos.x += StepX;
//    CameraPos.z += StepZ;
    glLoadIdentity();
    glRotatef(-Pitch, 1.0, 0.0, 0.0);
    glRotatef(-Yaw, 0.0, 1.0, 0.0);
    glTranslatef(-CameraPos.x, 0.0, -CameraPos.z);
    StepX=0;
    StepZ=0;
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

void Camera::SetCamPos(vec2d camPos){
    CameraPos.x = camPos.x;
    CameraPos.z = camPos.z;
}



void Camera::CanMove(std::vector<std::vector<Cell>> cellV){
    int Xid = (int)CameraPos.x / 1;
    int Zid = (int)CameraPos.z / 1;

    if((CameraPos.x+StepX)>=(-0.11+double(Xid+1)) && (cellV[Xid+1][Zid].data == 1)){
        StepX = 0;
        std::cout << Xid << " " << Zid << " " << CameraPos.x << " " << CameraPos.z << " RIGHT" << std::endl;
    }

    if((CameraPos.x+StepX)<=(-0.11+double(Xid)) && cellV[Xid-1][Zid].data == 1){
        StepX = 0;
        std::cout << Xid << " " << Zid << " " << CameraPos.x << " " << CameraPos.z << " LEFT" << std::endl;
    }

    if((CameraPos.z+StepZ)>=(-0.11+double(Zid+1)) && cellV[Xid][Zid+1].data == 1){
        StepZ = 0;
        std::cout << Xid << " " << Zid << " " << CameraPos.x << " " << CameraPos.z << "DOWN" << std::endl;
    }

    if((CameraPos.z+StepZ)<=(-0.11+double(Zid)) && cellV[Xid][Zid-1].data == 1){
        StepZ = 0;
        std::cout << Xid << " " << Zid << " " << CameraPos.x << " " << CameraPos.z << "UP" << std::endl;
    }




    double size=cellV.size();

    CameraPos.x += StepX;
    CameraPos.z += StepZ;

    if(CameraPos.x <=1.0 ){
        CameraPos.x = 1.05;
    }

    else if(CameraPos.x >=size-1){
        CameraPos.x = size-0.05;
    }

    if(CameraPos.z<= 1.0){
        CameraPos.z = 1.05;
    }

    else if(CameraPos.z >=size-1){
        CameraPos.z = size-0.05;
    }
}

