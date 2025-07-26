#include "../include/Physics.h"

b2WorldDef Physics::worldDef = b2DefaultWorldDef();
b2WorldId Physics::worldId = {0};
float timeStep = 1.0f / 60.0f;

void Physics::Init()
{
	worldDef.gravity = {0.0f, 9.0f};
	worldId = b2CreateWorld(&worldDef);
}

void Physics::Update(float deltaTime)
{
	b2World_Step(worldId, timeStep, 4);
}