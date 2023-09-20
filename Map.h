#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <string>

#include "NonMoveableEntity.h"

class Map {
 protected:
  //  matrix of 1's - walls, and 0's - paths
  int mapSize = 42;
  int** mapMatrix;

  int numWalls;
  NonMoveableEntity** allWalls;

  int id;
  std::string name;

  // methods.
  void setNumWalls(*int[42][42] mapMatrix);

 public:
  // should call generateMap and setWallPositions.
  Map();
  ~Map();

  // generate matrix of 1's - walls, and 0's - paths
  int[42][42] generateMap();

  //  set allWalls  with positions based on mapMatrix
  void setWalls(*int[42][42] mapMatrix);
  NonMoveableEntity** getWalls(int numWalls);

  void mapDisplay();
};

#endif  // MAP_H