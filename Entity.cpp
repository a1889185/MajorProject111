#include "Entity.h"

Entity::Entity() : xPos(0), yPos(0) {}

Entity::Entity(int _xPos, int _yPos) : xPos(_xPos), yPos(_yPos) {}

Entity::~Entity() {}

int Entity::getPosX() { return this->xPos; }
int Entity::getPosY() { return this->yPos; }