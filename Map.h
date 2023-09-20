#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <string>

#include "NonMoveableEntity.h"

class Map {
 protected:
  //  matrix of 1's - walls, and 0's - paths
  int** matrixOfWalls;

  int numWalls;
  NonMoveableEntity** allWalls;

  int id;
  std::string name;

 public:
  // should call generateMap and setWallPositions.
  Map();

  // generate matrix of 1's - walls, and 0's - paths
  int[42][42] generateMap();

  //  set allWalls  with positions based on matrix of walls
  void setWalls(*int[42][42] _matrixOfWalls);
  NonMoveableEntity** getWalls();
};

#endif  // MAP_H