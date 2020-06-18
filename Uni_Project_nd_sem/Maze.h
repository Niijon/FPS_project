#pragma once
#include <vector>

#include "MapBlocks.h"

struct Cell{
    bool visited;
    bool upw;
    bool downw;
    bool leftw;
    bool rightw;
    int data;
};


class Maze {
 private:
  int size;
  int totalCells;
  int visitedCells;
  std::vector<Cell> CellsVector;
  Vec2d startPos;
  Vec2d goalPos;


 public:
  Maze(int size);
  std::vector<std::vector<Cell>> generateMaze();
  void convertMaze();
  Vec2d getStartPos();
  Vec2d getGoalPos();
};
