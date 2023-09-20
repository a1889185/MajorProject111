#include "Enemy.h"

Enemy::Enemy() : MoveableEntity() {}

Enemy::Enemy(int _xPos, int _yPos, int damage, int health, int size)
    : MoveableEntity(_xPos, _yPos, damage, health, size) {}

