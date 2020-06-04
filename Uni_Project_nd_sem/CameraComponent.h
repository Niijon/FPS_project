#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "MazeExplorer.h"

class Camera{
private:
    vec3d CameraPos;
    vec3d CameraTarget;
    vec3d CameraUp;
    float CameraSpeed;
    float CameraAngle;

public:
    Camera();
    Camera(vec3d,vec3d,vec3d,float,float);
    void SetView();
    void MoveCam(vec2d,float);
    void RotateCam(vec3d,float);

};

#endif // CAMERACOMPONENT_H
