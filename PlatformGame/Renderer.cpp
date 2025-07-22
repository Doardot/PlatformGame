#include "Renderer.h"
#include <vector>

Renderer::Renderer(sf::RenderTarget& target)
	: target(target)
{
}

// TO-DO: aux function to get the selected sprite from spritesheet
//sf::IntRect getTileRect(int col, int row, int tileSize) {
//    return sf::IntRect(
//        sf::Vector2i(col * tileSize, row * tileSize),
//        sf::Vector2i(tileSize, tileSize)
//    );
//}

void Renderer::Draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size)
{
	if (!sprite.has_value())
		sprite.emplace(texture);

	// TO-DO: Render sprites from spritesheet
	//sprite->setTextureRect(sourceRect);

	sprite->setTexture(texture, true);
	sprite->setOrigin((sf::Vector2f)texture.getSize() / 2.0f);
	sprite->setPosition(position);
	sprite->setScale(sf::Vector2f(size.x / texture.getSize().x,
		size.y / texture.getSize().y));

	target.draw(*sprite);
}