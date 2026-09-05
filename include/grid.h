#pragma once

#include "raymath.h"

#include <vector>

struct Cell {
	int value = 0;
};

class Grid {
private:
	std::vector<Cell> cells{};
public:
	int rows = 0;
	int cols = 0;

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