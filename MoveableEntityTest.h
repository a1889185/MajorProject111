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
      cout << "Passed MoveableEntity getPosX Test!" << endl;
    } else {
      cout << "Failed MoveableEntity getPosX Test!" << endl;
    }
  }

  void testGetPosY() {
    MoveableEntity entity(30, 40, 10, 10);
    int posY = entity.getPosY();
    if (posY == 40) {
      cout << "Passed MoveableEntity getPosY Test!" << endl;
    } else {
      cout << "Failed MoveableEntity getPosY Test!" << endl;
    }
  }

  void testHealthSetterGetter() {
    MoveableEntity entity(10, 10, 0, 0);
    entity.setHealth(80);
    if (entity.getHealth() != 80) {
      cout << "Failed MoveableEntity HealthSetterGetter Test!" << endl;
    } else {
      cout << "Passed MoveableEntity HealthSetterGetter Test!" << endl;
    }
  }

  void testDamageSetterGetter() {
    MoveableEntity entity(10, 10, 0, 0);
    entity.setDamage(30);
    if (entity.getDamage() != 30) {
      cout << "Failed MoveableEntity DamageSetterGetter Test!" << endl;
    } else {
      cout << "Passed MoveableEntity DamageSetterGetter Test!" << endl;
    }
  }
};

#endif
