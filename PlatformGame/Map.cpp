#include "Map.h"
#include "Resources.h"

#include <fstream>

Map::Map(float cellSize)
    : cellSize(cellSize), grid()
{
}

void Map::Create_Map_From_Txt_File(const std::string& filepath)
{
    std::ifstream file(filepath);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(file, line)) {
        if (!line.empty())
            lines.push_back(line);
    }

    size_t width = lines[0].size();
    size_t height = lines.size();

    grid.clear();
    grid.resize(width, std::vector<int>(height, 0));

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            grid[x][y] = (lines[y][x] == '1') ? 1 : 0;
        }
    }
}

void Map::Draw(Renderer& renderer)
{
    int x = 0;
    for (const auto& column : grid)
    {
        int y = 0;
        for (const auto& cell : column)
        {
            if (cell)
            {
                renderer.Draw(Resources::textures["grass-block.png"],
                    sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f),
                    sf::Vector2f(cellSize, cellSize));
            }
            y++;
        }
        x++;
    }
}
