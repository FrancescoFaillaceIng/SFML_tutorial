#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;

int main()
{
    //variables
    float PlayerMovementSpeed = 0.01;
    int CounterWalking = 0;

    //create window
    sf::RenderWindow window(sf::VideoMode(1500, 850), "My window");

    //set icon
    sf::Image icon;
    if(!icon.loadFromFile( R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\PallinaNatale.jpg)"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //background
    sf::Texture texturetree;
    if(!texturetree.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\AlberoNatale.jpg)"))
        return EXIT_FAILURE;
    sf::Sprite spritetree (texturetree);

    //player
    sf::Texture textureplayer;
    if(!textureplayer.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\rpg_sprite_walk.png)"))
        return EXIT_FAILURE;
    sf::Sprite spriteplayer (textureplayer);
    spriteplayer.setPosition(window.getSize().x/2, window.getSize().y/2);
    spriteplayer.setTextureRect(sf::IntRect(0, 0, 24, 32));

    //testo
    sf::Font font;
    if(!font.loadFromFile(R"(C:\Users\erosp\Desktop\SFML_tutorial\Resources\Christmas Bell - Personal Use.otf)"))
        return EXIT_FAILURE;
    sf::Text testo("quello che voi",font,50);
    testo.setFillColor(sf::Color::Black);
    testo.setPosition(300,300);


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

        // get the global mouse position (relative to the desktop)
        //sf::Vector2i globalPosition = sf::Mouse::getPosition();
        //cout << globalPosition.x << " " << globalPosition.y << endl;

        // get the local mouse position (relative to a window)
        /*sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
        cout << localPosition.x << " " << localPosition.y << endl; */

        //up
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cout << "the up key is pressed" << endl;
            // set the mouse position locally (relative to a window)
            sf::Mouse::setPosition(sf::Vector2i(750, 50), window); // window is a sf::Window
        }
        //down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cout << "the down key is pressed" << endl;
            // set the mouse position locally (relative to a window)
            sf::Mouse::setPosition(sf::Vector2i(750, 800), window); // window is a sf::Window
        }
        //right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            cout << "the right key is pressed" << endl;
            // set the mouse position locally (relative to a window)
            sf::Mouse::setPosition(sf::Vector2i(1400, 400), window); // window is a sf::Window
        }
        //left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            cout << "the left key is pressed" << endl;
            // set the mouse position locally (relative to a window)
            sf::Mouse::setPosition(sf::Vector2i(10, 400), window); // window is a sf::Window
        } */

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            spriteplayer.move(0, -PlayerMovementSpeed);
            spriteplayer.setTextureRect(sf::IntRect(CounterWalking * 24, 32, 24, 32));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            spriteplayer.move(0, PlayerMovementSpeed);
            spriteplayer.setTextureRect(sf::IntRect(CounterWalking * 24, 0, 24, 32));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            spriteplayer.move(PlayerMovementSpeed, 0);
            spriteplayer.setTextureRect(sf::IntRect(CounterWalking * 24, 32*3, 24, 32));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            spriteplayer.move(-PlayerMovementSpeed, 0);
            spriteplayer.setTextureRect(sf::IntRect(CounterWalking * 24, 32*2, 24, 32));
        }

        CounterWalking++;
        if (CounterWalking == 7)
            CounterWalking = 0;

        //draw sprite
        //window.draw(spritetree);

        //draw testo
        //
        // window.draw(testo);

        //draw player
        window.draw(spriteplayer);

        //update the window
        window.display();
    }


    return 0;
}
