#pragma once

#include "raymath.h"

#include <vector>

struct Cell {
	bool activated = false;
};

class Grid {
private:
	int rows = 0;
	int cols = 0;
	std::vector<Cell> cells{};

public:

	Grid(int rows, int cols)
		:
		rows(rows),
		cols(cols)
	{
		cells.assign(rows * cols, Cell());
	};

	Cell& GetCell(int row, int col) {
		return cells[col + (row * cols)];
	}
};