#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "Enemy.h"

class EnemyManager {
 private:
  int maxEnemies;  // max number of enemies
  Enemy* activeEnemies;   // array to store active enemies
  int numEnemies; // number of active enemies

 public:
  EnemyManager(); 
  EnemyManager(int maxEnemies, int initialNumEnemies) {


  void addEnemy(int xPos, int yPos); 
  void removeEnemy(int xPos, int yPos); 

  void attackOpponent(int opponentPosX, int opponentPosY); 
  void printActiveEnemies(); 

  ~EnemyManager(); 

};

#endif