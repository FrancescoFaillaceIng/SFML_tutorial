//
// Created by erosp on 27/11/2020.
//

#ifndef MAIN_CPP_PROJECTILE_H
#define MAIN_CPP_PROJECTILE_H

#include "Entity.h"

class Projectile: public Entity {
public:
    int movementSpeed = 15;
    int attackDamage = 5;
    int direction = 0; //1 - up, 2 - down, 3 - left, 4 - right
    bool destroy = false;
    int counterLifetime = 0;
    int lifetime = 100;

    Projectile();
    void Update();
};


#endif //MAIN_CPP_PROJECTILE_H
