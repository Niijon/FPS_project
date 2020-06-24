#ifndef CHASINGCUBE_H
#define CHASINGCUBE_H
#include "Structures.h"

class ChasingCube{
private:
    double Height_;
    double Width_;
    double Length_;
    float posX;
    float posZ;
    bool IsViable;

    double Speed;

public:
    ChasingCube();
    ChasingCube(double,double);
    void Draw();
    bool getViability();
    Vec2d getPosition();

    void Move(float,float);

    void AStar(double&,Vec2d&);
};


#endif // CHASINGCUBE_H
