#ifndef ENTITYTEST_H
#define ENTITYTEST_H 

#include "./Entity.h"
#include <iostream>
using namespace std;

class EntityTest {
public:
    void runTests() {
        testGetPosX();
        testGetPosY();
    }

private:
    void testGetPosX() {
        Entity entity(30, 40);
        int posX = entity.getPosX();
        if (posX == 30) {
            cout << "getPosX Test: Passed" << endl;
        } else {
            cout << "getPosX Test: Failed" << endl;
        }
    }

    void testGetPosY() {
        Entity entity(30, 40);
        int posY = entity.getPosY();
        if (posY == 40) {
            cout << "getPosY Test: Passed" << endl;
        } else {
            cout << "getPosY Test: Failed" << endl;
        }
    }
};

#endif