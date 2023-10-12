#ifndef MAPTEST_H
#define MAPTEST_H

#include "./Map.h"
#include <iostream>
using namespace std;
using namespace sf;

class MapTest {
 public:
  void runTests() {
    testMapSizeSetterGetter();
    testMapDensitySetterGetter();
    testIDSetterGetter();
    testNameSetterGetter();
  }

 private:
  void testMapSizeSetterGetter() {
    Map map;
    map.setMapSize(30);
    if (map.getMapSize() != 30) {
      cout << "Test MapSizeSetterGetter failed!" << endl;
    } else {
      cout << "Test MapSizeSetterGetter passed!" << endl;
    }
  }

  void testMapDensitySetterGetter() {
    Map map;
    map.setMapDensity(500);
    if (map.getMapDensity() != 500) {
      cout << "Test MapDensitySetterGetter failed!" << endl;
    } else {
      cout << "Test MapDensitySetterGetter passed!" << endl;
    }
  }

  void testIDSetterGetter() {
    Map map;
    map.setID(42);
    if (map.getID() != 42) {
      cout << "Test IDSetterGetter failed!" << endl;
    } else {
      cout << "Test IDSetterGetter passed!" << endl;
    }
  }

  void testNameSetterGetter() {
    Map map;
    map.setName("TestMap");
    if (map.getName() != "TestMap") {
      cout << "Test NameSetterGetter failed!" << endl;
    } else {
      cout << "Test NameSetterGetter passed!" << endl;
    }
  }
};

#endif