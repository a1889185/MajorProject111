#ifndef MOVEABLEENTITY_H
#define MOVEABLEENTITY_H

#include <SFML/Graphics.hpp>

#include "Entity.h"

using namespace sf;

class MoveableEntity : public Entity {
 protected:
  bool playerFlag;

  int size;
  RectangleShape shape;

  int damage;
  int health;

 public:
  MoveableEntity();
  MoveableEntity(int _xPos, int _yPos, int damage, int health, int size);
};

#endif  // MOVEABLEENTITY_H