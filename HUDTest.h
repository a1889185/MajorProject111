#ifndef HUDTEST_H
#define HUDTEST_H

#include <iostream>
#include "HUD.h"

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
      cout << "Failed HUD HealthSetterGetter Test!" << endl;
    } else {
      cout << "Passed HUD HealthSetterGetter Test!" << endl;
    }
  }

  void testEnemiesSetterGetter() {
    HUD hud;
    hud.setEnemies(3);
    if (hud.getEnemies() != 3) {
      cout << "Failed HUD EnemiesSetterGetter Test!" << endl;
    } else {
      cout << "Passed HUD EnemiesSetterGetter Test!" << endl;
    }
  }

  void testScoreSetterGetter() {
    HUD hud;
    hud.setScore(50);
    if (hud.getScore() != 50) {
      cout << "Failed HUD ScoreSetterGetter Test!" << endl;
    } else {
      cout << "Passed HUD ScoreSetterGetter Test!" << endl;
    }
  }

  void testStepsSetterGetter() {
    HUD hud;
    hud.setSteps(10);
    if (hud.getSteps() != 10) {
      cout << "Failed HUD StepsSetterGetter Test!" << endl;
    } else {
      cout << "Passed HUD StepsSetterGetter Test!" << endl;
    }
  }

  void testUpdateStats() {
    HUD hud;
    hud.updateStats(100, 3, 50, 10);

    if (hud.getHealth() != 100 || hud.getEnemies() != 3 ||
        hud.getScore() != 50 || hud.getSteps() != 10) {
      cout << "Failed HUD UpdateStats Test!" << endl;
    } else {
      cout << "Passed HUD UpdateStats Test!" << endl;
    }
  }
};

#endif