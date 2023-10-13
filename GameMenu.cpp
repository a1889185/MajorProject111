#include "GameMenu.h"

GameMenu::GameMenu() {
  if (!font.loadFromFile("Assets/PixelifySans-VariableFont_wght.ttf")) {
    // Handle font loading error
  }

  startText.setFont(font);
  startText.setString("1. Start");
  startText.setCharacterSize(50);
  startText.setFillColor(sf::Color::White);
  startText.setPosition(400, 240);

  pauseText.setFont(font);
  pauseText.setString("2. Pause/Resume");
  pauseText.setCharacterSize(50);
  pauseText.setFillColor(sf::Color::White);
  pauseText.setPosition(400, 360);

  exitText.setFont(font);
  exitText.setString("3. Exit");
  exitText.setCharacterSize(50);
  exitText.setFillColor(sf::Color::White);
  exitText.setPosition(400, 480);
}

void GameMenu::draw(sf::RenderWindow& window) {
  window.draw(startText);
  window.draw(pauseText);
  window.draw(exitText);
}

int GameMenu::handleInput(sf::RenderWindow& window) {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      return -1;  // Exit the game
    }

    if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == sf::Keyboard::M) {
        // Open the menu when Enter key is pressed
        return 0;
      } else if (event.key.code == sf::Keyboard::Num1) {
        return 1;  // Start the game when 1 key is pressed
      } else if (event.key.code == sf::Keyboard::Num2) {
        return 2;  // Pause/Resume the game when 2 key is pressed
      } else if (event.key.code == sf::Keyboard::Num3) {
        return -1;  // Exit the game when 3 key is pressed
      }
    }
  }

  return 0;
}
