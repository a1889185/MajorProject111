#ifndef HUDTEST_H
#define HUDTEST_H

#include "./HUD.h"
#include <iostream>
using namespace std;
using namespace sf;

class HUDTest {
 public:
  void runTests() {
    testHealthSetterGetter();
    testEnemiesSetterGetter();
    testScoreSetterGetter();
    testStepsSetterGetter();
  }

 private:
  void testHealthSetterGetter() {
    HUD hud;
    hud.setHealth(100);
    if (hud.getHealth() != 100) {
      cout << "Test HealthSetterGetter failed!" << endl;
    } else {
      cout << "Test HealthSetterGetter passed!" << endl;
    }
  }

  void testEnemiesSetterGetter() {
    HUD hud;
    hud.setEnemies(3);
    if (hud.getEnemies() != 3) {
      cout << "Test EnemiesSetterGetter failed!" << endl;
    } else {
      cout << "Test EnemiesSetterGetter passed!" << endl;
    }
  }

  void testScoreSetterGetter() {
    HUD hud;
    hud.setScore(50);
    if (hud.getScore() != 50) {
      cout << "Test ScoreSetterGetter failed!" << endl;
    } else {
      cout << "Test ScoreSetterGetter passed!" << endl;
    }
  }

  void testStepsSetterGetter() {
    HUD hud;
    hud.setSteps(10);
    if (hud.getSteps() != 10) {
      cout << "Test StepsSetterGetter failed!" << endl;
    } else {
      cout << "Test StepsSetterGetter passed!" << endl;
    }
  }
};

#endif