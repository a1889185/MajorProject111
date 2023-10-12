#ifndef NONMOVEABLEENTITY_H
#define NONMOVEABLEENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Entity.h"

class NonMoveableEntity : public Entity {
 protected:
  int size;  // standard unit length.

 public:
  NonMoveableEntity();
  NonMoveableEntity(int x, int y, std::string _type);
  NonMoveableEntity(int x, int y, std::string _type, sf::Color _apperance);
  ~NonMoveableEntity();

  sf::RectangleShape getShape();

  std::string getType();
  void setType(std::string _type);

  void draw(sf::RenderWindow* window);

  int getPosX();
  int getPosY();
};

#endif  // NONMOVEABLEENTITY_H