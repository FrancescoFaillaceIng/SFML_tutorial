#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;

int main()
{
    //create window
    sf::RenderWindow window(sf::VideoMode(1500, 850), "My window");

    //set icon
    sf::Image icon;
    if(!icon.loadFromFile( R"(C:\Users\franc\CLionProjects\SFML_tutorial\Resources\PallinaNatale.jpg)"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //background
    sf::Texture texturetree;
    if(!texturetree.loadFromFile(R"(C:\Users\franc\CLionProjects\SFML_tutorial\Resources\AlberoNatale.jpg)"))
        return EXIT_FAILURE;
    sf::Sprite spritetree (texturetree);

    //testo
    sf::Font font;
    if(!font.loadFromFile(R"(C:\Users\franc\CLionProjects\SFML_tutorial\Resources\Christmas Bell - Personal Use.otf)"))
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
    }
    //clear screen
    window.clear();

    //draw sprite
    window.draw(spritetree);

    //draw testo
    window.draw(testo);

    //update the window
    window.display();

    return 0;
}
