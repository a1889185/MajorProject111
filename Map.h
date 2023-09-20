#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <string>

#include "NonMoveableEntity.h"

class Map {
 protected:
  int id;
  std::string name;
  // matrix of 1's - walls, and 0's - paths
  int mapSize = 42;
  int** mapMatrix;
  int mapDensity;
  // array of walls to be displayed.
  int numWalls;
  NonMoveableEntity** allWalls;

  // methods.
  // generate new mapMatrix of 1's - walls, and 0's - paths
  int[42][42] generateMap();
  void setNumWalls();
  void setWalls();
  NonMoveableEntity** getWalls();

 public:
  Map();  // should call generateMap and setWalls.
  Map(std::string _name, int _id, int _mapDensity);
  ~Map();

  void mapDisplay();

  void setName(std::string _name);
  void setID(int _id);
  void setMapDensity(int _mapDensity);

  std::string getName();
  int getID();
  int[42][42] getMapMatrix();
};

#endif  // MAP_H