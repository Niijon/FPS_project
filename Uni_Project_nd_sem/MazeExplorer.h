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

class mat3{
private:
    float x1;
    float x2;
    float x3;
    float x4;
    float x5;
    float x6;
    float x7;
    float x8;
    float x9;
    vec3d GetColumn1();
    vec3d GetColumn2();
    vec3d GetColumn3();
    vec3d GetRow1();
    vec3d GetRow2();
    vec3d GetRow3();

public:
    mat3(float x1_, float x2_, float x3_, float x4_, float x5_, float x6_, float x7_, float x8_, float x9_);
    mat3(vec3d,vec3d,vec3d);



    mat3 MultiplyMatrix(mat3);
};

vec3d MultiplyByConstant(vec3d,float);


void GameLoop();
void SetupLights();
void SetView();

#endif // MAZEEXPLORER_H
