#ifndef __MAP_H__
#define __MAP_H__

#include "Renderer.h"
#include <vector>
#include <string>

class Map
{
public:
	Map(float cellSize = 10.0f);
	void Draw(Renderer& renderer);
	void Create_Map_From_Txt_File(const std::string& filepath);

	std::vector<std::vector<int>> grid;
	float cellSize;
};

#endif