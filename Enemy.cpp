#include "Enemy.h"

#include "MoveableEntity.h"

Enemy::Enemy() : MoveableEntity() {}

Enemy::Enemy(int _xPos, int _yPos, int damage, int health, int size)
    : MoveableEntity(_xPos, _yPos, damage, health, size) {}

void Enemy::attackOpponent(Player* player) {
  // Check if enemy can attack player based on position
  if (xPos == player->getPosX() && yPos == player->getPosY()) {
    // enemy can attack player, so remove player from game
    delete player;  // delete the player object
    cout << "GAME OVER!"
         << endl;  // print game over message dont know how to do in sfml
  }
}

void Enemy::advancePos(Map* map, char action) {}
