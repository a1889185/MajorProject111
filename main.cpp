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

  Player player1(10, 10);

  // MAIN GAME WINDOW LOOP
  Event closeEvent;
  while (window.isOpen()) {
    while (window.pollEvent(closeEvent)) {
      if (closeEvent.type == Event::Closed) window.close();
    }

    // Take input from user in player class and move it if allowed.
    // NO event needs to be passed to it from main.
    player1.performAction(&map1, &keyClock);

    window.clear();
    map1.draw(&window);     // Display map.
    player1.draw(&window);  // Display player.
    window.display();
  }

  return 0;
}