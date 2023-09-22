#ifndef MOVEABLEENTITY_H
#define MOVEABLEENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Entity.h"
#include "Map.h"

using namespace sf;

class MoveableEntity : public Entity {
 protected:
  bool playerFlag;

  int size;  // 42.
  RectangleShape shape;

  int damage;
  int health;

 public:
  MoveableEntity();
  MoveableEntity(int _xPos, int _yPos, int damage, int health, int size);

  // methods.

  void setPosX(int _xPos);
  void setPosY(int _yPos);

  virtual void setHealth(int health);
  virtual void setDamage(int damage);

  virtual int getHealth();
  virtual int getDamage();

  int getPosX();
  int getPosY();

  // return 0 if not valid move. Directions can be: "up" "left" "right" "down"
  bool move(Map* map, std::String direction);
  virtual void attackOpponent(int opponentPosX, int opponentPosY);
};

#endif  // MOVEABLEENTITY_H