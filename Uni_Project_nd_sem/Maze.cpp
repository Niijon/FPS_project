#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <set>
#include <stack>
#include "Maze.h"
#include "Structures.h"

typedef std::pair<double,std::pair<int,int>> pPair;

Maze::Maze(const int &_size){
    size = _size;
    totalCells = ((_size-1)/2) * ((_size-1)/2);
    ChasersTotal = 0;
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
            Map[i][j].posX = i;
            Map[i][j].posZ = j;
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
            if(Map[j][i].data==0)
                MovingSpaceV.emplace_back(Map[j][i]);
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

void Maze::setPos(Vec2d _pos){
    Pos=_pos;

}

//bool Maze::ReachedGoal(float, float){

//}

bool Maze::ChasedDown(Vec2d chaserPos){
    return (chaserPos.x == Pos.x && chaserPos.y == Pos.y);
}

double Maze::calcH(int row, int col){
    return sqrt((row - Pos.x)*(row - Pos.x) + (col - Pos.y)*(col - Pos.y));
}

ChasingCube Maze::SpawnChasingCube(){
    srand((unsigned)time(NULL));
    if(ChasersTotal>9){
        return ChasingCube(0,0);
    }

    int randId = std::rand()%(MovingSpaceV.size()-2);
    if(MovingSpaceV[randId].posX != Pos.x && MovingSpaceV[randId].posZ != Pos.y){
        ChasingCube chase = ChasingCube(MovingSpaceV[randId].posX,MovingSpaceV[randId].posZ);
        ChasersTotal++;
        return chase;
    } else{
        ChasingCube chase = ChasingCube(MovingSpaceV[randId+1].posX,MovingSpaceV[randId+1].posZ);
        ChasersTotal++;
        return chase;
    }

}

void Maze::AStar(double &delT, std::vector<ChasingCube> &chasers){
    for(auto &chaser:chasers){
        if(ChasedDown(chaser.getPosition())){}


        bool closedList[size][size];
        ACell cells[size][size];
        double max = size + size;

        int i;
        int j;
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                cells[i][j].f = max;
                cells[i][j].g = max;
                cells[i][j].h = max;
                cells[i][j].parentX = -1;
                cells[i][j].parentZ = -1;
                closedList[i][j]=false;
            }
        }

        i = chaser.getPosition().y;
        j = chaser.getPosition().x;

        cells[i][j].f = 0.0;
        cells[i][j].g = 0.0;
        cells[i][j].h = 0.0;
        cells[i][j].parentX = i;
        cells[i][j].parentZ = j;

        std::set<std::pair<double,std::pair<int,int>>> openList;

        openList.insert(std::make_pair(0.0,std::make_pair(i,j)));

        bool found = false;

        while(!openList.empty()){
            std::pair<double,std::pair<int,int>> p = *openList.begin();

            openList.erase(openList.begin());

            i = p.second.first;
            j = p.second.second;

            closedList[i][j] = true;

            double gNew,hNew,fNew;
            //UP
            if(ChasedDown(Vec2d(i-1,j))){
                cells[i-1][j].parentX = i;
                cells[i-1][j].parentZ = j;
                trace();//tu zapisz do vectora
                found = true;
            } else if(closedList[i-1][j] == false && CellsVector[i-1][j].data == 0){
                gNew = cells[i][j].g + 1.0;
                hNew = calcH(i-1,j);
                fNew = gNew + hNew;

                if (cells[i-1][j].f == max ||
                        cells[i-1][j].f > fNew)
                {
                    openList.insert( std::make_pair(fNew, std::make_pair(i-1, j)));

                    cells[i-1][j].f = fNew;
                    cells[i-1][j].g = gNew;
                    cells[i-1][j].h = hNew;
                    cells[i-1][j].parentX = i;
                    cells[i-1][j].parentZ = j;
                }
            }

            //DOWN

            if(ChasedDown(Vec2d(i+1,j))){
                cells[i+1][j].parentX = i;
                cells[i+1][j].parentZ = j;
                trace();//tu zapisz do vectora
                found = true;
            } else if(closedList[i+1][j] == false && CellsVector[i+1][j].data == 0){
                gNew = cells[i][j].g + 1.0;
                hNew = calcH(i+1,j);
                fNew = gNew + hNew;

                if (cells[i+1][j].f == max || cells[i+1][j].f > fNew)
                {
                    openList.insert( std::make_pair(fNew, std::make_pair(i+1, j)));

                    cells[i+1][j].f = fNew;
                    cells[i+1][j].g = gNew;
                    cells[i+1][j].h = hNew;
                    cells[i+1][j].parentX = i;
                    cells[i+1][j].parentZ = j;
                }
            }

            //RIGHT

            if(ChasedDown(Vec2d(i,j+1))){
                cells[i][j+1].parentX = i;
                cells[i][j+1].parentZ = j;
                trace();//tu zapisz do vectora
                found = true;
            } else if(closedList[i][j+1] == false && CellsVector[i][j+1].data == 0){
                gNew = cells[i][j].g + 1.0;
                hNew = calcH(i,j+1);
                fNew = gNew + hNew;

                if(cells[i][j+1].f == max || CellsVector[i][j+1].data ==0){
                    openList.insert( std::make_pair(fNew, std::make_pair (i, j+1)));

                    // Update the details of this cell
                    cells[i][j+1].f = fNew;
                    cells[i][j+1].g = gNew;
                    cells[i][j+1].h = hNew;
                    cells[i][j+1].parentX = i;
                    cells[i][j+1].parentZ = j;
                }

            }




        }

    }
}

