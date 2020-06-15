#pragma once
#include <vector>
struct Cell{
    bool visited;
    bool upw;
    bool downw;
    bool leftw;
    bool rightw;
    int data;
};

class Vec2d{
public:
    int x;
    int y;

    Vec2d();
    Vec2d(int,int);
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
  void generateMaze();
  void convertMaze();
};