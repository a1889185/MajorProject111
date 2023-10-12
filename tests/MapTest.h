#ifndef MAPTEST_H
#define MAPTEST_H

#include "./Map.h"
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
      cout << "Test Map IDSetterGetter failed!" << endl;
    } else {
      cout << "Test Map IDSetterGetter passed!" << endl;
    }
  }

  void testNameSetterGetter() {
    Map map;
    map.setName("TestMap");
    if (map.getName() != "TestMap") {
      cout << "Test Map NameSetterGetter failed!" << endl;
    } else {
      cout << "Test Map NameSetterGetter passed!" << endl;
    }
  }
};

#endif