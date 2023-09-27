#include "Player.h"

#include <SFML/Graphics.hpp>
#include <string>

#include "Map.h"
#include "MoveableEntity.h"

using namespace sf;

Player::Player() : MoveableEntity() {}
Player::Player(int _xPos, int _yPos) : MoveableEntity(_xPos, _yPos) {}
Player::Player(int _xPos, int _yPos, int damage, int health, Color _apperance)
    : MoveableEntity(_xPos, _yPos, damage, health) {
  this->apperance = _apperance;
  this->shape.setFillColor(apperance);
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

    } else if (Keyboard::isKeyPressed(Keyboard::Space)) {
      actionPerformed = 1;
    }

    keyClock->restart();  // Reset the clock for the next delay
  }
  return actionPerformed;
}

const int isEnemyinPlayerPosition(Player tempPlayer, MoveableEntity** enemies,
                                  int numEnemies) {
  int j = -1;
  for (int i = 0; i < numEnemies; i++) {
    if (enemies[i]->getHealth() != 0 &&
        tempPlayer.getPosX() == enemies[i]->getPosX() &&
        tempPlayer.getPosY() == enemies[i]->getPosY()) {
      j = i;
      break;
    }
  }
  // return -1 if no enemies adjacent.
  // or return index of enemy that is adjacent.
  return j;
}

bool Player::performAction(Map* map, Clock* keyClock, MoveableEntity** enemies,
                           int numEnemies) {
  // Function to handle player actions (user inputs)
  bool actionPerformed = 0;
  // new temp player to make the desired move before real player.
  Player tempPlayer(this->xPos, this->yPos);

  // The clock sets a delay between each key input so it doesnt have a spaz.
  int refreshRate = 100;  // for key inputs.
  if (keyClock->getElapsedTime().asMilliseconds() >= refreshRate) {
    if (Keyboard::isKeyPressed(Keyboard::W)) {
      tempPlayer.move(map, "up");
      int enemyIndex = isEnemyinPlayerPosition(tempPlayer, enemies, numEnemies);

      if (enemyIndex == -1) {  // no enemy case.
        actionPerformed = this->move(map, "up");
      } else {  // enemy in position case.
        attackOpponent(enemies[enemyIndex]);
        actionPerformed = this->move(map, "up");
      }

    } else if (Keyboard::isKeyPressed(Keyboard::A)) {
      tempPlayer.move(map, "left");
      int enemyIndex = isEnemyinPlayerPosition(tempPlayer, enemies, numEnemies);

      if (enemyIndex == -1) {  // no enemy case.
        actionPerformed = this->move(map, "left");
      } else {  // enemy in position case.
        attackOpponent(enemies[enemyIndex]);
        actionPerformed = this->move(map, "left");
      }

    } else if (Keyboard::isKeyPressed(Keyboard::S)) {
      tempPlayer.move(map, "down");
      int enemyIndex = isEnemyinPlayerPosition(tempPlayer, enemies, numEnemies);

      if (enemyIndex == -1) {
        actionPerformed = this->move(map, "down");
      } else {  // enemy in position case.
        attackOpponent(enemies[enemyIndex]);
        actionPerformed = this->move(map, "down");
      }

    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
      tempPlayer.move(map, "right");
      int enemyIndex = isEnemyinPlayerPosition(tempPlayer, enemies, numEnemies);

      if (enemyIndex == -1) {  // no enemy case.
        actionPerformed = this->move(map, "right");
      } else {  // enemy in position case.
        attackOpponent(enemies[enemyIndex]);
        actionPerformed = this->move(map, "right");
      }

    } else if (Keyboard::isKeyPressed(Keyboard::Space)) {
      actionPerformed = 1;
    }

    keyClock->restart();  // Reset the clock for the next delay
  }

  return actionPerformed;
}

//
//
//
//

// void Player::performAction(Map* map, char action, Enemy* aliveEnemies,
//                            int j) {
//   // Function to handle player actions (user inputs)

//   // Get positions of all aliveEnemies and store them in arrays
//   int* xPos_aliveEnemies = new int[j];
//   int* yPos_aliveEnemies = new int[j];

//   for (int i = 0; i < j; i++) {
//     xPos_aliveEnemies[i] = aliveEnemies[i].getPosX();
//     yPos_aliveEnemies[i] = aliveEnemies[i].getPosY();
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
//       for (int i = 0; i < j; i++) {
//         if (yPos - 1 == yPos_aliveEnemies[i]) {
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
//       for (int i = 0; i < j; i++) {
//         if (yPos + 1 == yPos_aliveEnemies[i]) {
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
//       for (int i = 0; i < j; i++) {
//         if (xPos - 1 == xPos_aliveEnemies[i]) {
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
//       for (int i = 0; i < j; i++) {
//         if (xPos + 1 == xPos_aliveEnemies[i]) {
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

//   delete[] xPos_aliveEnemies;
//   delete[] yPos_aliveEnemies;
// }