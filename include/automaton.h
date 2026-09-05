#pragma once

#include "grid.h"
#include "graphics.h"

class Automaton {
private:
	
public:
	Grid grid;
	Renderer renderer;

	Automaton(int rows, int cols)
		: grid(rows, cols), renderer(&grid)
	{
	};
};