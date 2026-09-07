#pragma once

#include "grid.h"

#include <functional>
#include <optional>
#include <vector>

class Automaton {
private:
	Grid& grid;
	std::function<void(Grid& grid, int row, int col)> automatonRules;

public:
	Automaton(Grid& grid)
		:grid(grid)
	{
	};

	void Update();
};