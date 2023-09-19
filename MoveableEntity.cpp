#include "MoveableEntity.h"

#include "Map.h"

MoveableEntity::MoveableEntity() {}
MoveableEntity::MoveableEntity(int _xPos, int _yPos, int damage, int health,
                               int size)
    : xPos(_xPos), yPos(_yPos), damage(damage), health(health) {}

// methods.
void MoveableEntity::setPosX(int _xPos) { this->xPos = _xPos; }
void MoveableEntity::setPosY(int _yPos) { this->yPos = _yPos; }

void MoveableEntity::setHealth(int _health) { this->health = _health; }
void MoveableEntity::setDamage(int _damage) { this->damage = _damage; }

int MoveableEntity::getHealth() { return health; }
int MoveableEntity::getDamage() { return damage; }

void MoveableEntity::move(Map* _map, Event input) {}
void MoveableEntity::attackOpponent(int opponentPosX, int opponentPosY) {}