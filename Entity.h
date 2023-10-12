#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
 protected:
  int xPos;
  int yPos;

  sf::Texture texture;
  sf::Sprite sprite;

 public:
  Entity();
  Entity(int _xPos, int _yPos);

  ~Entity();

  virtual int getPosX();
  virtual int getPosY();

  virtual void draw(sf::RenderWindow* window) = 0;
};

#endif  // ENTITY