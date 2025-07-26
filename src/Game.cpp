#include "../include/Game.h"
#include "../include/Resources.h"
#include "../include/Map.h"
#include "../include/Player.h"
#include "../include/Physics.h"
// dependencies
#include <SFML/Graphics.hpp>
#include <filesystem>

Map map(1.0f);
Camera camera(20.0f);
Resources resources;
Player player;

void Game_Begin(const sf::RenderWindow& window)
{
    const std::string textureFolder = std::string(ASSETS_PATH) + "/textures/terrain";
    resources.Load_Textures(textureFolder);

    Physics::Init();

    sf::Image image;
    if (!image.loadFromFile(std::string(ASSETS_PATH) + "/textures/map/map.png"))
        return; // TO-DO: Log error or handle failure

    player.position = map.Create_Map_From_Image(image);
	player.Begin();
}

void Game_Update(float deltaTime)
{
    Physics::Update(deltaTime);
    player.Update(deltaTime);
    camera.position = player.position;
}

void Game_Render(Renderer& renderer)
{
    map.Draw(renderer);
    player.Draw(renderer);
}