#ifndef MAZECREATOR_H
#define MAZECREATOR_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace std;

class MazeCreator {
 public:
  int x;
  int y;

  MazeCreator(int x, int y) : x(x), y(x) {}
  MazeCreator() : x(0), y(0) {}
  ~MazeCreator() {}

  void move(int direction, int*** map, int n, int mapDenisity) {
    // set new temp posistion.
    int sudoX = x, sudoY = y;
    int inverseDirection = 0;
    // direction: 1=up, 2=right, 3=down, 4=left.
    switch (direction) {
      case 1:
        sudoY--;
        inverseDirection = 3;
        break;
      case 2:
        sudoX++;
        inverseDirection = 4;
        break;
      case 3:
        sudoY++;
        inverseDirection = 1;
        break;
      case 4:
        sudoX--;
        inverseDirection = 2;
        break;
      default:
        break;
    }
    // check for validity. cannot leave trace to place with adjacent zeros.
    // surroundings index vales: 0= null, 1=up, 2=right, 3=down, 4=left.
    int surroundings[5];
    surroundings[0] = 0;

    int flaseMove = false;

    if (sudoX < n - 1 && sudoY < n - 1 && sudoX > 0 && sudoY > 0) {
      // set surroundings of new sudo position.
      surroundings[1] = (*map)[sudoY - 1][sudoX];
      surroundings[2] = (*map)[sudoY][sudoX + 1];
      surroundings[3] = (*map)[sudoY + 1][sudoX];
      surroundings[4] = (*map)[sudoY][sudoX - 1];

      for (int i = 1; i < 5; i++) {
        // If any of the surroundings are zero, execpt the poistion that was
        // moved from (inverse direction), indicate a flase move.
        if ((surroundings[i] == 0) && (i != inverseDirection)) {
          flaseMove = true;
        }
      }

      // make move (update positions).
      this->x = sudoX;
      this->y = sudoY;

      // leave trace no flase move was detected.
      if (!flaseMove) {
        // leave trace, set pos on map equal to 0.
        if (surroundings[inverseDirection] == 0) {
          leaveTrace(map);
        }
      } else {
        // still have a random chance to leave a trace on map based on
        // mapDenisity. aim is to create more paths of map (make it less
        // difficult).
        int random = 1 + rand() % mapDenisity;
        if (random == 1) {
          leaveTrace(map);
        }
      }
    }
  }

  void leaveTrace(int*** map) { (*map)[this->y][this->x] = 0; }
};

#endif  // MAZECREATOR_H