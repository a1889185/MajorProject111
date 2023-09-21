#ifndef PLAYER_H
#define PLAYER_H 

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "MoveableEntity.h"
#include "Map.h"
#include "Enemy.h"

using namespace sf;

class Player : public MoveableEntity {

 private:
  Sprite appearance;

 public:
  Player(); 
  Player(int _xPos, int _yPos, int damage, int health, int size);
  
  void attackOpponent(Enemy* opponent);
  void performAction(Map* map, char action, Enemy* enemies, int numEnemies); 
};

#endif