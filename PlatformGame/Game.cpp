#include "Game.h"
#include "Resources.h"

// dependencies 
#include <filesystem>


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
}

void Game_Update(float deltaTime)
{

}

void Game_Render(Renderer& renderer)
{
	renderer.Draw(Resources::textures["grass-block.png"], sf::Vector2f(), sf::Vector2f(2, 2));
}