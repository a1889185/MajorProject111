#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
 protected:
  int xPos;
  int yPos;

 public:
  Texture texture;
  Sprite sprite;
  Entity();
  Entity(int _xPos, int _yPos);

  ~Entity();

  virtual int getPosX();
  virtual int getPosY();

  virtual void draw(sf::RenderWindow* window) = 0;
};

#endif  // ENTITY