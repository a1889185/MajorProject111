#ifndef ENEMYTEST_H
#define ENEMYTEST_H

#include "Enemy.h"
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
      cout << "Failed Enemy HealthSetterGetter Test!" << endl;
    } else {
      cout << "Passed Enemy HealthSetterGetter Test!" << endl;
    }
  }

  void testDamageSetterGetter() {
    Enemy enemy(10, 10);
    enemy.setDamage(30);
    if (enemy.getDamage() != 30) {
      cout << "Failed Enemy DamageSetterGetter Test!" << endl;
    } else {
      cout << "Passed Enemy DamageSetterGetter Test!" << endl;
    }
  }
};

#endif