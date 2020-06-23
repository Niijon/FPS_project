#pragma once
#include <vector>

#include "MapBlocks.h"
#include "ChasingCube.h"



class Maze {
 private:
  int size;
  int totalCells;
  int visitedCells;
  std::vector<std::vector<Cell>> CellsVector;
  std::vector<std::vector<ACell>> ACellVector;
  Vec2d startPos;
  Vec2d goalPos;

  bool ReachedGoal(float,float);


 public:
  Maze(const int &size);
  std::vector<std::vector<Cell>> generateMaze();
  void convertMaze();
  Vec2d getStartPos();
  Vec2d getGoalPos();

  void AStar();
  ChasingCube SpawnChasingCube();
};
