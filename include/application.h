#pragma once

#include "grid.h"
#include "graphics.h"
#include "automaton.h"

class Application {
private:
	
public:
	Grid grid;
	Renderer renderer;
	Automaton automaton;

	Application(int rows, int cols)
		: grid(rows, cols), automaton(grid), renderer(grid, automaton)
	{
	};
};