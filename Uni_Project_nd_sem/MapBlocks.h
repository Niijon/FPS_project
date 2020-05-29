#ifndef MAPBLOCKS_H
#define MAPBLOCKS_H

class MapStructure{

public:
    virtual bool CollisionDetection()=0;
    virtual void Draw(double size)=0;
};

class Floor : public MapStructure{


public:
    void Draw(double size) override;
};

class Wall : public MapStructure{


public:
    void Draw(double size) override;

};

#endif // MAPBLOCKS_H
