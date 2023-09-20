#include "Map.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
int[42][42] Map::getMapMatrix() { return this->mapMatrix; }

// PROCTECTED METHODS

// generate matrix of 1's - walls, and 0's - paths
int** onesMatrix(int n) {
  int i, j;
  int** matrix = new int*[n];
  for (i = 0; i < n; i++) {
    matrix[i] = new int[n];
    for (j = 0; j < n; j++) {
      matrix[i][j] = 1;
    }
  }
  return matrix;
}
int[42][42] Map::generateMap() {
  // create ones matrix.
  this->mapMatrix = onesMatrix(this->mapSize);

  // intialise thing to clear out paths in ones matrix.
  Thing thing(20, 20);

  // move thing in random direction so it can clear a path.
  int randDirection;
  for (int i = 0; i < 100000; i++) {
    // generate random direction: 1=up, 2=right, 3=down, 4=left.
    randDirection = 1 + rand() % 4;
    thing->move(randDirection, this->& mapMatrix, this->mapSize);
  }
}

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

// set allWalls with positions based on mapMatrix
void Map::setWalls() {}
NonMoveableEntity** Map::getWalls() { return this->allWalls; }
