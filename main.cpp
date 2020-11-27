#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Player.h"
#include "Projectile.h"


using namespace std;

int main()
{
    //variables
    int counter;

    //create window
    sf::RenderWindow window(sf::VideoMode(1500, 850), "TEST RPG");

    //set icon
    sf::Image icon;
    if(!icon.loadFromFile( R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\role-playing-game.png)"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //background
    sf::Texture textureBackground;
    if(!textureBackground.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\TexDung.png)"))
        return EXIT_FAILURE;
    sf::Sprite spriteBackground (textureBackground);
    spriteBackground.setTextureRect(sf::IntRect(0,0,1500,850));
    textureBackground.setRepeated(true);

    //player texture
    sf::Texture texturePlayer;
    if(!texturePlayer.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\rpg_sprite_walk.png)"))
        return EXIT_FAILURE;

    //class Object
    class Player Player1;
    Player1.sprite.setTexture(texturePlayer);

    //projectile vector array
    vector<Projectile>::const_iterator iter;
    vector<Projectile> projectileArray;

    //projectile object
    class Projectile Projectile1;

    //start game loop
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //clear screen
        window.clear();

        //draw background
        window.draw(spriteBackground);

        //fire projectiles (space bar)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - Projectile1.rect.getSize().x/2, Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - Projectile1.rect.getSize().y/2);
            Projectile1.direction = Player1.direction;
            projectileArray.push_back(Projectile1);
        }

        //draw projectiles
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
            projectileArray[counter].Update(); //update projectile
            window.draw(projectileArray[counter].rect);
            counter++;
        }

        //update player
        Player1.Update();
        Player1.UpdateMovement();

        //draw player
        window.draw(Player1.sprite);

        //update the window
        window.display();
    }


    return 0;
}
