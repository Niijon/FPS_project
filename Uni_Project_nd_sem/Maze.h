#pragma once
#include <vector>

#include "MapBlocks.h"
#include "ChasingCube.h"



class Maze {
 private:
  int size;
  int totalCells;
  int visitedCells;
  int ChasersTotal;
  std::vector<std::vector<Cell>> CellsVector;
  std::vector<Cell> MovingSpaceV;
  Vec2d startPos;
  Vec2d goalPos;
  Vec2d Pos;

  bool ReachedGoal(float,float);
  bool ChasedDown(Vec2d);

  Vec2d trace();
  double calcH(int row, int col);


 public:
  Maze(const int &size);
  std::vector<std::vector<Cell>> generateMaze();
  void convertMaze();
  Vec2d getStartPos();
  void setPos(Vec2d);
  Vec2d getGoalPos();


  void AStar(std::vector<ChasingCube>&);
  ChasingCube SpawnChasingCube();
};
