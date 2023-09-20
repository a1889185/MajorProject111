#include "Player.h"

Player::Player() : MoveableEntity() {}

Player::Player(int _xPos, int _yPos, int damage, int health, int size)
    : MoveableEntity(_xPos, _yPos, damage, health, size) {}

void Player::performAction(char action) { // Function to handle player actions (user inputs)
  // user inputs
  char move_up = 'W';     // or up arrow key
  char move_down = 'S';   // or down arrow key
  char move_left = 'A';   // or left arrow key
  char move_right = 'D';  // or right arrow key
  char move_wait = ' ';   // space bar for waiting

  switch (action) {
    case move_up:
      // Check if moving up is valid (not into a wall, player or out of bounds
      // (if walls are not 1s) ) If valid, update player's position If there's
      // an enemy, attack it Otherwise, do nothing
      if (yPos >= 0 && map[xPos][yPos + 1] != 1 && yPos + 1 != yPos_Enemy) {
        yPos++;  // move player up (increase y position)
      } else if (yPos + 1 == yPos_Enemy) {
        attackOpponent();  // attack nearby enemy
      } else {
        yPos = yPos;  // player remains stationary
      }

      break;

    case move_down:
      // Check if moving down is valid (not into a wall, player or out of bounds
      // (if walls are not 1s) ) If valid, update player's position If there's
      // an enemy, attack it Otherwise, do nothing
      if (yPos > 0 && map[xPos][yPos - 1] != 1 && yPos - 1 != yPos_Enemy) {
        yPos--;  // move player down (decrease y position)
      } else if (yPos - 1 == yPos_Enemy) {
        attackOpponent();  // attack nearby enemy
      } else {
        yPos = yPos;  // player remains stationary
      }

      break;

    case move_left:
      // Check if moving left is valid (not into a wall, player or out of bounds
      // (if walls are not 1s) ) If valid, update player's position If there's
      // an enemy, attack it Otherwise, do nothing
      if (xPos > 0 && map[xPos - 1][yPos] != 1 && xPos - 1 != xPos_Enemy) {
        xPos--;  // move player left (decrease x position)
      } else if (xPos - 1 == xPos_Enemy) {
        attackOpponent();  // attack nearby enemy
      } else {
        xPos = xPos;  // player remains stationary
      }

      break;

    case move_right:
      // Check if moving right is valid (not into a wall, player or out of
      // bounds (if walls are not 1s) ) If valid, update player's position If
      // there's an enemy, attack it Otherwise, do nothing
      if (xPos > 0 && map[xPos + 1][yPos] != 1 && xPos + 1 != xPos_Enemy) {
        xPos++;  // move player right (increase x position)
      } else if (xPos + 1 == xPos_Enemy) {
        attackOpponent();  // attack nearby enemy
      } else {
        xPos = xPos;  // player remains stationary
      }

      break;

    case move_wait:
      xPos = xPos;  // player remains stationary
      break;

    default:
      // Print an error message for invalid input
      std::cout << "Invalid input. Please use: "
                << "'W'"
                << ", "
                << "'S'"
                << ", "
                << "'A'"
                << ", "
                << "'D'"
                << ", or "
                << "Space bar"
                << "." << std::endl;
      break;
  }
}
