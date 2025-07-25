#ifndef __RESOURCES_H__
#define __RESOURCES_H__

// dependencies
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class Resources
{
public:
	// !Loads textures from a given folder and stores them in a static unordered_map "textures".
	void Load_Textures(std::string textureFolder);

	static std::unordered_map<std::string, sf::Texture> textures;
};

#endif