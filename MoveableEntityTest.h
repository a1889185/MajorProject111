#ifndef MOVEABLEENTITYTEST_H
#define MOVEABLEENTITYTEST_H

#include <iostream>

#include "MoveableEntity.h"
using namespace std;

class MoveableEntityTest {
 public:
  void runTests() {
    testGetPosX();
    testGetPosY();
    testHealthSetterGetter();
    testDamageSetterGetter();
  }

 private:
  void testGetPosX() {
    MoveableEntity entity(30, 40, 10, 10);
    int posX = entity.getPosX();
    if (posX == 30) {
      cout << "Test MoveableEntity getPosX passed!" << endl;
    } else {
      cout << "Test MoveableEntity getPosX failed!" << endl;
    }
  }

  void testGetPosY() {
    MoveableEntity entity(30, 40, 10, 10);
    int posY = entity.getPosY();
    if (posY == 40) {
      cout << "Test MoveableEntity getPosY passed!" << endl;
    } else {
      cout << "Test MoveableEntity getPosY failed!" << endl;
    }
  }

  void testHealthSetterGetter() {
    MoveableEntity entity(10, 10, 0, 0);
    entity.setHealth(80);
    if (entity.getHealth() != 80) {
      cout << "Test MoveableEntity HealthSetterGetter failed!" << endl;
    } else {
      cout << "Test MoveableEntity HealthSetterGetter passed!" << endl;
    }
  }

  void testDamageSetterGetter() {
    MoveableEntity entity(10, 10, 0, 0);
    entity.setDamage(30);
    if (entity.getDamage() != 30) {
      cout << "Test MoveableEntity DamageSetterGetter failed!" << endl;
    } else {
      cout << "Test MoveableEntity DamageSetterGetter passed!" << endl;
    }
  }
};

#endif
