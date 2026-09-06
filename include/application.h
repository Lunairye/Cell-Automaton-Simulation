#pragma once

#include "grid.h"
#include "graphics.h"

class Application {
private:
	
public:
	Grid grid;
	Renderer renderer;

	Application(int rows, int cols)
		: grid(rows, cols), renderer(grid)
	{
	};
};