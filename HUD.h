#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <string>

class HUD {
 private:
  sf::Font font;
  sf::Text healthText; 
  sf::Text enemiesText;
  sf::Text scoreText; 
  sf::Text stepsCountText;
  sf::RectangleShape enemiesBar;
  int health; 
  int enemies;
  int score; 
  int stepsCount; 

 public:
  HUD();
  void loseEnemy();
  int getEnemies(); 
  void setEnemies(int numEnemies);
  void updateStats(int newHealth, int newEnemies, int newStepsCount); 
  void draw(sf::RenderWindow &window); 

}; 

#endif