#include "Game.h"
#include "Resources.h"
#include "Map.h"

// dependencies 
#include <SFML/Graphics.hpp>
#include <filesystem>

Map map(16.0f);
Camera camera(320.0f);

void Game_Begin(const sf::RenderWindow& window)
{
	const std::string textureFolder = "./assets/terrain/";

	// Load all textures into an unordered map
    for (auto& file : std::filesystem::directory_iterator(textureFolder))
    {
		if (file.is_regular_file() && 
			(file.path().extension() == ".jpg" || file.path().extension() == ".png"))
		{
			sf::Texture texture;
			if (texture.loadFromFile(file.path().string()))
			{
				Resources::textures[file.path().filename().string()] = std::move(texture);
			}
			else
			{
				// TO-DO: Log error
			}
		}
    }

	sf::Image image;
	image.loadFromFile("./assets/map/map.png");
	map.Create_Map_From_Image(image);
	//map.Create_Map_From_Txt_File("map.txt");

	camera.position = sf::Vector2f(160.0f, 160.0f);
}

void Game_Update(float deltaTime)
{
	const float movementSpeed = 100.0f;
	float move = movementSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
		move *= 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		camera.position.x += move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		camera.position.x -= move * deltaTime;
}

void Game_Render(Renderer& renderer)
{
	map.Draw(renderer);
}