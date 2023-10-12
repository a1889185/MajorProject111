#ifndef HUDTEST_H
#define HUDTEST_H

#include <iostream>

#include "./HUD.h"
using namespace std;
using namespace sf;

class HUDTest {
 public:
  void runTests() {
    testHealthSetterGetter();
    testEnemiesSetterGetter();
    testScoreSetterGetter();
    testStepsSetterGetter();
    testUpdateStats();
  }

 private:
  void testHealthSetterGetter() {
    HUD hud;
    hud.setHealth(100);
    if (hud.getHealth() != 100) {
      cout << "Test HUD HealthSetterGetter failed!" << endl;
    } else {
      cout << "Test HUD HealthSetterGetter passed!" << endl;
    }
  }

  void testEnemiesSetterGetter() {
    HUD hud;
    hud.setEnemies(3);
    if (hud.getEnemies() != 3) {
      cout << "Test HUD EnemiesSetterGetter failed!" << endl;
    } else {
      cout << "Test HUD EnemiesSetterGetter passed!" << endl;
    }
  }

  void testScoreSetterGetter() {
    HUD hud;
    hud.setScore(50);
    if (hud.getScore() != 50) {
      cout << "Test HUD ScoreSetterGetter failed!" << endl;
    } else {
      cout << "Test HUD ScoreSetterGetter passed!" << endl;
    }
  }

  void testStepsSetterGetter() {
    HUD hud;
    hud.setSteps(10);
    if (hud.getSteps() != 10) {
      cout << "Test HUD StepsSetterGetter failed!" << endl;
    } else {
      cout << "Test HUD StepsSetterGetter passed!" << endl;
    }
  }

  void testUpdateStats() {
    HUD hud;
    hud.updateStats(100, 3, 50, 10);

    if (hud.getHealth() != 100 || hud.getEnemies() != 3 ||
        hud.getScore() != 50 || hud.getSteps() != 10) {
      cout << "Test HUD UpdateStats failed!" << endl;
    } else {
      cout << "Test HUD UpdateStats passed!" << endl;
    }
  }
};

#endif