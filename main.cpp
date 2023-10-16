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

  bool isLevelComplete = true, playerWonLevel = true, hasPlayerMoved = false;

  RectangleShape deathScreen(Vector2f(42 * 20, 42 * 20));
  Color color1;

  int playerHealth = 300, numEnemies = 3, currentNumEnemies = 3, score, steps;
  Player* player = new Player(10, 10, 100, playerHealth);
  MoveableEntity** enemies = new MoveableEntity*[numEnemies];
  Map* map;
  HUD hud;

  // ------------- MAIN GAME WINDOW LOOP -------------
  Event closeEvent;
  while (window.isOpen()) {
    while (window.pollEvent(closeEvent)) {
      if (closeEvent.type == Event::Closed) {
        window.close();
      }
    }

    // Reset everything on new level.
    if (isLevelComplete) {
      hud.writeToFile("ScoreRecord.txt");  // add score to file.

      if (playerWonLevel) {
        color1 = Color::Green;
        color1.a = 100;
        deathScreen.setFillColor(color1);
        window.draw(deathScreen);
        window.display();
        sleep(milliseconds(500));
      } else {
        color1 = Color::Red;
        color1.a = 100;
        deathScreen.setFillColor(color1);
        window.draw(deathScreen);
        window.display();
        sleep(milliseconds(500));
      }

      delete map;
      map = new Map(999);  // 1000 = less paths, 1 = more paths.

      delete[] enemies;  // deallocate the enemies array
      enemies = new MoveableEntity*[numEnemies];
      enemies[0] = new Enemy(5, 5);
      enemies[1] = new Enemy(15, 15);
      enemies[2] = new Enemy(5, 15);

      delete player;
      player = new Player(10, 10, 100, playerHealth);

      score = 50;
      steps = 0;
      currentNumEnemies = 3;
      hud.updateStats(playerHealth, currentNumEnemies, score, steps);

      isLevelComplete = false;
    }

    // Update player.
    hasPlayerMoved = player->performAction(map, &keyClock, enemies, numEnemies);

    // Move enemys only if player moved.
    if (hasPlayerMoved) {
      score--;
      steps++;
      currentNumEnemies = numEnemies;
      for (i = 0; i < numEnemies; i++) {
        if (enemies[i]->getHealth() != 0) {
          enemies[i]->advancePos(map, player);
        } else if (enemies[i]->getHealth() == 0) {
          currentNumEnemies--;
        }
      }
      hasPlayerMoved = 0;
    }

    // Update HUD.
    hud.updateStats(player->getHealth(), currentNumEnemies, score, steps);

    // check if all enemies are dead and if level is complete.
    playerWonLevel = true;
    for (i = 0; i < numEnemies; i++) {
      if (enemies[i]->getHealth() != 0) {
        playerWonLevel = false;
      }
    }
    if ((player->getHealth() == 0) || (playerWonLevel)) {
      isLevelComplete = true;
    }

    // Draw and display objects.
    window.clear();
    map->draw(&window);
    hud.draw(&window);
    player->draw(&window);
    for (i = 0; i < numEnemies; i++) {
      if (enemies[i]->getHealth() != 0) {
        enemies[i]->draw(&window);
      }
    }
    window.display();

  }  // END MAIN GAME LOOP
  delete player;
  delete map;
  for (int i = 0; i < numEnemies; i++) {
    delete enemies[i];
  }
  delete[] enemies;
  return 0;
}