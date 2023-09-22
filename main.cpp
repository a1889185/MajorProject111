// The Main Game file.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Entity.h"
#include "Map.h"
#include "MoveableEntity.h"
#include "NonMoveableEntity.h"
#include "Player.h"

using namespace sf;

// units.
int u = 42;
int windowSize = 20 * u;

int main() {
  srand((time(nullptr)));
  Clock keyClock;  // for setting a delay between keypresses.
  RenderWindow window(VideoMode(windowSize, windowSize), "Rogue");

  // Generate random map with densisty: 1000=not many paths, 1=allpaths.
  Map map1(1000);
  int numWalls = map1.getNumWalls();
  NonMoveableEntity** allWalls = map1.getWalls();

  Player player1(10, 10);

  // MAIN GAME WINDOW LOOP
  Event event;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }
    window.clear();

    // Display map.
    for (int i = 0; i < numWalls; i++) {
      window.draw(allWalls[i]->getShape());
    }

    // if (clock.getElapsedTime().asMilliseconds() >= 200) {
    //   if (Keyboard::isKeyPressed(Keyboard::W)) {
    //     help.move(&map1, "up");
    //   } else if (Keyboard::isKeyPressed(Keyboard::A)) {
    //     help.move(&map1, "left");
    //   } else if (Keyboard::isKeyPressed(Keyboard::S)) {
    //     help.move(&map1, "down");
    //   } else if (Keyboard::isKeyPressed(Keyboard::D)) {
    //     help.move(&map1, "right");
    //   }
    //   clock.restart();  // Reset the clock for the next delay
    // }
    player1.performAction(&map1, &keyClock);

    player1.draw(&window);

    window.display();
  }

  return 0;
}