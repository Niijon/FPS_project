#ifndef MAZEEXPLORER_H
#define MAZEEXPLORER_H

struct vec3d{
    float x;
    float y;
    float z;
};

struct vec2d{
  float x;
  float z;
};

vec3d MultiplyByConstant(vec3d,float);


void GameLoop(int size);
void SetupLights();
void SetView();

#endif // MAZEEXPLORER_H
