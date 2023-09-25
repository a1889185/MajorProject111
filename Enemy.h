#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Map.h"
#include "MoveableEntity.h"
#include "Player.h"

using namespace sf;

class Enemy : public MoveableEntity {
 private:
  Sprite appearance;

 public:
  Enemy();
  Enemy(int _xPos, int _yPos);
  Enemy(int _xPos, int _yPos, int damage, int health, Sprite apperance);

  // void attackOpponent(Player* player);
  void advancePos(Map* map, Player* player);
};

#endif