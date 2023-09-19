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
  Map();

  // generate matrix of 1's - walls, and 0's - paths
  int[42][42] generateMap();

  //  set allWalls  with positions based on matrix of walls
  void setWallPostions(int[64][64] _matrixOfWalls);
};

#endif  // MAP_H