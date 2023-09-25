#include "Player.h"

#include <SFML/Graphics.hpp>
#include <string>

#include "Map.h"
#include "MoveableEntity.h"

using namespace sf;

Player::Player() : MoveableEntity() {}
Player::Player(int _xPos, int _yPos) : MoveableEntity(_xPos, _yPos) {}
Player::Player(int _xPos, int _yPos, int damage, int health, Sprite _apperance)
    : MoveableEntity(_xPos, _yPos, damage, health) {
  this->appearance = _apperance;
  // this->shape.setTexture(appereance);
}

void Player::attackOpponent(MoveableEntity* opponent) {
  if (opponent != nullptr) {
    // Remove enemy from game
    delete opponent;  // (think this is correct way to do it?)
  }
}

bool Player::performAction(Map* map, Clock* keyClock) {
  bool actionPerformed = 0;
  // The clock sets a delay after each key input so it doesnt have a spaz.
  int refreshRate = 100;  // for key inputs.
  if (keyClock->getElapsedTime().asMilliseconds() >= refreshRate) {
    if (Keyboard::isKeyPressed(Keyboard::W)) {
      actionPerformed = this->move(map, "up");

    } else if (Keyboard::isKeyPressed(Keyboard::A)) {
      actionPerformed = this->move(map, "left");

    } else if (Keyboard::isKeyPressed(Keyboard::S)) {
      actionPerformed = this->move(map, "down");

    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
      actionPerformed = this->move(map, "right");
    }
    keyClock->restart();  // Reset the clock for the next delay
  }
  return actionPerformed;
}

bool Player::performAction(Map* map, Clock* keyClock, MoveableEntity** enemies,
                           int numEnemies) {
  // Function to handle player actions (user inputs)
  bool actionPerformed = 0;

  // Get positions of all enemies and store them in arrays
  int* xPos_Enemies = new int[numEnemies];
  int* yPos_Enemies = new int[numEnemies];

  for (int i = 0; i < numEnemies; i++) {
    xPos_Enemies[i] = enemies[i]->getPosX();
    yPos_Enemies[i] = enemies[i]->getPosY();
  }

  // The clock sets a delay between each key input so it doesnt have a spaz.
  if (keyClock->getElapsedTime().asMilliseconds() >= 200) {
    if (Keyboard::isKeyPressed(Keyboard::W)) {
      // Check if moving up is valid (not into a enemy)
      for (int i = 0; i < numEnemies; i++) {
        if (yPos - 1 == yPos_Enemies[i]) {
          // attackOpponent();  // attack nearby enemy
          actionPerformed = this->move(map, "up");
          break;  // Break out of loop after attacking enemy
        } else {
          actionPerformed = this->move(map, "up");
        }
      }

    } else if (Keyboard::isKeyPressed(Keyboard::A)) {
      // Check if moving left is valid (not a enemy)
      for (int i = 0; i < numEnemies; i++) {
        if (xPos - 1 == xPos_Enemies[i]) {
          // attackOpponent();
          actionPerformed = this->move(map, "left");
          break;

        } else {
          actionPerformed = this->move(map, "left");
        }
      }

    } else if (Keyboard::isKeyPressed(Keyboard::S)) {
      // Check if moving down is valid (not a enemy)
      for (int i = 0; i < numEnemies; i++) {
        if (yPos + 1 == yPos_Enemies[i]) {
          // attackOpponent();
          actionPerformed = this->move(map, "down");
          break;

        } else {
          actionPerformed = this->move(map, "down");
        }
      }

    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
      // Check if moving right is valid (not a enemy)
      for (int i = 0; i < numEnemies; i++) {
        if (xPos + 1 == xPos_Enemies[i]) {
          // attackOpponent();
          actionPerformed = this->move(map, "right");
          break;

        } else {
          actionPerformed = this->move(map, "right");
        }
      }
    } else {
      int i = 69;
    }

    // case move_wait:
    //   setPosX(xPos);  // player remains stationary
    //   setPosY(yPos);
    //   break;

    // default:
    //   // Print an error message for invalid input
    //   std::cout << "Invalid input. Please use: "
    //             << "'W'"
    //             << ", "
    //             << "'S'"
    //             << ", "
    //             << "'A'"
    //             << ", "
    //             << "'D'"
    //             << ", or "
    //             << "Space bar"
    //             << "." << std::endl;
    //   break;

    keyClock->restart();  // Reset the clock for the next delay
  }

  delete[] xPos_Enemies;
  delete[] yPos_Enemies;

  return actionPerformed;
}

