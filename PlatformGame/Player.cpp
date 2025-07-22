#include "Player.h"
#include "Resources.h"

const float movementSpeed = 100.0f;

void Player::Update(float deltaTime)
{
	float move = movementSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
		move *= 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		position.x += move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		position.x -= move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		position.y -= move * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		position.y += move * deltaTime;
}

void Player::Draw(Renderer& renderer) const
{
	renderer.Draw(Resources::textures["Idle.png"], position, sf::Vector2f(23.0f, 24.0f));
}