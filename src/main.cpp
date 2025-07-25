#include "../include/Game.h"
#include "../include/Camera.h"
#include "../include/Renderer.h"
//dependencies
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Platform Game");
    window.setFramerateLimit(60);
    sf::Clock deltaClock;
    Renderer renderer(window);

    Game_Begin(window);
    while (window.isOpen()) {
        float deltaTime = deltaClock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.setView(camera.GetView(window.getSize()));
        Game_Update(deltaTime);

        window.clear(sf::Color(20, 20, 20, 00));
        Game_Render(renderer);
        window.display();
    }

    return 0;
}