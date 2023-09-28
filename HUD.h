#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <string>

class HUD {
 private:
  sf::Font font;
  sf::Text healthText; 
  sf::Text livesText;
  sf::Text scoreText; 
  sf::Text stepsText;
  sf::RectangleShape livesBar;
  int health; 
  int remainingLives;
  int score; 
  int stepsCount; 

 public:
  HUD(); 
  void loseLife(); 
  int getRemainingLives(); 
  void updateStats(int newHealth, int newRemainingLives, int newStepsCount); 
  void draw(sf::RenderWindow &window); 

}; 

#endif
