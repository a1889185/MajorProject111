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
  Color apperance;
  Texture playerTexture;
  Sprite playerSprite;

 public:
  Player();
  Player(int _xPos, int _yPos);
  Player(int _xPos, int _yPos, int damage, int health);

  void draw(sf::RenderWindow* window);

  // override perform action (one doesnt consider enemies). return true if
  // action performed;
  bool performAction(Map* map, Clock* keyClock);
  bool performAction(Map* map, Clock* keyClock, MoveableEntity** enemies,
                     int numEnemies);
};

#endif