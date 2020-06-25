#ifndef HERO_H
#define HERO_H
#include <iostream>
struct vec3d{
    float x;
    float y;
    float z;
};

struct vec2d{
  float x;
  float z;
};


class Vec2d{
public:
    int x;
    int y;

    Vec2d();
    Vec2d(int,int);
};


class Vec2Param{
public:
    int x;
    int y;
    int width;
    int length;

    Vec2Param(int,int,int,int);
};

struct Cell{
    bool visited;
    bool upw;
    bool downw;
    bool leftw;
    bool rightw;
    int data;
    int posX;
    int posZ;
};

struct ACell{
    int parentX, parentZ;

    double f,g,h;
};

//struct ANode{
//    Vec2d
//};

#endif // HERO_H
