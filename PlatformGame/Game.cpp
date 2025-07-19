#include "Game.h"

sf::Texture texture;


void Game_Begin(const sf::RenderWindow& window)
{
	if (!texture.loadFromFile("assets/terrain/grass-block.png"))
		exit(-1);
}

void Game_Update(float deltaTime)
{

}

void Game_Render(Renderer& renderer)
{
	renderer.Draw(texture, sf::Vector2f(), sf::Vector2f(2, 2));
}