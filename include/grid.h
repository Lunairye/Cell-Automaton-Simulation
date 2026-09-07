#pragma once

#include "raymath.h"

#include <vector>

struct Cell {
	int value = 0;
};

class Grid {
private:
	std::vector<Cell> cells{};
	std::vector<Cell> nextCells{};
public:
	int rows = 0;
	int cols = 0;

	Grid(int rows, int cols)
		:
		rows(rows),
		cols(cols)
	{
		cells.assign(rows * cols, Cell());
		nextCells.assign(rows * cols, Cell());

		for (size_t i = 0; i < cells.size(); i++) {
			if (i % 2 == 0) {
				cells[i].value = 1;
			}
		}
	};

	Cell& GetCellFromCells(int row, int col) {
		return cells[col + (row * cols)];
	}

	Cell& GetCellFromNextCells(int row, int col) {
		return nextCells[col + (row * cols)];
	}

	void UpdateToNextCells() {
		cells.swap(nextCells);
	}
};