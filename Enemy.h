//
// Created by erosp on 28/11/2020.
//

#ifndef MAIN_CPP_ENEMY_H
#define MAIN_CPP_ENEMY_H

#include "Entity.h"
#include "Random.h"

class Enemy: public Entity {
public:
    float movementSpeed = 2;
    int movementLength = 20;
    int attackDamage = 2;
    int counterWalking = 0;
    int direction = 0; //1 - up, 2 - down, 3 - left, 4 - right
    int counter = 0;
    int hp = 15;
    bool alive = true;

    Enemy();
    void Update();
    void UpdateMovement();
};


#endif //MAIN_CPP_ENEMY_H
