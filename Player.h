#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// #include "Enemy.h"
#include "Entity.h"
#include "Map.h"
#include "MoveableEntity.h"

using namespace sf;

class Player : public MoveableEntity {
 private:
  Sprite appearance;

 public:
  Player();
  Player(int _xPos, int _yPos);
  Player(int _xPos, int _yPos, int damage, int health, Sprite apperance);

  void attackOpponent(MoveableEntity* opponent);

  // override perform action (one doesnt consider enemies).
  void performAction(Map* map, Clock* keyClock);
  void performAction(Map* map, Clock* keyClock, MoveableEntity** enemies,
                     int numEnemies);
};

#endif