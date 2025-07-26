#ifndef __PHYSICS_H__
#define __PHYSICS_H__

// dependencies
#include <box2d/box2d.h>

class Physics
{
public:
	static void Init();
	static void Update(float deltaTime);
	static b2WorldDef worldDef;
	static b2WorldId worldId;
};

#endif