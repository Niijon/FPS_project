#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include <MazeExplorer.h>

#include <GL/glu.h>


class Camera{
private:
    vec3d CameraPos;
    vec3d CameraTarget;
    vec3d CameraUp;
    float CameraSpeed;

public:
    Camera();
    Camera(vec3d,vec3d,vec3d,float);
    void SetView();
    void MoveCam(vec2d,float);

};

#endif // CAMERACOMPONENT_H
