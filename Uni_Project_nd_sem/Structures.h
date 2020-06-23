#ifndef HERO_H
#define HERO_H

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
};

struct ACell{

};


#endif // HERO_H
