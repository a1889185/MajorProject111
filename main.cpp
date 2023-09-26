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

  bool isLevelComplete = true;
  Map* map;
  bool isLevelComplete = true;
  Map* map;

  // x | y | damage | health | Colour
  Player* player = new Player(10, 10);
  bool hasPlayerMoved = 0;

  Enemy** enemies = new Enemy*[3];
  Enemy** enemies = new Enemy*[3];

  // MAIN GAME WINDOW LOOP
  Event closeEvent;
  while (window.isOpen()) {
    while (window.pollEvent(closeEvent)) {
      if (closeEvent.type == Event::Closed) window.close();
    }

    if (&player1 != nullptr) {
      if (isLevelComplete) {
        // Generate random map with densisty: 1000=not many paths, 1=allpaths.
        delete[] map;
        map = new Map(100);

        delete[] enemies[0];
        delete[] enemies[1];
        delete[] enemies[2];
        enemies[0] = new Enemy(5, 5);
        enemies[1] = new Enemy(15, 15);
        enemies[2] = new Enemy(5, 15);

        isLevelComplete = false;
      }

    if (isLevelComplete) {
      // Generate random map with densisty: 1000=not many paths, 1=allpaths.
      delete map;
      map = new Map(1000);

      delete enemies[0];
      delete enemies[1];
      delete enemies[2];
      enemies[0] = new Enemy(5, 5);
      enemies[1] = new Enemy(15, 15);
      enemies[2] = new Enemy(5, 15);

      delete player;
      player = new Player(10, 10, 25, 100, Color::Blue);

      isLevelComplete = false;
    }

    // Take input from user in player class and move it if allowed.
    // NO event needs to be passed to it from main.
    hasPlayerMoved = player->performAction(map, &keyClock);
      // Take input from user in player class and move it if allowed.
      // NO event needs to be passed to it from main.
      hasPlayerMoved = player1.performAction(map, &keyClock);

    if (hasPlayerMoved) {
      enemies[0]->advancePos(map, player);
      enemies[1]->advancePos(map, player);
      enemies[2]->advancePos(map, player);
      hasPlayerMoved = 0;
    }
      if (hasPlayerMoved) {
        enemies[0]->advancePos(map, &player1);
        enemies[1]->advancePos(map, &player1);
        enemies[2]->advancePos(map, &player1);
        hasPlayerMoved = 0;
      }

    window.clear();
    map->draw(&window);         // Display map.
    player->draw(&window);      // Display player.
    enemies[0]->draw(&window);  // Display enemy.
    enemies[1]->draw(&window);
    enemies[2]->draw(&window);
    window.display();

    if (player->getHealth() == 0) {
      isLevelComplete = true;
    }
      window.clear();
      map->draw(&window);         // Display map.
      player1.draw(&window);      // Display player.
      enemies[0]->draw(&window);  // Display enemy.
      enemies[1]->draw(&window);
      enemies[2]->draw(&window);
      window.display();
    }
  }

  return 0;
}