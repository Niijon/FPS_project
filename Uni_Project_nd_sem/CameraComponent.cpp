

#include "CameraComponent.h"

Camera::Camera(vec3d CameraPos_, vec3d CameraTarget_, vec3d CameraUp_, float CameraSpeed_){
    CameraPos = CameraPos_;
    CameraTarget = CameraTarget_;
    CameraUp = CameraUp_;
    CameraSpeed = CameraSpeed_;
}


Camera::Camera(){
    CameraPos.x = 10.0;
    CameraPos.y = 1.0;
    CameraPos.z = 10.0;
    CameraTarget.x = 0.0;
    CameraTarget.y = 0.0;
    CameraTarget.z = 0.0;
    CameraUp.x = 0.0;
    CameraUp.y = 1.0;
    CameraUp.z = 0.0;
}

void Camera::SetView(){
    gluLookAt(CameraPos.x, CameraPos.y, CameraPos.z,
              CameraTarget.x, CameraTarget.y, CameraTarget.z,
              CameraUp.x, CameraUp.y,CameraUp.z);
}


void Camera::MoveCam(vec2d Direction_){

}
