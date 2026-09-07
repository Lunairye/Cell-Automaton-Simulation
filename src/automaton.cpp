#include "automaton.h"

std::vector<Cell*> getNeighbours(Grid & grid, int row, int col) {
	std::vector<Cell*> neighbours{};

	for (int rowOffset = -1; rowOffset < 2; rowOffset++) {
		for (int colOffset = -1; colOffset < 2; colOffset++) {
			if (rowOffset == 0 && colOffset == 0) continue;

			int currentRow = row + rowOffset;
			int currentCol = col + colOffset;

			if (currentRow < 0 || currentRow >= grid.rows) continue;
			if (currentCol < 0 || currentCol >= grid.cols) continue;

			neighbours.push_back(&grid.GetCellFromCells(currentRow, currentCol));
		}
	}

	return neighbours;
}

void default(Grid& grid, int row, int col) {
	std::vector<Cell*> neighbours = getNeighbours(grid, row, col);

	int numOfOnes = 0;

	for (Cell* cell : neighbours) {
		if (cell->value == 1) numOfOnes++;
	}

	Cell* currentCell = &grid.GetCellFromCells(row, col);
	Cell* nextCell = &grid.GetCellFromNextCells(row, col);

	if (currentCell->value == 1) {
		if (numOfOnes == 2 || numOfOnes == 3) {
			nextCell->value = 1;
		}
		else {
			nextCell->value = 0;
		}
	}
	else {
		if (numOfOnes == 3) {
			nextCell->value = 1;
		}
		else {
			nextCell->value = 0;
		}
	}
}

void Automaton::Update() {
	for (size_t row = 0; row < grid.rows; row++) {
		for (size_t col = 0; col < grid.cols; col++) {

			if (automatonRules) {
				automatonRules(grid, row, col);
			}
			else {
				default(grid, row, col);
			}

		}
	}

	grid.UpdateToNextCells();
}