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

void Player::draw(RenderWindow* window) { window->draw(shape); }

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