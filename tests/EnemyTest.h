#ifndef ENEMYTEST_H
#define ENEMYTEST_H

#include "./Enemy.h"
#include <iostream>
using namespace std;

class EnemyTest {
 public:
  void runTests() {
    testHealthSetterGetter();
    testDamageSetterGetter();
  }

 private:
  void testHealthSetterGetter() {
    Enemy enemy(10, 10);
    enemy.setHealth(80);
    if (enemy.getHealth() != 80) {
      cout << "Test HealthSetterGetter failed!" << endl;
    } else {
      cout << "Test HealthSetterGetter passed!" << endl;
    }
  }

  void testDamageSetterGetter() {
    Enemy enemy(10, 10);
    enemy.setDamage(30);
    if (enemy.getDamage() != 30) {
      cout << "Test DamageSetterGetter failed!" << endl;
    } else {
      cout << "Test DamageSetterGetter passed!" << endl;
    }
  }
};

#endif