#ifndef MOVEABLEENTITYTEST_H
#define MOVEABLEENTITYTEST_H

#include <iostream>

#include "./MoveableEntity.h"
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
    MoveableEntity entity(30, 40);
    int posX = entity.getPosX();
    if (posX == 30) {
      cout << "MoveableEntity getPosX Test: Passed" << endl;
    } else {
      cout << "MoveableEntity getPosX Test: Failed" << endl;
    }
  }

  void testGetPosY() {
    MoveableEntity entity(30, 40);
    int posY = entity.getPosY();
    if (posY == 40) {
      cout << "MoveableEntity getPosY Test: Passed" << endl;
    } else {
      cout << "MoveableEntity getPosY Test: Failed" << endl;
    }
  }

  void testHealthSetterGetter() {
    MoveableEntity entity(10, 10);
    entity.setHealth(80);
    if (entity.getHealth() != 80) {
      cout << "Test MoveableEntity HealthSetterGetter failed!" << endl;
    } else {
      cout << "Test MoveableEntity HealthSetterGetter passed!" << endl;
    }
  }

  void testDamageSetterGetter() {
    MoveableEntity entity(10, 10);
    entity.setDamage(30);
    if (entity.getDamage() != 30) {
      cout << "Test MoveableEntity DamageSetterGetter failed!" << endl;
    } else {
      cout << "Test MoveableEntity DamageSetterGetter passed!" << endl;
    }
  }
};

#endif
