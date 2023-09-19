#include "MoveableEntity.h"

#include "Map.h"

MoveableEntity::MoveableEntity() {}
MoveableEntity::MoveableEntity(int _xPos, int _yPos, int damage, int health,
                               int size) {}

// methods.
void MoveableEntity::setPosX(int Xpos) {}
void MoveableEntity::setPosY(int Ypos) {}

void MoveableEntity::setHealth(int health) {}
void MoveableEntity::setDamage(int damage) {}

int MoveableEntity::getHealth() {}
int MoveableEntity::getDamage() {}

void MoveableEntity::move(Map* _map, Event input) {}
void MoveableEntity::attackOpponent(int opponentPosX, int opponentPosY) {}