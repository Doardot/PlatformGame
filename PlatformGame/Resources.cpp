#include "Resources.h"

void Resources::Load_Textures(std::string textureFolder) {
	// TO-DO: Improve this function by checking its subdirectories too
	for (auto& file : std::filesystem::directory_iterator(textureFolder))
	{
		if (file.is_regular_file() &&
			(file.path().extension() == ".jpg" || file.path().extension() == ".png"))
		{
			sf::Texture texture;
			if (texture.loadFromFile(file.path().string()))
			{
				textures[file.path().filename().string()] = std::move(texture);
			}
			else
			{
				// TO-DO: Log error
			}
		}
	}
}

std::unordered_map<std::string, sf::Texture> Resources::textures{};