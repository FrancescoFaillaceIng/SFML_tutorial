#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Random.h"
#include "Entity.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "TextDisplay.h"


using namespace std;

int main()
{
    //variables
    int counter;
    int counter2;
    sf::Clock clock;
    sf::Clock clock2;

    //create window
    sf::RenderWindow window(sf::VideoMode(1500, 850), "TEST RPG");
    window.setFramerateLimit(60);

    //set icon
    sf::Image icon;
    if(!icon.loadFromFile( R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\role-playing-game.png)"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //background texture
    sf::Texture textureBackground;
    if(!textureBackground.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\TexDung.png)"))
        return EXIT_FAILURE;
    sf::Sprite spriteBackground (textureBackground);
    spriteBackground.setTextureRect(sf::IntRect(0,0,1500,850));
    textureBackground.setRepeated(true);

    //text texture
    sf::Font font;
    if(!font.loadFromFile( R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\SuperLegendBoy-4w8Y.ttf)"))
        return EXIT_FAILURE;

    //player texture
    sf::Texture texturePlayer;
    if(!texturePlayer.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\rpg_sprite_walk.png)"))
        return EXIT_FAILURE;

    //enemy texture
    sf::Texture textureEnemy;
    if(!textureEnemy.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\skeletons.png)"))
        return EXIT_FAILURE;

    //projectile texture
    sf::Texture textureProjectile;
    if(!textureProjectile.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\Projectiles_preview_rev_1.png)"))
        return EXIT_FAILURE;

    //player object
    class Player Player1;
    Player1.sprite.setTexture(texturePlayer);

    //projectile vector array
    vector<Projectile>::const_iterator iter;
    vector<Projectile> projectileArray;

    //projectile object
    class Projectile Projectile1;
    Projectile1.sprite.setTexture(textureProjectile);

    //enemy vector array
    vector<Enemy>::const_iterator iter4;
    vector<Enemy> enemyArray;

    //enemy object
    class Enemy Enemy1;
    Enemy1.sprite.setTexture(textureEnemy);
    enemyArray.push_back(Enemy1);

    //text vector array
    vector<TextDisplay>::const_iterator iter8;
    vector<TextDisplay> textDisplayArray;

    //text object
    class TextDisplay TextDisplay1;
    TextDisplay1.text.setFont(font);


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


        //clock
        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();

        //enemy collision with player
        if (elapsed2.asSeconds() >= 0.5) {
            clock2.restart();
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
                if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds())) {

                    //text display
                    TextDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                    TextDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2,
                                                  Player1.rect.getPosition().y - Player1.rect.getSize().y / 2);
                    textDisplayArray.push_back(TextDisplay1);

                    Player1.hp -= enemyArray[counter].attackDamage;
                }
                counter++;
            }
        }
        cout << Player1.hp << endl;

        //projectiles collisions
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds())){
                    projectileArray[counter].destroy = true;

                    //text display
                    TextDisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                    TextDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x / 2,enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y / 2);
                    textDisplayArray.push_back(TextDisplay1);

                    enemyArray[counter2].hp -= projectileArray[counter].attackDamage;
                    if (enemyArray[counter2].hp <= 0)
                        enemyArray[counter2].alive = false;
                }
                counter2++;
            }
            counter++;
        }

        //delete dead enemy
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
            if (!enemyArray[counter].alive) {
                enemyArray.erase(iter4);
                break;
            }
            counter++;
        }

        //delete projectiles
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
            if (projectileArray[counter].destroy) {
                projectileArray.erase(iter);
                break;
            }
            counter++;
        }

        //delete text
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
            if (textDisplayArray[counter].destroy) {
                textDisplayArray.erase(iter8);
                break;
            }
            counter++;
        }


        //spawn new enemies (y)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            Enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
            enemyArray.push_back(Enemy1);
        }

        //fire projectiles (left click)
        if (elapsed1.asSeconds() >= 0.1) {
            clock.restart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                Projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - Projectile1.rect.getSize().x/2, Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - Projectile1.rect.getSize().y/2);
                Projectile1.direction = Player1.direction;
                projectileArray.push_back(Projectile1);
            }
        }

        //draw projectiles
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
            projectileArray[counter].Update(); //update projectile
            window.draw(projectileArray[counter].sprite);
            counter++;
        }

        //draw enemies
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
            enemyArray[counter].Update();
            enemyArray[counter].UpdateMovement();
            window.draw(enemyArray[counter].sprite);
            counter++;
        }

        //update player
        Player1.Update();
        Player1.UpdateMovement();

        //draw player
        window.draw(Player1.sprite);

        //draw text
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
            textDisplayArray[counter].Update();
            window.draw(textDisplayArray[counter].text);
            counter++;
        }

        //update the window
        window.display();
    }


    return 0;
}
