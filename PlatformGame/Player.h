#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Renderer.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	void Update(float deltaTime);
	void Draw(Renderer& renderer) const;
	sf::Vector2f position;
	float angle;
};

#endif __PLAYER_H__