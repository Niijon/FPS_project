#ifndef MAPBLOCKS_H
#define MAPBLOCKS_H

class MapStructure{

public:
    virtual bool CollisionDetection()=0;
    virtual void Draw()=0;
};

class Floor : public MapStructure{
    float Height_;
    float Width_;
    float Length_;


public:
    Floor();
    void Draw() override;
    bool CollisionDetection() override;
};

class Wall : public MapStructure{
    float Height_;
    float Width_;
    float Length_;

public:
    Wall();
    void Draw() override;
    bool CollisionDetection() override;

};

void CreateMap(Floor floor_);

#endif // MAPBLOCKS_H
