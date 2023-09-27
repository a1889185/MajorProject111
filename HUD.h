#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <string>

class HUD {
 private:
  sf::Font font;
  sf::Text healthText; 
  sf::Text livesText;
  sf::RectangleShape livesBar;
  int remainingLives;
  int playerHealth; 
  int playerDamage; 
  int enemyHealth; 
  int enemyDamage; 

 public:
  HUD(); 
  void loseLife(); 
  int getRemainingLives(); 
  void updateStats(int health, int remainingLives);
  void draw(sf::RenderWindow &window); 

}; 

#endif
