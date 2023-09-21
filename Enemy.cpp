#include "Enemy.h"

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

void Enemy::advancePos(Map* map, char action);

// user inputs (same as for player because dependent on player movement)
// attempts to move one step closer to player and eventually attack player
char move_up = 'W';     // or up arrow key
char move_down = 'S';   // or down arrow key
char move_left = 'A';   // or left arrow key
char move_right = 'D';  // or right arrow key
char move_wait = ' ';   // space bar for waiting

switch (action) {
  case move_up:
    // If player moves up, enemy attempts to move down 1 step closer to player
    // Check if moving down is valid (not into a wall or player)
    // If valid, update enemy's position
    // If there's a player, attack it Otherwise, do nothing
    if (map[xPos][yPos + 1] != 1 && yPos + 1 != yPos_Player) {
      yPos++;  // move enemy down matrix (decrease y position)
    } else if (yPos + 1 == yPos_Player) {
      attackOpponent();  // attack nearby player
    } else {
      yPos = yPos;  // enemy remains stationary
    }
    break;

  case move_down:
    // If player moves down, enemy attempts to move up 1 step closer to player
    // Check if moving up is valid (not into a wall or player)
    // If valid, update enemy's position
    // If there's a player, attack it Otherwise, do nothing
    if (map[xPos][yPos - 1] != 1 && yPos - 1 != yPos_Player) {
      yPos--;  // move enemy up matrix (increase y position)
    } else if (yPos - 1 == yPos_Player) {
      attackOpponent();  // attack nearby player
    } else {
      yPos = yPos;  // enemy remains stationary
    }
    break;

  case move_left:
    // If player moves left, enemy attempts to move right 1 step closer to
    // player Check if moving right is valid (not into a wall or player) If valid,
    // update enemy's position If there's a player, attack it Otherwise, do
    // nothing
    if (map[xPos + 1][yPos] != 1 && xPos + 1 != xPos_Player) {
      xPos++;  // move enemy right (increase x position)
    } else if (xPos + 1 == xPos_Player) {
      attackOpponent();  // attack nearby player
    } else {
      xPos = xPos;  // enemy remains stationary
    }
    break;

  case move_right:
    // If player moves right, enemy attempts to move left 1 step closer to
    // player Check if moving left is valid (not into a wall or enemy) If
    // valid, update player's position If there's a player, attack it Otherwise,
    // do nothing
    if (map[xPos - 1][yPos] != 1 && xPos - 1 != xPos_Player) {
      xPos--;  // move enemy left (decrease x position)
    } else if (xPos - 1 == xPos_Player) {
      attackOpponent();  // attack nearby player
    } else {
      xPos = xPos;  // enemy remains stationary
    }
    break;

  case move_wait:
    xPos = xPos;  // enemy remains stationary
    yPos = yPos;
    break;
}