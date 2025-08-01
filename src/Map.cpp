﻿#include "../include/Map.h"
#include "../include/Resources.h"
#include "../include/Physics.h"
// dependencies
#include <fstream>
#include <box2d/box2d.h>

Map::Map(float cellSize)
    : cellSize(cellSize), grid()
{
}

void Map::Create_Map_From_Txt_File(const std::string &filepath)
{
    std::ifstream file(filepath);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(file, line))
    {
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

sf::Vector2f Map::Create_Map_From_Image(const sf::Image &image)
{
    grid.clear();
    grid = std::vector(image.getSize().x, std::vector(image.getSize().y, 0));

    sf::Vector2f playerPosition{};

    for (size_t x = 0; x < grid.size(); x++)
    {
        for (size_t y = 0; y < grid[x].size(); y++)
        {
            sf::Color color = image.getPixel(x, y);
            if (color == sf::Color::Black)
            {
                grid[x][y] = 1;
                b2BodyDef groundBodyDef = b2DefaultBodyDef();
                groundBodyDef.position.x = cellSize * x + cellSize / 2.0f;
                groundBodyDef.position.y = cellSize * y + cellSize / 2.0f;

                b2BodyId groundId = b2CreateBody(Physics::worldId, &groundBodyDef);
                b2Polygon groundBox = b2MakeBox(cellSize / 2.0f, cellSize / 2.0f);

                b2ShapeDef groundShapeDef = b2DefaultShapeDef();
                b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);
            }
            else if (color == sf::Color::Red) // TO-DO: What if there are multiple red pixels?
                playerPosition = sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f);
			    continue;
        }
    }

    return playerPosition;
}

void Map::Draw(Renderer &renderer)
{
    int x = 0;
    for (const auto &column : grid)
    {
        int y = 0;
        for (const auto &cell : column)
        {
            if (cell)
            {
                renderer.Draw(Resources::textures["grass-block.png"],
                              sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f), // cell center position
                              sf::Vector2f(cellSize, cellSize));                                            // cell size
            }
            y++;
        }
        x++;
    }
}
