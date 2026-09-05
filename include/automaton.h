#pragma once

#include "grid.h"
#include "graphics.h"
#include "scene.h"

class Automaton {
private:
	
public:
	Scene currentScene {Scene::MAINMENU}
	Grid grid;
	Renderer renderer;

	Automaton(int rows, int cols)
		: grid(rows, cols), renderer(&grid)
	{
	};
};