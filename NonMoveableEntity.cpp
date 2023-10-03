#include "NonMoveableEntity.h"

#include <SFML/Graphics.hpp>
#include <string>

#include "Entity.h"

NonMoveableEntity::NonMoveableEntity() : size(42), type(" ") {
  this->xPos = 0;
  this->yPos = 0;
  this->apperance = sf::Color::Green;
  this->shape = new sf::RectangleShape(sf::Vector2f(size, size));
  // shape position is mapmatrix index * unit (42)
  this->shape->setPosition(sf::Vector2f(xPos * 42, yPos * 42));
  this->shape->setFillColor(apperance);
}

NonMoveableEntity::NonMoveableEntity(int x, int y, std::string _type)
    : Entity::Entity(x, y), size(42), type(_type) {
  this->apperance = sf::Color::Green;
  this->shape = new sf::RectangleShape(sf::Vector2f(size, size));
  // shape position is mapmatrix index * unit (42)
  this->shape->setPosition(sf::Vector2f(xPos * 42, yPos * 42));
  this->shape->setFillColor(apperance);
}

NonMoveableEntity::NonMoveableEntity(int x, int y, std::string _type,
                                     sf::Color _apperance)
    : Entity::Entity(x, y), size(42), type(_type) {
  this->apperance = _apperance;
  this->shape = new sf::RectangleShape(sf::Vector2f(size, size));
  // shape position is mapmatrix index * unit (42)
  this->shape->setPosition(sf::Vector2f(xPos * 42, yPos * 42));
  this->shape->setFillColor(apperance);
}

NonMoveableEntity::~NonMoveableEntity() { delete[] shape; }

sf::RectangleShape NonMoveableEntity::getShape() { return *(this->shape); }

std::string NonMoveableEntity::getType() { return this->type; }
void NonMoveableEntity::setType(std::string _type) { this->type = _type; }

void NonMoveableEntity::draw(sf::RenderWindow* window) { window->draw(*shape); }

int NonMoveableEntity::getPosX() { return xPos; }
int NonMoveableEntity::getPosY() { return yPos; }