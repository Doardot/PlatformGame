#include "Game.h"
#include "Resources.h"
#include "Map.h"
#include "Player.h"

// dependencies 
#include <SFML/Graphics.hpp>
#include <filesystem>

Map map(16.0f);
Camera camera(320.0f);
Resources resources;
Player player;

void Game_Begin(const sf::RenderWindow& window)
{
	const std::string textureFolder = "./assets/terrain/";
	resources.Load_Textures(textureFolder);

	sf::Image image;
	if (!image.loadFromFile("./assets/map/map.png"))
		return; // TO-DO: Log error or handle failure

	player.position = map.Create_Map_From_Image(image);
}

void Game_Update(float deltaTime)
{
	player.Update(deltaTime);
	camera.position = player.position;
}

void Game_Render(Renderer& renderer)
{
	map.Draw(renderer);
	player.Draw(renderer);
}