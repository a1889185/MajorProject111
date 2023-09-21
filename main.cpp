// The Main Game file.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"
#include "Map.h"
#include "NonMoveableEntity.h"

using namespace sf;

// units.
int u = 42;
int windowSize = 20 * u;

int main() {
  srand((time(nullptr)));
  RenderWindow window(VideoMode(windowSize, windowSize), "ROUGE");

  // Generate random map with densisty: 1000=not many paths, 1=allpaths.
  Map map1(1000);
  int numWalls = map1.getNumWalls();
  NonMoveableEntity** allWalls = map1.getWalls();

  // MAIN GAME WINDOW LOOP.
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }
    window.clear();

    // Display map.
    for (int i = 0; i < numWalls; i++) {
      window.draw(allWalls[i]->getShape());
    }

    window.display();
  }

  return 0;
}