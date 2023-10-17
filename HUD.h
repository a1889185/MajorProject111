#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

typedef struct {
  int _score;
  char timeString[100];
} ScoreData;
typedef std::vector<ScoreData> vector_scores;

class HUD {
 private:
  sf::Font font;
  sf::Text healthText;
  sf::Text enemiesText;
  sf::Text scoreText;
  sf::Text stepsCountText;
  sf::RectangleShape enemiesBar;
  int health;
  int enemies;
  int score;
  int stepsCount;

  sf::Texture enemyTexture;
  sf::Sprite enemySprite;

  // read write to txt file.
  vector_scores scores;

 public:
  HUD();

  int getHealth();
  void setHealth(int health);

  int getEnemies();
  void setEnemies(int enemies);

  int getScore();
  void setScore(int score);

  int getSteps();
  void setSteps(int stepsCount);

  void loseEnemy();
  void updateStats(int newHealth, int newEnemies, int newScore,
                   int newStepsCount);
  void draw(sf::RenderWindow* window);

  void writeToFile(std::string filename);
};

#endif