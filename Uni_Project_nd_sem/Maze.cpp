#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stack>
#include "Maze.h"
#include "Structures.h"


Maze::Maze(const int &_size){
    size = _size;
    totalCells = ((_size-1)/2) * ((_size-1)/2);
}

//Maze creating algorithm
std::vector<std::vector<Cell>> Maze::generateMaze(){
    //CreateTable
    Cell Map[size][size];
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            Map[i][j].data = 1;
            Map[i][j].visited = false;
            Map[i][j].upw = true;
            Map[i][j].downw = true;
            Map[i][j].leftw = true;
            Map[i][j].rightw = true;
        }
    }
    for(int i=1; i<size-1; i++) {
        for(int j=1; j<size-1; j++) {
            // Border Cells have fewer accessible walls
            Map[1][j].upw = false;
            Map[size-2][j].downw = false;
            Map[i][1].leftw = false;
            Map[i][size-2].rightw = false;
        }
    }
    //Creating maze
    srand((unsigned)time(NULL));

    int rand=0;
    int randX=((2*std::rand()+1))%(size-1);
    int randY=((2*std::rand()+1))%(size-1);
    int visitedCells = 1;

    std::stack<Vec2d> backTrack;

    Map[randY][randX].data = 3;
    Map[randY][randX].visited=true;
    startPos = Vec2d(randX,randY);

    while(visitedCells<totalCells){
        if((!Map[randY-2][randX].visited && Map[randY][randX].upw && Map[randY-2][randX].downw) ||
           (!Map[randY+2][randX].visited && Map[randY][randX].downw && Map[randY+2][randX].upw) ||
           (!Map[randY][randX-2].visited && Map[randY][randX].leftw && Map[randY][randX-2].rightw) ||
           (!Map[randY][randX+2].visited && Map[randY][randX].rightw && Map[randY][randX+2].leftw))
        {
            rand = (std::rand() % 4) + 1;
            //Try upwards
            if(rand == 1 && randY>1){
                if(!Map[randY-2][randX].visited){
//                    std::cout << randX << std::endl;
                    Map[randY-1][randX].data = 0;
                    Map[randY-1][randX].visited = true;
                    Map[randY][randX].upw = false;

                    backTrack.push(Vec2d(randX,randY));
                    randY-=2;

                    Map[randY][randX].visited = true;
                    Map[randY][randX].data = 0;
                    Map[randY][randX].downw = false;

                    visitedCells++;
                }
            } else if(rand==2 && randY<size-2){ //Downwards
                if(!Map[randY+2][randX].visited){
//                    std::cout << randX << std::endl;
                    Map[randY+1][randX].data = 0;
                    Map[randY+1][randX].visited = true;
                    Map[randY][randX].downw = false;

                    backTrack.push(Vec2d(randX,randY));
                    randY+=2;

                    Map[randY][randX].visited = true;
                    Map[randY][randX].data = 0;
                    Map[randY][randX].upw = false;

                    visitedCells++;
                }
            } else if(rand == 3 && randX >1){ //Left
                if(!Map[randY][randX-2].visited){
//                    std::cout << randX << std::endl;
                    Map[randY][randX-1].data = 0;
                    Map[randY][randX-1].visited = true;
                    Map[randY][randX].leftw = false;

                    backTrack.push(Vec2d(randX,randY));
                    randX-=2;

                    Map[randY][randX].visited = true;
                    Map[randY][randX].data = 0;
                    Map[randY][randX].rightw = false;

                    visitedCells++;
                }
            } else if(rand == 4 && randX<size-2){
                if(!Map[randY][randX+2].visited){
//                    std::cout << randX << std::endl;
                    Map[randY][randX+1].data = 0;
                    Map[randY][randX+1].visited = true;
                    Map[randY][randX].rightw = false;

                    backTrack.push(Vec2d(randX,randY));
                    randX+=2;

                    Map[randY][randX].visited = true;
                    Map[randY][randX].data = 0;
                    Map[randY][randX].leftw = false;

                    visitedCells++;
                }
            }
        } else{
            randX = backTrack.top().x;
            randY = backTrack.top().y;
            backTrack.pop();
        }
    }

    goalPos = Vec2d(randX,randY);
    Map[goalPos.y][goalPos.x].data = 4;

    std::vector<std::vector<Cell>> V(size);

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            V[j].emplace_back(Map[j][i]);
        }
    }

    CellsVector = V;
   return V;
}

Vec2d Maze::getGoalPos(){
    return goalPos;
}

Vec2d Maze::getStartPos(){
    return startPos;
}


ChasingCube Maze::SpawnChasingCube(){
    srand((unsigned)time(NULL));
    int Xrand = std::rand()%(size-2) + 1;
    int Zrand = std::rand()%(size-2) + 1;

    if(CellsVector[Zrand][Xrand].data==0){
        ChasingCube(Xrand,Zrand);
    }
}

