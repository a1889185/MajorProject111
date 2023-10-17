#include "Enemy.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "MoveableEntity.h"
#include "Player.h"

Enemy::Enemy() : MoveableEntity() {
  sf::IntRect area = sf::IntRect();
  if (!texture.loadFromFile("Assets/Enemy.png", area)) {
    std::cout << "Error loading enemy image." << std::endl;
  }
  this->sprite.setTexture(texture);
}
Enemy::Enemy(int _xPos, int _yPos) : MoveableEntity(_xPos, _yPos) {
  sf::IntRect area = sf::IntRect();
  if (!texture.loadFromFile("Assets/Enemy.png", area)) {
    std::cout << "Error loading enemy image." << std::endl;
  }
  this->sprite.setTexture(texture);
}
Enemy::Enemy(int _xPos, int _yPos, int damage, int health)
    : MoveableEntity(_xPos, _yPos, damage, health) {
  sf::IntRect area = sf::IntRect();
  if (!texture.loadFromFile("Assets/Enemy.png", area)) {
    std::cout << "Error loading enemy image." << std::endl;
  }
  this->sprite.setTexture(texture);
}

void Enemy::draw(sf::RenderWindow* window) { window->draw(sprite); }

void Enemy::advancePos(Map* map, MoveableEntity* player) {
  int playerXPos = player->getPosX();
  int playerYPos = player->getPosY();

  int relativeXPos = this->xPos - playerXPos;
  int relativeYPos = this->yPos - playerYPos;

  bool succesfulMove = false;

  // for attacking.
  if (playerXPos + 1 == this->xPos && playerYPos == this->yPos) {
    attackOpponent(player);
    move(map, "right");
  } else if (playerXPos - 1 == this->xPos && playerYPos == this->yPos) {
    attackOpponent(player);
    move(map, "left");
  } else if (playerXPos == this->xPos && playerYPos + 1 == this->yPos) {
    attackOpponent(player);
    move(map, "down");
  } else if (playerXPos == this->xPos && playerYPos - 1 == this->yPos) {
    attackOpponent(player);
    move(map, "up");
  } else if (relativeXPos <= 0 && relativeYPos >= 0) {
    // player above right of enemy.
    // choose direction which has furthest distance between.
    if (abs(relativeXPos) > abs(relativeYPos)) {
      succesfulMove = this->move(map, "right");
    } else {
      succesfulMove = this->move(map, "up");
    }

    // fail case.
    if (!succesfulMove) {
      succesfulMove = this->move(map, "right");
    }
    if (!succesfulMove) {
      succesfulMove = this->move(map, "up");
    }

  } else if (relativeXPos <= 0 && relativeYPos <= 0) {
    // player bellow right of enemy.
    if (abs(relativeXPos) > abs(relativeYPos)) {
      succesfulMove = this->move(map, "right");
    } else {
      succesfulMove = this->move(map, "down");
    }

    if (!succesfulMove) {
      succesfulMove = this->move(map, "right");
    }
    if (!succesfulMove) {
      succesfulMove = this->move(map, "down");
    }

  } else if (relativeXPos >= 0 && relativeYPos <= 0) {
    // player bellow left of enemy.
    if (abs(relativeXPos) > abs(relativeYPos)) {
      succesfulMove = this->move(map, "left");
    } else {
      succesfulMove = this->move(map, "down");
    }

    if (!succesfulMove) {
      succesfulMove = this->move(map, "left");
    }
    if (!succesfulMove) {
      succesfulMove = this->move(map, "down");
    }

  } else if (relativeXPos >= 0 && relativeYPos >= 0) {
    // player above left of enemy.
    if (abs(relativeXPos) > abs(relativeYPos)) {
      succesfulMove = this->move(map, "left");
    } else {
      succesfulMove = this->move(map, "up");
    }

    if (!succesfulMove) {
      succesfulMove = this->move(map, "left");
    }
    if (!succesfulMove) {
      succesfulMove = this->move(map, "up");
    }
  }
}
