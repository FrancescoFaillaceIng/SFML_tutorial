//
// Created by erosp on 29/11/2020.
//

#ifndef MAIN_CPP_TEXTDISPLAY_H
#define MAIN_CPP_TEXTDISPLAY_H

#include "Entity.h"

class TextDisplay: public Entity {
public:
    float movementSpeed = 1;
    string myString;
    int counter = 0;
    int lifeTime = 100;
    bool destroy = false;

    TextDisplay();
    void Update();
};

#endif //MAIN_CPP_TEXTDISPLAY_H
