#ifndef MAZEEXPLORER_H
#define MAZEEXPLORER_H

struct vec3d{
    float x;
    float y;
    float z;
};

struct vec2d{
  float x;
  float y;
};


void GameLoop();
void SetupLights();
void SetView();

#endif // MAZEEXPLORER_H
