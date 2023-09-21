#ifndef ENEMY_H
#define ENEMY_H 

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "MoveableEntity.h"
#include "Map.h"
#include "Player.h"

using namespace sf;

class Enemy : public MoveableEntity {

 private:
  Sprite appearance; 

 public:
  Enemy();
  Enemy(int _xPos, int _yPos, int damage, int health, int size);
  
  void attackOpponent(Player* player); 
  void advancePos(Map* map, char action); 
}; 

#endif