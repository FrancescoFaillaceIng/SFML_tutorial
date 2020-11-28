//
// Created by erosp on 27/11/2020.
//

#include "Projectile.h"

Projectile::Projectile() {
    rect.setSize(sf::Vector2f(10, 10));
    rect.setPosition(0, 0);
    sprite.setTextureRect(sf::IntRect(0,0,55,42));
}

void Projectile::Update() {
    if (direction == 1) //up
        rect.move(0, -movementSpeed);
    if (direction == 2) //down
        rect.move(0, movementSpeed);
    if (direction == 3) //left
        rect.move(-movementSpeed, 0);
    if (direction == 4) //right
        rect.move(movementSpeed, 0);

    //lifetime
    counterLifetime++;
    if (counterLifetime >= lifetime)
        destroy = true;

    //sprite
    sprite.setPosition(rect.getPosition());



}