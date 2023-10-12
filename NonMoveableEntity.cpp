#include "NonMoveableEntity.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"

NonMoveableEntity::NonMoveableEntity() : size(42), type(" ") {
  this->xPos = 0;
  this->yPos = 0;

  sf::IntRect area = sf::IntRect();
  if (!texture.loadFromFile("Assets/Wall.png", area)) {
    std::cout << "Error loading player image." << std::endl;
  }
  this->sprite.setTexture(texture);
}

NonMoveableEntity::NonMoveableEntity(int x, int y, std::string _type)
    : Entity::Entity(x, y), size(42), type(_type) {
  // default texture is wall.
  sf::IntRect area = sf::IntRect();
  if (!texture.loadFromFile("Assets/Wall.png", area)) {
    std::cout << "Error loading player image." << std::endl;
  }
  this->sprite.setTexture(texture);
}

NonMoveableEntity::NonMoveableEntity(int x, int y, std::string _type,
                                     sf::Texture _texture)
    : Entity::Entity(x, y), size(42), type(_type) {
  this->sprite.setTexture(_texture);
}

NonMoveableEntity::~NonMoveableEntity() {}

sf::Sprite NonMoveableEntity::getShape() { return this->sprite; }

std::string NonMoveableEntity::getType() { return this->type; }
void NonMoveableEntity::setType(std::string _type) { this->type = _type; }

void NonMoveableEntity::draw(sf::RenderWindow* window) { window->draw(sprite); }

int NonMoveableEntity::getPosX() { return xPos; }
int NonMoveableEntity::getPosY() { return yPos; }