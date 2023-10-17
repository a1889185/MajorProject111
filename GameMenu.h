#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>

class GameMenu {
 private:
  sf::Font font;
  sf::Text startText;
  sf::Text pauseText;
  sf::Text exitText;
  sf::Text controlsText;
  sf::Text controlsInstructionsText;
  sf::Text gameplayInstructionsText;
  sf::Text gameplayDescriptionText;

 public:
  GameMenu();
  void draw(sf::RenderWindow& window);
  int handleInput(sf::RenderWindow& window);
};

#endif
