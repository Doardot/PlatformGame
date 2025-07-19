#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include "Renderer.h"

void Game_Begin(const sf::RenderWindow& window);
void Game_Update(float deltaTime);
void Game_Render(Renderer& renderer);

#endif