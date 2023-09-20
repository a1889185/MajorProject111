#include "Map.h"

#include <SFML/Graphics.hpp>
#include <string>

#include "NonMoveableEntity.h"

Map::Map() : name(""), id(0), mapDensity(100) {
  this->generateMap();
  this->getNumWalls();
  this->setWalls();
}
Map::Map(std::string _name, int _id, int _mapDensity)
    : name(_name), id(_id), mapDensity(_mapDensity) {
  this->generateMap();
  this->getNumWalls();
  this->setWalls();
}
Map::~Map() {
  delete[] mapMatrix;
  delete[] allWalls;
}

void Map::mapDisplay() {}

void Map::setName(string _name) { this->name = _name; }
void Map::setID(int _id) { this->id = _id; }
void Map::setMapDensity(int _mapDensity) { this->mapDensity = _mapDensity; }

std::string Map::getName() { return this->name; }
int Map::getID() { return this->id; }

// PROCTECTED METHODS

// generate matrix of 1's - walls, and 0's - paths
int[42][42] Map::generateMap() {}

void Map::setNumWalls() {
  int i, j;
  for (i = 0; i < 42; i++) {
    for (j = 0; j < 42; j++) {
      if (this->mapMatrix[i][j] == 1) {
        this->numWalls++;
      }
    }
  }
}

// set allWalls with positions based on matrix of walls
void Map::setWalls() {}
NonMoveableEntity** Map::getWalls() { return this->allWalls; }
