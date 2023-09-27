#include "HUD.h" 

HUD::HUD() {
    // if (!font.loadFromFile("font_file_path_here")) {
    //     // Handle font loading failure
    // }

    healthText.setFont(font);
    healthText.setCharacterSize(24);
    healthText.setFillColor(sf::Color::White);

    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::White);

    livesBar.setSize(sf::Vector2f(200, 20));
    livesBar.setFillColor(sf::Color::Green);
    livesBar.setPosition(10, 10);

    remainingLives = 3;  // Initialize with 3 lives
    playerHealth = 300;
    playerDamage = 100; 
    enemyHealth = 100; 
    enemyDamage = 100;
    updateStats(playerHealth, remainingLives);
}

void HUD::loseLife() {
    // Decrease remaining lives and update the HUD
    if (remainingLives > 0) {
        remainingLives--;
        updateStats(playerHealth, remainingLives);
    }
}

int HUD::getRemainingLives() {
    return remainingLives;
}

void HUD::updateStats(int health, int remainingLives) {
    // Update the text of your HUD elements based on the provided values
    healthText.setString("Health: " + std::to_string(health));
    livesText.setString("Lives: " + std::to_string(remainingLives));
    // Update lives bar size based on remaining lives
    float livesRatio = static_cast<float>(remainingLives) / 3.0f;  // 3 lives in total
    livesBar.setSize(sf::Vector2f(200 * livesRatio, 20));
}

void HUD::draw(sf::RenderWindow& window) {
    // Draw lives text and bar
    window.draw(livesText);
    window.draw(livesBar);
}
