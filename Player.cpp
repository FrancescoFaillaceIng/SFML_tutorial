//
// Created by erosp on 27/11/2020.
//

#include "Player.h"

Player::Player() {
    rect.setSize(sf::Vector2f(48, 64));
    rect.setPosition(750-24, 425-32);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 0, 48, 64));
}

void Player::Update() {
    sprite.setPosition(rect.getPosition());
}

void Player::UpdateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 64, 48, 64));
        direction = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 0, 48, 64));
        direction = 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 64*2, 48, 64));
        direction = 3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 64*3, 48, 64));
        direction = 4;
    }

    counterWalking++;
    if (counterWalking == 7)
        counterWalking = 0;
}