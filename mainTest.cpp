#include <iostream>
#include "MoveableEntityTest.h"
#include "NonMoveableEntityTest.h"
#include "MapTest.h"
#include "PlayerTest.h"
#include "EnemyTest.h"
#include "HUDTest.h"

using namespace std;

int main() {

  MoveableEntityTest moveableEntityTest;
  moveableEntityTest.runTests();

  // NonMoveableEntityTest nonMoveableEntityTest;
  // nonMoveableEntityTest.runTests();

  // MapTest mapTest;
  // mapTest.runTests();

  // PlayerTest playerTest;
  // playerTest.runTests();

  // EnemyTest EnemyTest;
  // EnemyTest.runTests();

  // HUDTest hudTest;
  // hudTest.runTests();

  cout << "All tests completed." << endl;

  return 0;
}
