#ifndef __MAP_H__
#define __MAP_H__

#include "Renderer.h"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map(float cellSize = 10.0f);
	void Create_Map_From_Txt_File(const std::string& filepath);
	void Create_Map_From_Image(const sf::Image& image);
	void Draw(Renderer& renderer);

	std::vector<std::vector<int>> grid;
	float cellSize;
};

#endif