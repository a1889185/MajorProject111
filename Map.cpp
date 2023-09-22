#include "Map.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

#include "MazeCreator.h"  // for random maze generation.
#include "NonMoveableEntity.h"

Map::Map() : name(""), id(0), mapDensity(800), mapSize(20) {
  this->mapMatrix = generateMap();
  this->numWalls = getNumWalls();
  this->setWalls();
}
Map::Map(int _mapDensity)
    : name(""), id(0), mapDensity(_mapDensity), mapSize(20) {
  this->mapMatrix = generateMap();
  this->numWalls = getNumWalls();
  this->setWalls();
}
Map::Map(std::string _name, int _id, int _mapDensity)
    : name(_name), id(_id), mapDensity(_mapDensity), mapSize(20) {
  this->mapMatrix = generateMap();
  this->numWalls = getNumWalls();
  this->setWalls();
}

Map::~Map() {
  delete[] mapMatrix;
  delete[] allWalls;
}

void Map::draw(sf::RenderWindow* window) {
  // draw all walls.
  for (int i = 0; i < numWalls; i++) {
    window->draw(this->allWalls[i]->getShape());
  }
}

void Map::setName(std::string _name) { this->name = _name; }
void Map::setID(int _id) { this->id = _id; }
void Map::setMapDensity(int _mapDensity) { this->mapDensity = _mapDensity; }

std::string Map::getName() { return this->name; }
int Map::getID() { return this->id; }

int** Map::getMapMatrix() { return this->mapMatrix; }

NonMoveableEntity** Map::getWalls() { return this->allWalls; }

int Map::getNumWalls() {
  this->numWalls = 0;
  int i, j;
  for (i = 0; i < mapSize; i++) {
    for (j = 0; j < mapSize; j++) {
      if (this->mapMatrix[i][j] == 1) {
        this->numWalls++;
      }
    }
  }
  return numWalls;
}

// PROCTECTED METHODS

int** Map::generateMap() {
  // create ones matrix.
  int i, j;
  int** _mapMatrix = new int*[mapSize];
  for (i = 0; i < mapSize; i++) {
    _mapMatrix[i] = new int[mapSize];
    for (j = 0; j < mapSize; j++) {
      _mapMatrix[i][j] = 1;
    }
  }

  // Intialise mazeCreator to clear out paths of zeros in ones matrix.
  // start at postion 10,10.
  MazeCreator mazeCreator1(10, 10);
  mazeCreator1.leaveTrace(&_mapMatrix);  // leave first trace.

  // Move mazeCreator1 in random direction 100000 times so it can clear a path.
  int randDirection;
  for (i = 0; i < 100000; i++) {
    // random direction: 1=up, 2=right, 3=down, 4=left.
    randDirection = 1 + rand() % 4;
    // direction | _mapMatrix pointer | mapSize | Density.
    mazeCreator1.move(randDirection, &_mapMatrix, this->mapSize,
                      this->mapDensity);
  }
  return _mapMatrix;
}

// set allWalls with positions based on mapMatrix
void Map::setWalls() {
  getNumWalls();
  allWalls = new NonMoveableEntity*[this->numWalls];

  int xIndex, yIndex, i = 0;
  for (xIndex = 0; xIndex < mapSize; xIndex++) {
    for (yIndex = 0; yIndex < mapSize; yIndex++) {
      if (mapMatrix[yIndex][xIndex] == 1) {
        // create new wall of NonMoveableEntity class: x | y | type | apperance
        allWalls[i] =
            new NonMoveableEntity(xIndex, yIndex, "Wall", sf::Color::Green);

        i++;
      }
    }
  }
}
