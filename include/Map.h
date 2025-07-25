#ifndef __MAP_H__
#define __MAP_H__

#include "Renderer.h"
// dependencies
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map(float cellSize = 10.0f);

	// This function creates a map from a text file. DEPRECATED.
	void Create_Map_From_Txt_File(const std::string& filepath);

	// ! This function creates a map from an image file.
	// The function returns the player's position as a `sf::Vector2f`.
	sf::Vector2f Create_Map_From_Image(const sf::Image& image);

	void Draw(Renderer& renderer);

	std::vector<std::vector<int>> grid;
	float cellSize;
};

#endif