#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Renderer.h"
// dependencies
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Player
{
public:
	void Begin();
	void Update(float deltaTime);
	void Draw(Renderer& renderer) const;
	sf::Vector2f position;
private:
	b2BodyId bodyId{ b2_nullBodyId };
	b2Vec2 bodyIdPosition{ 0 };
	b2Rot bodyIdRotation{ 0, 0 };
};

#endif __PLAYER_H__