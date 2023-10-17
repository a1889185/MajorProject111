#ifndef MOVEABLEENTITY_H
#define MOVEABLEENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Entity.h"
#include "Map.h"

class MoveableEntity : public Entity {
 protected:
  bool playerFlag;

  int size;  // 42.

  int damage;
  int health;

 public:
  MoveableEntity();
  MoveableEntity(int _xPos, int _yPos);
  MoveableEntity(int _xPos, int _yPos, int damage, int health);

  // methods.

  void setPosX(int _xPos);
  void setPosY(int _yPos);

  virtual void setHealth(int health);
  virtual void setDamage(int damage);

  virtual int getHealth();
  virtual int getDamage();

  int getPosX();
  int getPosY();

  void draw(sf::RenderWindow* window);

  virtual bool performAction(Map* map, sf::Clock* keyClock,
                             MoveableEntity** enemies, int numEnemies);
  virtual void advancePos(Map* map, MoveableEntity* player);

  // return 0 if unvalid move. Direction strings: "up" "left" "right" "down"
  bool move(Map* map, std::string direction);
  virtual void attackOpponent(MoveableEntity* opponent);
};

#endif  // MOVEABLEENTITY_H