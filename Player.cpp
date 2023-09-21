#include "Player.h"

Player::Player() : MoveableEntity() {}

Player::Player(int _xPos, int _yPos, int damage, int health, int size)
    : MoveableEntity(_xPos, _yPos, damage, health, size) {}

void Player::attackOpponent(Enemy* opponent) {
  if (opponent != nullptr) {
    // Remove enemy from game
    delete opponent;  // (think this is correct way to do it?)
    opponent = nullptr;
  }
}

void Player::performAction(Map* map, char action, Enemy* enemies,
                           int numEnemies) {
  // Function to handle player actions (user inputs)

  // Get positions of all enemies and store them in arrays
  int* xPos_Enemies = new int[numEnemies];
  int* yPos_Enemies = new int[numEnemies];

  for (int i = 0; i < numEnemies; i++) {
    xPos_Enemies[i] = enemies[i].getPosX();
    yPos_Enemies[i] = enemies[i].getPosY();
  }

  // user inputs
  char move_up = 'W';     // or up arrow key
  char move_down = 'S';   // or down arrow key
  char move_left = 'A';   // or left arrow key
  char move_right = 'D';  // or right arrow key
  char move_wait = ' ';   // space bar for waiting

  switch (action) {
    case move_up:
      // Check if moving up is valid (not into a wall or enemy)
      // If valid, update player's position
      // If there's an enemy, attack it Otherwise, do nothing
      for (int i = 0; i < numEnemies; i++) {
        if (map[xPos][yPos - 1] != 1 && yPos - 1 != yPos_Enemies[i]) {
          setPosY(yPos - 1);  // move player up matrix (increase y position)
        } else if (yPos - 1 == yPos_Enemies[i]) {
          attackOpponent();  // attack nearby enemy
          setPosY(yPos - 1);
        } else {
          setPosY(yPos);  // player remains stationary
        }
      }
      break;

    case move_down:
      // Check if moving down is valid (not into a wall or enemy)
      // If valid, update player's position
      // If there's an enemy, attack it Otherwise, do nothing
      for (int i = 0; i < numEnemies; i++) {
        if (map[xPos][yPos + 1] != 1 && yPos + 1 != yPos_Enemies[i]) {
          setPosY(yPos + 1);  // move player down matrix (decrease y position)
        } else if (yPos + 1 == yPos_Enemies[i]) {
          attackOpponent();  // attack nearby enemy
          setPosY(yPos + 1);
        } else {
          setPosY(yPos);  // player remains stationary
        }
      }
      break;

    case move_left:
      // Check if moving left is valid (not into a wall or enemy)
      // If valid, update player's position
      // If there's an enemy, attack it Otherwise, do nothing
      for (int i = 0; i < numEnemies; i++) {
        if (map[xPos - 1][yPos] != 1 && xPos - 1 != xPos_Enemies[i]) {
          setPosX(xPos - 1);  // move player left (decrease x position)
        } else if (xPos - 1 == xPos_Enemies[i]) {
          attackOpponent();  // attack nearby enemy
          setPosX(xPos - 1);
        } else {
          setPosX(xPos); // player remains stationary
        }
      }
      break;

    case move_right:
      // Check if moving right is valid (not into a wall or enemy)
      // If valid, update player's position
      // If there's an enemy, attack it Otherwise, do nothing
      for (int i = 0; i < numEnemies; i++) {
        if (map[xPos + 1][yPos] != 1 && xPos + 1 != xPos_Enemies[i]) {
          setPosX(xPos + 1);  // move player right (increase x position)
        } else if (xPos + 1 == xPos_Enemies[i]) {
          attackOpponent();  // attack nearby enemy
          setPosX(xPos + 1);
        } else {
          setPosX(xPos); // player remains stationary
        }
      }
      break;

    case move_wait:
      setPosX(xPos);  // player remains stationary
      setPosY(yPos);
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
