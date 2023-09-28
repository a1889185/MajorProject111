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

    // Initialize lives text
    livesText.setFont(font);
    livesText.setCharacterSize(50);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(841, 30);

    // Initialize score text
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(841, 60);

    // Initialize steps text
    stepsText.setFont(font);
    stepsText.setCharacterSize(50);
    stepsText.setFillColor(sf::Color::White);
    stepsText.setOutlineColor(sf::Color::White);
    stepsText.setPosition(841, 90);

    health = 100;            // Initial health
    remainingLives = 3;      // Initial lives
    score = 50;              // Initial score
    stepsCount = 0;          // Initial steps count
}

void HUD::loseLife() {
    if (remainingLives > 0) {
        remainingLives--;
    }
}

int HUD::getRemainingLives() {
    return remainingLives;
}

void HUD::updateStats(int newHealth, int newRemainingLives, int newStepsCount) {
    health = newHealth;
    remainingLives = newRemainingLives;
    stepsCount = newStepsCount;

    // Update the text
    healthText.setString("Health: " + std::to_string(health));
    livesText.setString("Lives: " + std::to_string(remainingLives));
    scoreText.setString("Score: " + std::to_string(50 - stepsCount));
    stepsText.setString("Steps: " + std::to_string(stepsCount));
}

void HUD::draw(sf::RenderWindow &window) {
    // Draw all HUD elements
    window.draw(healthText);
    window.draw(livesText);
    window.draw(scoreText);
    window.draw(stepsText);

    // Draw the health bar
    sf::RectangleShape healthBar(sf::Vector2f(200 * (health / 100.0f), 20)); // Adjust size as needed
    healthBar.setFillColor(sf::Color::Green);  // Adjust color as needed
    healthBar.setPosition(841, 150);            // Adjust position as needed
    window.draw(healthBar);

    // Draw three vertical lines for lives
    for (int i = 0; i < remainingLives; i++) {
        sf::RectangleShape lifeLine(sf::Vector2f(5, 30)); // Adjust size as needed
        lifeLine.setFillColor(sf::Color::Red);            // Adjust color as needed
        lifeLine.setPosition(841 + i * 15, 200);           // Adjust position and spacing as needed
        window.draw(lifeLine);
    }
}
