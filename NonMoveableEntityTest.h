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
    testShapeGetter();
  }

 private:
  void testGetPosX() {
    NonMoveableEntity entity(30, 40, "TestType");
    int posX = entity.getPosX();
    if (posX == 30) {
      cout << "NonMoveableEntity getPosX Test: Passed" << endl;
    } else {
      cout << "NonMoveableEntity getPosX Test: Failed" << endl;
    }
  }

  void testGetPosY() {
    NonMoveableEntity entity(30, 40, "TestType");
    int posY = entity.getPosY();
    if (posY == 40) {
      cout << "NonMoveableEntity getPosY Test: Passed" << endl;
    } else {
      cout << "NonMoveableEntity getPosY Test: Failed" << endl;
    }
  }

  void testTypeSetterGetter() {
    NonMoveableEntity entity(10, 10, "TestType");
    entity.setType("NewType");
    if (entity.getType() != "NewType") {
      cout << "Test NonMoveableEntity TypeSetterGetter failed!" << endl;
    } else {
      cout << "Test NonMoveableEntity TypeSetterGetter passed!" << endl;
    }
  }

  void testShapeGetter() {
    NonMoveableEntity entity(10, 10, "Obstacle");
    RectangleShape shape = entity.getShape();

    // Verify that the shape properties are as expected
    if (shape.getSize() != sf::Vector2f(42, 42)) {
      cout << "Test NonMoveableEntity ShapeGetter failed: Incorrect size!" << endl;
    } else if (shape.getPosition() != sf::Vector2f(10, 10)) {
      cout << "Test NonMoveableEntity ShapeGetter failed: Incorrect position!" << endl;
    } else {
      cout << "Test NonMoveableEntity ShapeGetter passed!" << endl;
    }
  }
};

#endif