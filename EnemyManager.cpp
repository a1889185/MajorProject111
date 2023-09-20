#include "Enemy.h"
#include "EnemyManger.h"

EnemyManager::EnemyManager() {
  this->maxEnemies = 0;
  this->activeEnemies = nullptr;
  this->numEnemies = 0;
}

EnemyManager::EnemyManager(int maxEnemies, int initialNumEnemies) {
  this->maxEnemies = maxEnemies;
  this->activeEnemies = new Enemy[maxEnemies];
  this->numEnemies = initialNumEnemies;
}

void EnemyManager::addEnemy(int xPos, int yPos) {
  if (numEnemies < maxEnemies) {
    activeEnemies[numEnemies] = new Enemy(xPos, yPos);
    numEnemies++;
  } else {
    std::cout << "Maximum number of enemies reached." << std::endl;
  }
}

void EnemyManager::removeEnemy(int xPos, int yPos) {
  for (int i = 0; i < numEnemies; i++) {
    if (activeEnemies[i]->xPos == x && activeEnemies[i]->yPos == y) {
      // Remove the enemy and shift remaining enemies in the array
      delete activeEnemies[i];
      for (int j = i; j < numEnemies - 1; j++) {
        activeEnemies[j] = activeEnemies[j + 1];
      }
      numEnemies--;
      return;  // Stop searching once found and removed
    }
  }
}

void EnemyManager::attackOpponent(int opponentPosX, int opponentPosY) {
  // Assuming we want to remove opponent upon attack
  removeEnemy(opponentPosX, opponentPosY);
}

void EnemyManager::printActiveEnemies() {
  for (int i = 0; i < numEnemies; i++) {
    std::cout << "Enemy at (" << activeEnemies[i]->xPos << ", "
              << activeEnemies[i]->yPos << ")" << std::endl;
  }
}

EnemyManager::~EnemyManager() {
  // Deallocate memory for enemy objects
  for (int i = 0; i < numEnemies; i++) {
    delete activeEnemies[i];
  }
}