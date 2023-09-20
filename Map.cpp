#include "Map.h"

#include <SFML/Graphics.hpp>
#include <string>

#include "NonMoveableEntity.h"

Map::Map() {}
Map::~Map() {}

// generate matrix of 1's - walls, and 0's - paths
int[42][42] Map::generateMap() {}

void Map::setNumWalls(*int[42][42] mapMatrix) {
  int i, j;
  for (i = 0; i < 42; i++) {
    for (j = 0; j < 42; j++) {
      if (mapMatrix[i][j] == 1) {
        this->numWalls++;
      }
    }
  }
}

// set allWalls  with positions based on matrix of walls
void Map::setWalls(*int[64][64] mapMatrix) {}
NonMoveableEntity** Map::getWalls() { return this->allWalls; }

void mapDisplay();