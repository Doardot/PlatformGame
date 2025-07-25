#ifndef __RENDERER_H__
#define __RENDERER_H__

// dependencies
#include <SFML/Graphics.hpp>

class Renderer
{
public:
	Renderer(sf::RenderTarget& target);

	void Draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size);
private:
	sf::RenderTarget& target;
	sf::Sprite sprite;
};

#endif 