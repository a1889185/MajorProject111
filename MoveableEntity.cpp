#include "MoveableEntity.h"

#include <string>

#include "Entity.h"
#include "Map.h"

MoveableEntity::MoveableEntity() : Entity::Entity() {
  this->damage = 0;
  this->health = 0;
  this->size = 42;
  this->shape.setSize(sf::Vector2f(size, size));
  this->shape.setFillColor(sf::Color::Red);
  this->shape.setPosition(sf::Vector2f(xPos, yPos));
}
MoveableEntity::MoveableEntity(int _xPos, int _yPos)
    : Entity::Entity(_xPos, _yPos) {
  this->damage = 0;
  this->health = 0;
  this->size = 42;
  this->shape.setSize(sf::Vector2f(size, size));
  this->shape.setFillColor(sf::Color::Red);
  this->shape.setPosition(sf::Vector2f(xPos * 42, yPos * 42));
}
MoveableEntity::MoveableEntity(int _xPos, int _yPos, int damage, int health)
    : Entity::Entity(_xPos, _yPos), damage(damage), health(health) {
  this->size = 42;
  this->shape.setSize(sf::Vector2f(size, size));
  this->shape.setFillColor(sf::Color::Red);
  this->shape.setPosition(sf::Vector2f(xPos * 42, yPos * 42));
}

// methods.
void MoveableEntity::setPosX(int _xPos) {
  this->xPos = _xPos;
  // update shape postion which is matrix postion * unit (42).
  this->shape.setPosition(sf::Vector2f(xPos * 42, yPos * 42));
}
void MoveableEntity::setPosY(int _yPos) {
  this->yPos = _yPos;
  // update shape postion which is matrix postion * unit (42).
  this->shape.setPosition(sf::Vector2f(xPos * 42, yPos * 42));
}

void MoveableEntity::setHealth(int _health) { this->health = _health; }
void MoveableEntity::setDamage(int _damage) { this->damage = _damage; }

int MoveableEntity::getHealth() { return health; }
int MoveableEntity::getDamage() { return damage; }

int MoveableEntity::getPosX() { return xPos; }
int MoveableEntity::getPosY() { return yPos; }

void MoveableEntity::draw(sf::RenderWindow* window) { window->draw(shape); }

void MoveableEntity::attackOpponent(MoveableEntity* opponent) {
  if (opponent != nullptr) {
    int OpponentHealth = opponent->getHealth();
    opponent->setHealth(OpponentHealth - this->damage);
    // min is zero.
    OpponentHealth = opponent->getHealth();
    if (OpponentHealth < 0) {
      opponent->setHealth(0);
      delete[] opponent;
    }
  }
}

bool MoveableEntity::move(Map* map, std::string direction) {
  bool validMove = 1;
  // 0=up,1=right,2=down,3=left.
  int surroundings[4];
  surroundings[0] = (map->getMapMatrix())[yPos - 1][xPos];  // above
  surroundings[1] = (map->getMapMatrix())[yPos][xPos + 1];  // to right
  surroundings[2] = (map->getMapMatrix())[yPos + 1][xPos];  // bellow
  surroundings[3] = (map->getMapMatrix())[yPos][xPos - 1];  // to left

  if (!direction.compare("up")) {
    if (surroundings[0] == 0) {
      yPos--;
    } else {
      validMove = 0;
    }
  } else if (!direction.compare("right")) {
    if (surroundings[1] == 0) {
      xPos++;
    } else {
      validMove = 0;
    }
  } else if (!direction.compare("down")) {
    if (surroundings[2] == 0) {
      yPos++;
    } else {
      validMove = 0;
    }
  } else if (!direction.compare("left")) {
    if (surroundings[3] == 0) {
      xPos--;
    } else {
      validMove = 0;
    }
  } else {
    validMove = 0;
  }

  // update;
  this->setPosX(this->xPos);
  this->setPosY(this->yPos);

  return validMove;
}
