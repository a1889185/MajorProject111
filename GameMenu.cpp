#include "GameMenu.h"

GameMenu::GameMenu() {
  if (!font.loadFromFile("Assets/PixelifySans-VariableFont_wght.ttf")) {
    // Handle font loading error
  }

  startText.setFont(font);
  startText.setString("1. Start");
  startText.setCharacterSize(50);
  startText.setFillColor(sf::Color::Red);
  startText.setPosition(450, 320);

  pauseText.setFont(font);
  pauseText.setString("2. Resume");
  pauseText.setCharacterSize(50);
  pauseText.setFillColor(sf::Color::Red);
  pauseText.setPosition(450, 440);

  exitText.setFont(font);
  exitText.setString("3. Exit");
  exitText.setCharacterSize(50);
  exitText.setFillColor(sf::Color::Red);
  exitText.setPosition(450, 560);

  // Add control instructions
  controlsText.setFont(font);
  controlsText.setString("Key Controls:");
  controlsText.setCharacterSize(30);
  controlsText.setFillColor(sf::Color::White);
  controlsText.setPosition(25, 25);

  controlsInstructionsText.setFont(font);
  controlsInstructionsText.setString(
      "Press: 'W' to Move Up   |   'S' to Move Down   |   'A' to Move Left   | "
      "  'D' to Move Right   |   'Space' to Wait Turn");
  controlsInstructionsText.setCharacterSize(20);
  controlsInstructionsText.setFillColor(sf::Color::White);
  controlsInstructionsText.setPosition(25, 65);

  // Add gameplay instructions
  gameplayInstructionsText.setFont(font);
  gameplayInstructionsText.setString("Game Instructions:");
  gameplayInstructionsText.setCharacterSize(30);
  gameplayInstructionsText.setFillColor(sf::Color::White);
  gameplayInstructionsText.setPosition(25, 120);

  gameplayDescriptionText.setFont(font);
  gameplayDescriptionText.setString(
      "The player begins with three lives. If an enemy attacks the player, they lose a life.\n"
      "If the player loses all lives, the game ends.\n"
      "To attack an enemy, the player must move into the space they occupy.\n"
      "Beware of moving near enemies as it may cost a life.");
  gameplayDescriptionText.setCharacterSize(20);
  gameplayDescriptionText.setFillColor(sf::Color::White);
  gameplayDescriptionText.setPosition(25, 160);
}

void GameMenu::draw(sf::RenderWindow& window) {

  // Set the background color to dark grey
  window.clear(sf::Color(50, 50, 50)); // RGB values for dark gray

  window.draw(startText);
  window.draw(pauseText);
  window.draw(exitText);
  window.draw(controlsText);
  window.draw(controlsInstructionsText);
  window.draw(gameplayInstructionsText);
  window.draw(gameplayDescriptionText);
}

int GameMenu::handleInput(sf::RenderWindow& window) {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      return -1;  // Exit the game
    }

    if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == sf::Keyboard::M) {
        // Toggle the menu when "M" key is pressed
        return 0;
      } else if (event.key.code == sf::Keyboard::Num1) {
        return 1;  // Start the game when 1 key is pressed
      } else if (event.key.code == sf::Keyboard::Num2) {
        return 2;  // Resume the game when 2 key is pressed
      } else if (event.key.code == sf::Keyboard::Num3) {
        return -1;  // Exit the game when 3 key is pressed
      }
    }
  }

  return 0;
}
