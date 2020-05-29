#ifndef MAPBLOCKS_H
#define MAPBLOCKS_H

class MapStructure{

public:
    virtual bool CollisionDetection()=0;
};

class Floor : public MapStructure{


public:

};

class Wall : public MapStructure{


public:

};

#endif // MAPBLOCKS_H
