#include "Entity.h"

Entity::Entity() {
  this->xPos = 0;
  this->yPos = 0;
}

Entity::Entity(int _xPos, int _yPos) : xPos(_xPos), yPos(_yPos) {}

Entity::~Entity() {}

int Entity::getPosX() { return xPos; }
int Entity::getPosY() { return yPos; }