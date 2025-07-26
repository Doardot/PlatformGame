#include "../include/Player.h"
#include "../include/Resources.h"
#include "../include/Physics.h"
// dependencies
#include <box2d/box2d.h>
#include <box2d/collision.h>

const float movementSpeed = 3.0f;
const float playerSize = 1.4f;
const float playerHeight = 1.5f;

void Player::Begin()
{
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = { position.x,  position.x };

	bodyId = b2CreateBody(Physics::worldId, &bodyDef);
	b2Polygon dynamicBox = b2MakeBox(playerSize / 2.0f, playerHeight / 2.0f);

	b2ShapeDef shapeDef = b2DefaultShapeDef();
	shapeDef.density = 1.0f;
	shapeDef.material.friction = 0.3f;

	b2CreatePolygonShape(bodyId, &shapeDef, &dynamicBox);
}

void Player::Update(float deltaTime)
{
	float move = movementSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
		move *= 2;

	b2Vec2 pos = b2Body_GetPosition(bodyId);
	position = sf::Vector2f(pos.x, pos.y);
	bodyIdRotation = b2Body_GetRotation(bodyId);
	printf("%4.2f %4.2f %4.2f\n", bodyIdPosition.x, bodyIdPosition.y, b2Rot_GetAngle(bodyIdRotation)); // debug
}

void Player::Draw(Renderer& renderer) const
{
	renderer.Draw(Resources::textures["Idle.png"], position, sf::Vector2f(playerSize, playerHeight), b2Rot_GetAngle(bodyIdRotation));
}