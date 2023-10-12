#include <iostream>
#include "./PlayerTest.h"
#include "./EnemyTest.h"
#include "./MoveableEntityTest.h"
#include "./HUDTest.h"
#include "./MapTest.h"
#include "./NonMoveableEntityTest.h"

using namespace std;

int main() {
  PlayerTest playerTest;
  playerTest.runTests();

  EnemyTest EnemyTest;
  EnemyTest.runTests();

  MoveableEntityTest moveableEntityTest;
  moveableEntityTest.runTests();

  HUDTest hudTest;
  hudTest.runTests();

  MapTest mapTest;
  mapTest.runTests();

  NonMoveableEntityTest nonMoveableEntityTest;
  nonMoveableEntityTest.runTests();

  cout << "All tests completed." << endl;

  return 0;
}
