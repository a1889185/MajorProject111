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
#include "HUD.h"

using namespace sf;

// units.
int u = 42;
int windowSize = 20 * u;
int hudWidth = 400;    // HUD width (adjust as needed)
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
  int stepsCount = 0; // track number of steps 
  while (window.isOpen()) {
    while (window.pollEvent(closeEvent)) {
      if (closeEvent.type == Event::Closed) {
        window.close();
      }
    }

    if (isLevelComplete) {  // reset everything on new level.
      if (playerWonLevel) {
        hud.setEnemies(3); 
        color1 = Color::Green;
        color1.a = 100;
        deathScreen.setFillColor(color1);
        window.draw(deathScreen);
        window.display();
        sleep(milliseconds(500));
        //hud.setScore(50); 
      } else {
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
      map = new Map(1000);

      delete enemies[0];
      delete enemies[1];
      delete enemies[2];
      enemies[0] = new Enemy(5, 5);
      enemies[1] = new Enemy(15, 15);
      enemies[2] = new Enemy(5, 15);

      delete player;
      // x | y | damage | health | Colour
      player = new Player(10, 10, 100, 300, Color::Blue);

      isLevelComplete = false;
    }

    int numEnemies = 3; 
    // Take input from user in player class and move it if allowed.
    hasPlayerMoved = player->performAction(map, &keyClock, enemies, numEnemies);
    
    if (hasPlayerMoved) {  // move enemys if player moved.
      stepsCount++;
      for (i = 0; i < 3; i++) {
        if (enemies[i]->getHealth() != 0) {
          enemies[i]->advancePos(map, player);
          // check if attacked opponent in process
          if (player->getHealth() == 200) {
            hud.setHealth(200); 
          } else if (player->getHealth() == 100) {
            hud.setHealth(100);
          } else if (player->getHealth() == 0) {
            hud.setHealth(0);
          }
        } else if (enemies[i]->getHealth() == 0) {
          numEnemies--; 
          hud.setEnemies(numEnemies); 
        }
      }
      hasPlayerMoved = 0;
    }

    // Update HUD based on game state
    hud.updateStats(player->getHealth(), hud.getEnemies(), stepsCount);


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
    player->draw(&window);     // Display player.
    for (i = 0; i < 3; i++) {  // Display enemies.
      if (enemies[i]->getHealth() != 0) {
        enemies[i]->draw(&window);
      }
    }

    // Draw the HUD to the right of the game window
    hud.draw(window);

    // Display the window
    window.display();
  }
  return 0;
}