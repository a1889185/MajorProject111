#ifndef NONMOVEABLEENTITYTEST_H
#define NONMOVEABLEENTITYTEST_H

#include <iostream>
#include "NonMoveableEntity.h"

using namespace std;
using namespace sf;

class NonMoveableEntityTest {
 public:
  void runTests() {
    testGetPosX();
    testGetPosY();
    testTypeSetterGetter();
  }

 private:
  void testGetPosX() {
    NonMoveableEntity entity(30, 40, "TestType");
    int posX = entity.getPosX();
    if (posX == 30) {
      cout << "Passed NonMoveableEntity getPosX Test!" << endl;
    } else {
      cout << "Failed NonMoveableEntity getPosX Test!" << endl;
    }
  }

  void testGetPosY() {
    NonMoveableEntity entity(30, 40, "TestType");
    int posY = entity.getPosY();
    if (posY == 40) {
      cout << "Passed NonMoveableEntity getPosY Test!" << endl;
    } else {
      cout << "Failed NonMoveableEntity getPosY Test!" << endl;
    }
  }

  void testTypeSetterGetter() {
    NonMoveableEntity entity(10, 10, "TestType");
    entity.setType("NewType");
    if (entity.getType() != "NewType") {
      cout << "Failed NonMoveableEntity TypeSetterGetter Test!" << endl;
    } else {
      cout << "Passed NonMoveableEntity TypeSetterGetter Test!" << endl;
    }
  }
};

#endif