#ifndef MOVEABLEENTITY_H
#define MOVEABLEENTITY_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
// #include "Map.h"

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

  // methods.

  void setPosX(int Xpos);
  void setPosY(int Ypos);

  virtual void setHealth(int health);
  virtual void setDamage(int damage);

  virtual int getHealth();
  virtual int getDamage();

  virtual void move(Map* _map, Event input);
  virtual void attackOpponent(int opponentPosX, int opponentPosY);
};

#endif  // MOVEABLEENTITY_H