// void Player::performAction(Map* map, char action, Enemy* enemies,
//                            int numEnemies) {
//   // Function to handle player actions (user inputs)

//   // Get positions of all enemies and store them in arrays
//   int* xPos_Enemies = new int[numEnemies];
//   int* yPos_Enemies = new int[numEnemies];

//   for (int i = 0; i < numEnemies; i++) {
//     xPos_Enemies[i] = enemies[i].getPosX();
//     yPos_Enemies[i] = enemies[i].getPosY();
//   }

//   // user inputs
//   char move_up = 'W';     // or up arrow key
//   char move_down = 'S';   // or down arrow key
//   char move_left = 'A';   // or left arrow key
//   char move_right = 'D';  // or right arrow key
//   char move_wait = ' ';   // space bar for waiting

//   switch (action) {
//     case move_up:

//       // Initialize a flag to check if a position contains an enemy
//       int isEnemyPosition = 0;

//       // Check if moving up is valid (not into a wall or enemy)
//       for (int i = 0; i < numEnemies; i++) {
//         if (yPos - 1 == yPos_Enemies[i]) {
//           // yPos - 1 is an enemy position
//           isEnemyPosition = 1;
//           attackOpponent();  // attack nearby enemy
//           setPosY(yPos - 1);
//           break;  // Break out of loop after attacking enemy
//         }
//       }

//       // If yPos - 1 is not an enemy position and not a wall, move player
//       up if (!isEnemyPosition && map[xPos][yPos - 1] != 1) {
//         setPosY(yPos - 1);  // move player up matrix (increase y position)
//       }
//       break;

//     case move_down:

//       // Initialize a flag to check if a position contains an enemy
//       int isEnemyPosition = 0;

//       // Check if moving down is valid (not into a wall or enemy)
//       for (int i = 0; i < numEnemies; i++) {
//         if (yPos + 1 == yPos_Enemies[i]) {
//           // yPos + 1 is an enemy position
//           isEnemyPosition = 1;
//           attackOpponent();  // attack nearby enemy
//           setPosY(yPos + 1);
//           break;  // Break out of loop after attacking enemy
//         }
//       }

//       // If yPos + 1 is not an enemy position and not a wall, move player
//       down if (!isEnemyPosition && map[xPos][yPos + 1] != 1) {
//         setPosY(yPos + 1);  // move player down matrix (decrease y
//         position)
//       }
//       break;

//     case move_left:

//       // Initialize a flag to check if a position contains an enemy
//       int isEnemyPosition = 0;

//       // Check if moving left is valid (not into a wall or enemy)
//       for (int i = 0; i < numEnemies; i++) {
//         if (xPos - 1 == xPos_Enemies[i]) {
//           // xPos - 1 is an enemy position
//           isEnemyPosition = 1;
//           attackOpponent();  // attack nearby enemy
//           setPosY(xPos - 1);
//           break;  // Break out of loop after attacking enemy
//         }
//       }

//       // If xPos - 1 is not an enemy position and not a wall, move player
//       left if (!isEnemyPosition && map[xPos - 1][yPos] != 1) {
//         setPosY(xPos - 1);  // move player left (decrease x position)
//       }
//       break;

//     case move_right:

//       // Initialize a flag to check if a position contains an enemy
//       int isEnemyPosition = 0;

//       // Check if moving right is valid (not into a wall or enemy)
//       for (int i = 0; i < numEnemies; i++) {
//         if (xPos + 1 == xPos_Enemies[i]) {
//           // xPos + 1 is an enemy position
//           isEnemyPosition = 1;
//           attackOpponent();  // attack nearby enemy
//           setPosY(xPos + 1);
//           break;  // Break out of loop after attacking enemy
//         }
//       }

//       // If xPos + 1 is not an enemy position and not a wall, move player
//       right if (!isEnemyPosition && map[xPos + 1][yPos] != 1) {
//         setPosY(xPos + 1);  // move player right (increase x position)
//       }
//       break;

//     case move_wait:
//       setPosX(xPos);  // player remains stationary
//       setPosY(yPos);
//       break;

//     default:
//       // Print an error message for invalid input
//       std::cout << "Invalid input. Please use: "
//                 << "'W'"
//                 << ", "
//                 << "'S'"
//                 << ", "
//                 << "'A'"
//                 << ", "
//                 << "'D'"
//                 << ", or "
//                 << "Space bar"
//                 << "." << std::endl;
//       break;
//   }

//   delete[] xPos_Enemies;
//   delete[] yPos_Enemies;
// }
