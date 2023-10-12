// The Main Game file.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Enemy.h"
#include "Entity.h"
#include "HUD.h"
#include "Map.h"
#include "MoveableEntity.h"
#include "NonMoveableEntity.h"
#include "Player.h"

using namespace sf;

// units.
int u = 42;
int windowSize = 20 * u;
int hudWidth = 400;                      // HUD width (adjust as needed)
int totalWidth = windowSize + hudWidth;  // Total window width

int main() {
  int i;
  srand((time(nullptr)));
  Clock keyClock;  // for setting a delay between keypresses.
  RenderWindow window(VideoMode(totalWidth, windowSize), "Rogue");

  RectangleShape deathScreen(Vector2f(42 * 20, 42 * 20));
  Color color1;

  bool isLevelComplete = true;
  bool playerWonLevel = true;
  bool hasPlayerMoved = false;

  Player* player = new Player(10, 10);
  MoveableEntity** enemies = new MoveableEntity*[3];
  Map* map;

  // Create HUD instance
  HUD hud;

  // MAIN GAME WINDOW LOOP
  Event closeEvent;
  while (window.isOpen()) {
    while (window.pollEvent(closeEvent)) {
      if (closeEvent.type == Event::Closed) {
        window.close();
      }
    }

    if (isLevelComplete) {  // reset everything on new level.
      if (playerWonLevel) {
        hud.setScore(50);
        hud.setSteps(0);
        hud.setEnemies(3);
        color1 = Color::Green;
        color1.a = 100;
        deathScreen.setFillColor(color1);
        window.draw(deathScreen);
        window.display();
        sleep(milliseconds(500));
      } else {
        hud.setScore(50);
        hud.setSteps(0);
        hud.setEnemies(3);
        color1 = Color::Red;
        color1.a = 100;
        deathScreen.setFillColor(color1);
        window.draw(deathScreen);
        window.display();
        sleep(milliseconds(500));
      }
      // Generate random map with densisty: 1000=not many paths, 1=allpaths.
      delete map;
      map = new Map(999);

      delete enemies[0];
      delete enemies[1];
      delete enemies[2];
      enemies[0] = new Enemy(5, 5);
      enemies[1] = new Enemy(15, 15);
      enemies[2] = new Enemy(5, 15);

      delete player;
      // x | y | damage | health
      player = new Player(10, 10, 100, 300);

      isLevelComplete = false;
    }

    int numEnemies = 3;
    // Take input from user in player class and move it if allowed.
    hasPlayerMoved = player->performAction(map, &keyClock, enemies, numEnemies);

    int score = hud.getScore();
    int steps = hud.getSteps();

    if (hasPlayerMoved) {  // move enemys if player moved.
      hud.setScore(--score);
      hud.setSteps(++steps);
      for (i = 0; i < 3; i++) {
        if (enemies[i]->getHealth() != 0) {
          enemies[i]->advancePos(map, player);

          hud.setHealth(player->getHealth());
        } else if (enemies[i]->getHealth() == 0) {
          --numEnemies;
          hud.setEnemies(numEnemies);
        }
      }
      hasPlayerMoved = 0;
    }

    // Update HUD based on game state
    hud.updateStats(player->getHealth(), hud.getEnemies(), hud.getScore(),
                    hud.getSteps());

    // check if all enemies are dead.
    playerWonLevel = true;
    for (i = 0; i < 3; i++) {
      if (enemies[i]->getHealth() != 0) {
        playerWonLevel = false;
      }
    }
    if ((player->getHealth() == 0) || (playerWonLevel)) {
      isLevelComplete = true;
    }

    window.clear();
    map->draw(&window);        // Display map.
    hud.draw(&window);         // Draw the HUD to the right of the game window
    player->draw(&window);     // Display player.
    for (i = 0; i < 3; i++) {  // Display enemies.
      if (enemies[i]->getHealth() != 0) {
        enemies[i]->draw(&window);
      }
    }

    // Display the window
    window.display();
  }
  return 0;
}