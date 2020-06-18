#ifndef MAPBLOCKS_H
#define MAPBLOCKS_H

class MapStructure{

public:
    virtual bool CollisionDetection()=0;
    virtual void Draw()=0;
};

class Floor : public MapStructure{
    double Height_;
    double Width_;
    double Length_;


public:
    Floor();
    Floor(double);
    void Draw() override;
    bool CollisionDetection() override;
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
    bool CollisionDetection() override;

};

void CreateMap(Floor floor_);

#endif // MAPBLOCKS_H
