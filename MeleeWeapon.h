//
// Created by erosp on 01/12/2020.
//

#ifndef MAIN_CPP_MELEEWEAPON_H
#define MAIN_CPP_MELEEWEAPON_H

#include <SFML/Graphics.hpp>

class MeleeWeapon {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;

    float movementSpeed = 5;
    int attackDamage = 5;
    int counterWalking = 0;
    int direction = 0; //1 - up, 2 - down, 3 - left, 4 - right
    int hp = 10;

    MeleeWeapon();
    void Update();
    void UpdateMovement();

};


#endif //MAIN_CPP_MELEEWEAPON_H
