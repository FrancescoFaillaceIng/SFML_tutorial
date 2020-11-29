//
// Created by erosp on 29/11/2020.
//

#include "TextDisplay.h"

TextDisplay::TextDisplay() {
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(15);
    text.setString(myString);
}

void TextDisplay::Update() {
    text.move(0, -movementSpeed);
    counter++;
    if (counter >= lifeTime)
        destroy = true;
}