//
// Created by erosp on 28/11/2020.
//

#include "Enemy.h"


Enemy::Enemy() {
    rect.setSize(sf::Vector2f(48, 64));
    rect.setPosition(750-24, 425-32);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 63.5*2, 64.625, 63.5));
}

void Enemy::Update() {
    sprite.setPosition(rect.getPosition());
}

void Enemy::UpdateMovement() {
    if (direction == 1){ //up
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 64.625, 0, 48, 64));
    }

    else if (direction == 2){ //down
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 64.625, 64*2, 48, 64));
    }

    else if (direction == 3){ //left
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 64.625, 64, 48, 64));
    }

    else if (direction == 4){ //right
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 64.625, 64*3, 48, 64));
    }

    else {
        //no movement
    }

    counterWalking++;
    if (counterWalking == 7)
        counterWalking = 0;

    counter++;
    if (counter >= movementLength) {
        direction = generateRandom(20);
        counter = 0;
    }
}
