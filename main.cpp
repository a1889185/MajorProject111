// The Main Game file.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Enemy.h"
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

  // x | y | damage | health | Colour
  Player player1(10, 10, 25, 100, Color::Blue);
  bool hasPlayerMoved = 0;

  Enemy enemy1(5, 5), enemy2(15, 15), enemy3(5, 15);

  // MAIN GAME WINDOW LOOP
  Event closeEvent;
  while (window.isOpen()) {
    while (window.pollEvent(closeEvent)) {
      if (closeEvent.type == Event::Closed) window.close();
    }

    // Take input from user in player class and move it if allowed.
    // NO event needs to be passed to it from main.
    hasPlayerMoved = player1.performAction(&map1, &keyClock);

    if (hasPlayerMoved) {
      enemy1.advancePos(&map1, &player1);
      enemy2.advancePos(&map1, &player1);
      enemy3.advancePos(&map1, &player1);
      hasPlayerMoved = 0;
    }

    window.clear();
    map1.draw(&window);     // Display map.
    player1.draw(&window);  // Display player.
    enemy1.draw(&window);   // Display enemy.
    enemy2.draw(&window);
    enemy3.draw(&window);
    window.display();
  }

  return 0;
}