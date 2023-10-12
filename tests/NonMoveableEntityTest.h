#ifndef NONMOVEABLEENTITYTEST_H
#define NONMOVEABLEENTITYTEST_H 

#include "./NonMoveableEntity.h"
#include <iostream>
using namespace std;
using namespace sf;

class NonMoveableEntityTest {
 public:
  void runTests() {
    testTypeSetterGetter();
  }

 private:
  void testTypeSetterGetter() {
    NonMoveableEntity entity(10, 10, "TestType");
    entity.setType("NewType");
    if (entity.getType() != "NewType") {
      cout << "Test TypeSetterGetter failed!" << endl;
    } else {
      cout << "Test TypeSetterGetter passed!" << endl;
    }
  }
};

#endif