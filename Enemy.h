#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Map.h"
#include "MoveableEntity.h"
#include "Player.h"

class Enemy : public MoveableEntity {
 public:
  Enemy();
  Enemy(int _xPos, int _yPos);
  Enemy(int _xPos, int _yPos, int damage, int health);

  void draw(sf::RenderWindow* window);

  void advancePos(Map* map, MoveableEntity* player);
};

#endif