#ifndef NONMOVEABLEENTITYTEST_H
#define NONMOVEABLEENTITYTEST_H

#include <iostream>

#include "./NonMoveableEntity.h"
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

  void testTypeSetterGetter() {
    NonMoveableEntity entity(10, 10, "TestType");
    entity.setType("NewType");
    if (entity.getType() != "NewType") {
      cout << "Test TypeSetterGetter failed!" << endl;
    } else {
      cout << "Test TypeSetterGetter passed!" << endl;
    }
  }

  void testShapeGetter() {
    NonMoveableEntity entity(10, 10, "Obstacle");
    sf::RectangleShape shape = entity.getShape();

    // Verify that the shape properties are as expected
    if (shape.getSize() != sf::Vector2f(42, 42)) {
      std::cout << "Test ShapeGetter failed: Incorrect size!" << std::endl;
    } else if (shape.getPosition() != sf::Vector2f(10, 10)) {
      std::cout << "Test ShapeGetter failed: Incorrect position!" << std::endl;
    } else {
      std::cout << "Test ShapeGetter passed!" << std::endl;
    }
  }
};

#endif