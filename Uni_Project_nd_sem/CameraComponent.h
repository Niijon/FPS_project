#pragma once

#include "MazeExplorer.h"


class Camera{
private:
    vec3d CameraPos;
    vec3d CameraTarget;
    vec3d CameraUp;
    float CameraSpeed;
    float Yaw;
    float Pitch;
    float devx;
    float devy;

public:
    Camera();
    Camera(vec3d,vec3d,vec3d,float,float);
    void SetView();
    void StrafeRight(float);
    void StrafeLeft(float);
    void MoveForward(float);
    void MoveBackwards(float);
    void RotateCam(vec3d,float);
    void UpdateCam();

};


