#ifndef ENTITY_H
#define ENTITY_H

class Entity {
 protected:
  int xPos;
  int yPos;

 public:
  Entity();
  Entity(int _xPos, int _yPos);

  ~Entity();

  virtual int getPosX();
  virtual int getPosY();
};

#endif  // ENTITY