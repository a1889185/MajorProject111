#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>

#include "MazeCreator.h"
#include "NonMoveableEntity.h"

using namespace std;

class Map {
 protected:
  int id;
  string name;

  int mapSize;
  int mapDensity;
  int numWalls;
  int** mapMatrix;               // matrix of 1's - walls, and 0's - paths
  NonMoveableEntity** allWalls;  // array of walls to be displayed.

  int** generateMap();  // generate new mapMatrix [mapSize][mapSize]
  void setWalls();      // set allWalls array.

 public:
  Map();
  Map(int _mapDensity);
  Map(string _name, int _id, int _mapDensity);
  ~Map();

  void draw(sf::RenderWindow* window);

  void setName(string _name);
  void setID(int _id);
  void setMapDensity(int _mapDensity);

  string getName();
  int getID();
  int** getMapMatrix();
  int getNumWalls();
  NonMoveableEntity** getWalls();
};

#endif  // MAP_H