//
// Created by erosp on 27/11/2020.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "Entity.h"

class Player: public Entity {
public:
    float movementSpeed = 1;
    int attackDamage = 5;
    int counterWalking = 0;
    int direction = 0; //1 - up, 2 - down, 3 - left, 4 - right

    Player();
    void Update();
    void UpdateMovement();
};


#endif //MAIN_CPP_PLAYER_H
