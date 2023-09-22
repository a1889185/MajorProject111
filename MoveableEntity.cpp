#include "MoveableEntity.h"

#include <string>

#include "Entity.h"
#include "Map.h"

MoveableEntity::MoveableEntity() : Entity() {
  this->damage = 0;
  this->health = 0;
  this->size = 0;
}

MoveableEntity::MoveableEntity(int _xPos, int _yPos, int damage, int health,
                               int size)
    : xPos(_xPos), yPos(_yPos), damage(damage), health(health), size(size) {}

// methods.
void MoveableEntity::setPosX(int _xPos) { this->xPos = _xPos; }
void MoveableEntity::setPosY(int _yPos) { this->yPos = _yPos; }

void MoveableEntity::setHealth(int _health) { this->health = _health; }
void MoveableEntity::setDamage(int _damage) { this->damage = _damage; }

int MoveableEntity::getHealth() { return health; }
int MoveableEntity::getDamage() { return damage; }

int MoveableEntity::getPosX() { return xPos; }
int MoveableEntity::getPosY() { return yPos; }

void MoveableEntity::attackOpponent(int opponentPosX, int opponentPosY) {}

bool MoveableEntity::move(Map* map, std::String direction) {
  bool validMove = 1;
  // 0=up,1=right,2=down,3=left.
  int surroundings[4];
  surroundings[0] = (*map)[yPos - 1][xPos];  // above
  surroundings[1] = (*map)[yPos][xPos + 1];  // to right
  surroundings[2] = (*map)[yPos + 1][xPos];  // bellow
  surroundings[3] = (*map)[yPos][xPos - 1];  // to left

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

  return validMove;
}
