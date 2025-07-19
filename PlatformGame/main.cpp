#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Camera.h"
#include "Renderer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Platform Game");
    window.setFramerateLimit(60);
    sf::Clock deltaClock;
    Camera camera;
    Renderer renderer(window);

    Game_Begin(window);
    while (window.isOpen()) {
        float deltaTime = deltaClock.restart().asSeconds();

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
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
