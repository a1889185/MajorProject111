#ifndef NONMOVEABLEENTITY_H
#define NONMOVEABLEENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Entity.h"

class NonMoveableEntity : public Entity {
 protected:
  int size;  // standard unit length.
<<<<<<< HEAD
=======
  std::string type;
>>>>>>> c2f2cae5f95135506b436369c480e9e120c58c60

 public:
  NonMoveableEntity();
  NonMoveableEntity(int x, int y, std::string _type);
  NonMoveableEntity(int x, int y, std::string _type, sf::Texture _texture);
  ~NonMoveableEntity();

  sf::Sprite getShape();

  std::string getType();
  void setType(std::string _type);

  void draw(sf::RenderWindow* window);

  int getPosX();
  int getPosY();
};

#endif  // NONMOVEABLEENTITY_H