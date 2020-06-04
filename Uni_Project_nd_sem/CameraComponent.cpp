
#include "CameraComponent.h"

#include <GL/glu.h>


Camera::Camera(vec3d CameraPos_, vec3d CameraTarget_, vec3d CameraUp_, float CameraSpeed_, float CameraAngle_){
    CameraPos = CameraPos_;
    CameraTarget = CameraTarget_;
    CameraUp = CameraUp_;
    CameraSpeed = CameraSpeed_;
    CameraAngle = CameraAngle_;
}

Camera::Camera(){
    CameraPos.x = 10.0;
    CameraPos.y = 1.0;
    CameraPos.z = -60.0;
    CameraTarget.x = 0.0f;
    CameraTarget.y = 0.0f;
    CameraTarget.z = -1.0f;
    CameraUp.x = 0.0f;
    CameraUp.y = 1.0f;
    CameraUp.z = 0.0f;
    CameraSpeed = 15.0f;
    CameraAngle = 10.0f;
}


void Camera::SetView(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(CameraPos.x, CameraPos.y, CameraPos.z,
              CameraTarget.x, CameraTarget.y, CameraTarget.z,
              CameraUp.x, CameraUp.y,CameraUp.z);


}


void Camera::MoveCam(vec2d Direction_,float Del_){
    CameraPos.x += Direction_.x*Del_*CameraSpeed;
    CameraPos.z += Direction_.z*Del_*CameraSpeed;
    CameraTarget.x += Direction_.x*Del_*CameraSpeed;
    CameraTarget.z += Direction_.z*Del_*CameraSpeed;
}


void Camera::RotateCam(vec3d angles,float Del_){

}
