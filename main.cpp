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
  int i;
  srand((time(nullptr)));
  Clock keyClock;  // for setting a delay between keypresses.
  RenderWindow window(VideoMode(windowSize, windowSize), "Rogue");

  RectangleShape deathScreen(Vector2f(42 * 20, 42 * 20));
  Color color1 = Color::Red;
  color1.a = 100;
  deathScreen.setFillColor(color1);

  bool isLevelComplete = true;
  bool hasPlayerMoved = false;

  Player* player = new Player(10, 10, 100, 100, Color::Blue);
  MoveableEntity** enemies = new MoveableEntity*[3];
  Map* map;

  // MAIN GAME WINDOW LOOP
  Event closeEvent;
  while (window.isOpen()) {
    while (window.pollEvent(closeEvent)) {
      if (closeEvent.type == Event::Closed) {
        window.close();
      }
    }

    if (isLevelComplete) {  // reset everything on new level.
      window.draw(deathScreen);
      window.display();
      sleep(milliseconds(500));

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
      // x | y | damage | health | Colour
      player = new Player(10, 10, 100, 100, Color::Blue);

      isLevelComplete = false;
    }

    // Take input from user in player class and move it if allowed.
    hasPlayerMoved = player->performAction(map, &keyClock, enemies, 3);

    if (hasPlayerMoved) {  // move enemys if player moved.
      for (i = 0; i < 3; i++) {
        if (enemies[i]->getHealth() != 0) {
          enemies[i]->advancePos(map, player);
          std::cout << enemies[i]->getHealth() << " ";
        }
      }
      std::cout << "\n";
      hasPlayerMoved = 0;
    }

    if (player->getHealth() == 0) {
      isLevelComplete = true;
    }

    window.clear();
    map->draw(&window);        // Display map.
    player->draw(&window);     // Display player.
    for (i = 0; i < 3; i++) {  // Display enemies.
      if (enemies[i]->getHealth() != 0) {
        enemies[i]->draw(&window);
      }
    }
    window.display();
  }
  return 0;
}