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
      cout << "getPosX Test: Passed" << endl;
    } else {
      cout << "getPosX Test: Failed" << endl;
    }
  }

  void testGetPosY() {
    MoveableEntity entity(30, 40);
    int posY = entity.getPosY();
    if (posY == 40) {
      cout << "getPosY Test: Passed" << endl;
    } else {
      cout << "getPosY Test: Failed" << endl;
    }
  }

  void testHealthSetterGetter() {
    MoveableEntity entity(10, 10);
    entity.setHealth(80);
    if (entity.getHealth() != 80) {
      cout << "Test HealthSetterGetter failed!" << endl;
    } else {
      cout << "Test HealthSetterGetter passed!" << endl;
    }
  }

  void testDamageSetterGetter() {
    MoveableEntity entity(10, 10);
    entity.setDamage(30);
    if (entity.getDamage() != 30) {
      cout << "Test DamageSetterGetter failed!" << endl;
    } else {
      cout << "Test DamageSetterGetter passed!" << endl;
    }
  }
};

#endif
