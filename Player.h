#ifndef PLAYER_H
#define PLAYER_H 

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "MoveableEntity.h"
// #include "Map.h"

class Player : public MoveableEntity {
 private:
  Sprite appearance;

 public:
  Player(); 
  Player(int _xPos, int _yPos, int damage, int health, int size); 

  void performAction(char action); 

  void move(Map* _map, Event input); 

  void attackOpponent(int opponentPosX, int opponentPosY); 
};

#endif