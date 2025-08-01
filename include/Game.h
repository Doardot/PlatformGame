#ifndef __GAME_H__
#define __GAME_H__

#include "Renderer.h"
#include "Camera.h"
// dependencies
#include <SFML/Graphics.hpp>

extern Camera camera;

void Game_Begin(const sf::RenderWindow& window);
void Game_Update(float deltaTime);
void Game_Render(Renderer& renderer);

#endif