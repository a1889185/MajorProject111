#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>

class GameMenu {
 private:
  sf::Font font;
  sf::Text startText;
  sf::Text pauseText;
  sf::Text exitText;

 public:
  GameMenu();
  void draw(sf::RenderWindow& window);
  int handleInput(sf::RenderWindow& window);
};

#endif
