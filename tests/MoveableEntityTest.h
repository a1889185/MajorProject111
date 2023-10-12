#ifndef MOVEABLEENTITYTEST_H
#define MOVEABLEENTITYTEST_H 

#include "./MoveableEntity.h"
#include <iostream>
using namespace std;

class MoveableEntityTest {
 public:
  void runTests() {
    testHealthSetterGetter();
    testDamageSetterGetter();
  }

 private:
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
