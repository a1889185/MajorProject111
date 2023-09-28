#include "HUD.h"

HUD::HUD() {
    // Load the font
    if (!font.loadFromFile("PixelifySans-VariableFont_wght.ttf")) {
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

    health = 100;            // Initial health
    enemies = 3;             // Initial enemies
    score = 50;              // Initial score
    stepsCount = 0;          // Initial steps count
}

void HUD::loseEnemy() {
    if (enemies > 0) {
        enemies--;
    }
}

int HUD::getEnemies() {
    return enemies;
}

void HUD::setEnemies(int numEnemies) {
    this->enemies = numEnemies;
}

void HUD::updateStats(int newHealth, int newEnemies, int newStepsCount) {
    health = newHealth;
    enemies = newEnemies;
    stepsCount = newStepsCount;

    // Update the text
    healthText.setString("Health: ");
    enemiesText.setString("Enemies: ");
    scoreText.setString("Score: " + std::to_string(50 - stepsCount));
    stepsCountText.setString("Steps: " + std::to_string(stepsCount));
}

void HUD::draw(sf::RenderWindow &window) {
    // Draw all HUD elements
    window.draw(healthText);
    window.draw(enemiesText);
    window.draw(scoreText);
    window.draw(stepsCountText);

    // Draw the health bar
    sf::RectangleShape healthBar(sf::Vector2f(400 * (health / 100.0f), 20)); // Adjust size as needed
    healthBar.setFillColor(sf::Color::Blue);  // Adjust color as needed
    healthBar.setPosition(841, 60);           // Adjust position as needed
    window.draw(healthBar);

    // Draw three vertical lines for enemies
    for (int i = 0; i < enemies; i++) {
        sf::RectangleShape enemyLifeLine(sf::Vector2f(5, 30)); // Adjust size as needed
        enemyLifeLine.setFillColor(sf::Color::Red);            // Adjust color as needed
        enemyLifeLine.setPosition(842 + i * 15, 180);          // Adjust position and spacing as needed
        window.draw(enemyLifeLine);
    }
}
