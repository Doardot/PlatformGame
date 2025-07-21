#include "Game.h"
#include "Resources.h"
#include "Map.h"

// dependencies 
#include <filesystem>

Map map;
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

	map.Create_Map_From_Txt_File("map.txt");
	camera.position = sf::Vector2f(160.0f, 160.0f);
}

void Game_Update(float deltaTime)
{

}

void Game_Render(Renderer& renderer)
{
	map.Draw(renderer);
}