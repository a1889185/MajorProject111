#include "GameMenu.h"

GameMenu::GameMenu() {
  if (!font.loadFromFile("Assets/PixelifySans-VariableFont_wght.ttf")) {
    // Handle font loading error
  }

  startText.setFont(font);
  startText.setString("1. Start");
  startText.setCharacterSize(60);
  startText.setFillColor(sf::Color::Red);
  startText.setPosition(450, 320);

  pauseText.setFont(font);
  pauseText.setString("2. Resume");
  pauseText.setCharacterSize(60);
  pauseText.setFillColor(sf::Color::Red);
  pauseText.setPosition(450, 440);

  exitText.setFont(font);
  exitText.setString("3. Exit");
  exitText.setCharacterSize(60);
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
      "The player begins with 3 lives. If an enemy attacks the player, they lose a life.\n"
      "If the player loses all lives, the game ends.\n"
      "To attack an enemy, the player must be orthogonally adjacent and move into the space occupied by the enemy.\n"
      "For an enemy to attack, the player must be within or move to a space orthogonally adjacent to that enemy.\n"
      "Beware of moving near enemies, it could cost a life, consider waiting and letting them move towards you. Goodluck!");
  gameplayDescriptionText.setCharacterSize(20);
  gameplayDescriptionText.setFillColor(sf::Color::White);
  gameplayDescriptionText.setPosition(25, 160);

  // Add player description
  playerDescriptionText.setFont(font);
  playerDescriptionText.setString("Player:");
  playerDescriptionText.setCharacterSize(30);
  playerDescriptionText.setFillColor(sf::Color::White);
  playerDescriptionText.setPosition(25, 320);

  // Load player image texture
  if (!playerTexture.loadFromFile("Assets/Player.png")) {
    // Handle loading error
  }
  playerSprite.setTexture(playerTexture);
  playerSprite.setScale(2.0f, 2.0f);  // Scale image to preference
  playerSprite.setPosition(25, 370);  // Adjust position as needed

  // Add enemy description
  enemyDescriptionText.setFont(font);
  enemyDescriptionText.setString("Enemy:");
  enemyDescriptionText.setCharacterSize(30);
  enemyDescriptionText.setFillColor(sf::Color::White);
  enemyDescriptionText.setPosition(25, 490);

  // Load enemy image texture
  if (!enemyTexture.loadFromFile("Assets/Enemy.png")) {
    // Handle loading error
  }
  enemySprite.setTexture(enemyTexture);
  enemySprite.setScale(1.6f, 1.6f);  // Scale image to preference
  enemySprite.setPosition(25, 540);  // Adjust position as needed
}

void GameMenu::draw(sf::RenderWindow& window) {
  // Set the background color to black
  window.clear(sf::Color(0, 0, 0));  // RGB values for black

  window.draw(startText);
  window.draw(pauseText);
  window.draw(exitText);
  window.draw(controlsText);
  window.draw(controlsInstructionsText);
  window.draw(gameplayInstructionsText);
  window.draw(gameplayDescriptionText);

  window.draw(playerDescriptionText);
  window.draw(enemyDescriptionText);

  window.draw(playerSprite);
  window.draw(enemySprite);
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
