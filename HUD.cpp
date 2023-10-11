#include "HUD.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <fstream>
#include <vector>

typedef std::vector<ScoreData> vector_scores;

HUD::HUD() {
  // Load the font
  if (!font.loadFromFile("Assets/PixelifySans-VariableFont_wght.ttf")) {
    // Handle font loading error
  }

  // Initialize health text
  healthText.setFont(font);
  healthText.setCharacterSize(50);
  healthText.setFillColor(sf::Color::White);
  healthText.setPosition(841, 0);

  // Initialize enemies text
  enemiesText.setFont(font);
  enemiesText.setCharacterSize(50);
  enemiesText.setFillColor(sf::Color::White);
  enemiesText.setPosition(841, 120);

  // Initialize score text
  scoreText.setFont(font);
  scoreText.setCharacterSize(50);
  scoreText.setFillColor(sf::Color::White);
  scoreText.setPosition(841, 240);

  // Initialize steps text
  stepsCountText.setFont(font);
  stepsCountText.setCharacterSize(50);
  stepsCountText.setFillColor(sf::Color::White);
  stepsCountText.setOutlineColor(sf::Color::White);
  stepsCountText.setPosition(841, 320);

  health = 300;    // Initial health
  enemies = 3;     // Initial enemies
  score = 50;      // Initial score
  stepsCount = 0;  // Initial steps count
}

int HUD::getHealth() { return health; }
void HUD::setHealth(int health) { this->health = health; }

int HUD::getEnemies() { return enemies; }
void HUD::setEnemies(int enemies) { this->enemies = enemies; }

int HUD::getScore() { return score; }
void HUD::setScore(int score) { this->score = score; }

int HUD::getSteps() { return stepsCount; }
void HUD::setSteps(int stepsCount) { this->stepsCount = stepsCount; }

void HUD::loseEnemy() {
  if (enemies > 0) {
    enemies--;
  }
}

void HUD::updateStats(int newHealth, int newEnemies, int newScore,
                      int newStepsCount) {
  health = newHealth;
  enemies = newEnemies;
  score = newScore;
  stepsCount = newStepsCount;

  // Update the text
  healthText.setString("Health: ");
  enemiesText.setString("Enemies: ");
  scoreText.setString("Score: " + std::to_string(50 - stepsCount));
  stepsCountText.setString("Steps: " + std::to_string(stepsCount));
}

void HUD::draw(sf::RenderWindow* window) {
  // Draw all HUD elements
  window->draw(healthText);
  window->draw(enemiesText);
  window->draw(scoreText);
  window->draw(stepsCountText);

  // Draw the health bar
  sf::RectangleShape healthBar(
      sf::Vector2f(400 * (health / 300.0f), 20));  // Adjust size as needed
  healthBar.setFillColor(sf::Color::Blue);         // Adjust color as needed
  healthBar.setPosition(841, 60);                  // Adjust position as needed
  window->draw(healthBar);

  // Draw three vertical lines for enemies
  for (int i = 0; i < enemies; i++) {
    sf::RectangleShape enemyLifeLine(
        sf::Vector2f(5, 30));                    // Adjust size as needed
    enemyLifeLine.setFillColor(sf::Color::Red);  // Adjust color as needed
    enemyLifeLine.setPosition(842 + i * 15,
                              180);  // Adjust position and spacing as needed
    window->draw(enemyLifeLine);
  }
}

void HUD::writeToFile(std::string filename) {
  ScoreData sd1;                          // Score to write to txt.
  std::time_t time = std::time(nullptr);  // Add time of score.
  std::tm* timeInfo = std::localtime(&time);
  std::strftime(sd1.timeString, sizeof(sd1.timeString), "%Y-%m-%d %H:%M:%S",
                timeInfo);
  sd1._score = this->score;

  // Add score to static scores vector.
  // HUD::scores.push_back(sd1);
  std::ofstream ScoreRecord(filename, std::ios::app);

  // vector_scores::iterator itr;

  ScoreRecord << "A score of " << sd1._score << " was acheived on "
              << sd1.timeString << std::endl;

  ScoreRecord.close();
}
