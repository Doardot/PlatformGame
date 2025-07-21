#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#include <unordered_map>
#include <SFML/Graphics.hpp>

class Resources
{
public:
	static std::unordered_map<std::string, sf::Texture> textures;
};

#endif