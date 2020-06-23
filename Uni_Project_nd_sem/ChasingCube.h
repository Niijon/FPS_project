#ifndef CHASINGCUBE_H
#define CHASINGCUBE_H

class ChasingCube{
private:
    double Height_;
    double Width_;
    double Length_;
    float posX;
    float posZ;

    double Speed;

public:
    ChasingCube();
    ChasingCube(double,double);
    void Draw();

    void Move(float,float);
};


#endif // CHASINGCUBE_H
