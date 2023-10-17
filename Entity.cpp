#include "Entity.h"

#include <SFML/Graphics.hpp>

Entity::Entity() : xPos(0), yPos(0) {}

Entity::Entity(int _xPos, int _yPos) : xPos(_xPos), yPos(_yPos) {
  this->sprite.setPosition(sf::Vector2f(xPos * 42, yPos * 42));
}

Entity::~Entity() {}

int Entity::getPosX() { return this->xPos; }
int Entity::getPosY() { return this->yPos; }
