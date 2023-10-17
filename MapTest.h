#ifndef MAPTEST_H
#define MAPTEST_H

#include "Map.h"
#include <iostream>
using namespace std;
using namespace sf;

class MapTest {
 public:
  void runTests() {
    testIDSetterGetter();
    testNameSetterGetter();
  }

 private:
  void testIDSetterGetter() {
    Map map;
    map.setID(42);
    if (map.getID() != 42) {
      cout << "Failed Map IDSetterGetter Test!" << endl;
    } else {
      cout << "Passed Map IDSetterGetter Test!" << endl;
    }
  }

  void testNameSetterGetter() {
    Map map;
    map.setName("TestMap");
    if (map.getName() != "TestMap") {
      cout << "Failed Map NameSetterGetter Test!" << endl;
    } else {
      cout << "Passed Map NameSetterGetter Test!" << endl;
    }
  }
};

#endif