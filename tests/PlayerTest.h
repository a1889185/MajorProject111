#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "./Player.h"
#include <iostream>
using namespace std;

class PlayerTest {
 public:
  void runTests() {
    testHealthSetterGetter();
    testDamageSetterGetter();
  }

 private:
  void testHealthSetterGetter() {
    Player player(10, 10);
    player.setHealth(100);
    if (player.getHealth() != 100) {
      cout << "Test HealthSetterGetter failed!" << endl;
    } else {
      cout << "Test HealthSetterGetter passed!" << endl;
    }
  }

  void testDamageSetterGetter() {
    Player player(10, 10);
    player.setDamage(50);
    if (player.getDamage() != 50) {
      cout << "Test DamageSetterGetter failed!" << endl;
    } else {
      cout << "Test DamageSetterGetter passed!" << endl;
    }
  }
};

#endif
