#ifndef MAPBLOCKS_H
#define MAPBLOCKS_H

#include "Structures.h"

class MapStructure{

public:
    virtual void Draw()=0;
};

class Floor : public MapStructure{
    double Height_;
    double Width_;
    double Length_;
    double size;


public:
    Floor();
    Floor(double);
    void Draw() override;
};

class Wall : public MapStructure{
    double Height_;
    double Width_;
    double Length_;
    float posX;
    float posZ;

public:
    Wall();
    Wall(float posX, float posZ);
    void Draw() override;
    Vec2Param getGlobalBounds();

};

void CreateMap(Floor floor_);

#endif // MAPBLOCKS_H
