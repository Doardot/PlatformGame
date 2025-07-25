#ifndef __CAMERA_H__
#define __CAMERA_H__

// dependencies
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera(float zoomLevel = 5.0f);
	sf::View GetView(sf::Vector2u windowSize);

	float zoomLevel;
	sf::Vector2f position;
};

#endif