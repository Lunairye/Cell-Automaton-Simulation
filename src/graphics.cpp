#include "raylib.h"
#include "raymath.h"

#include "graphics.h"
#include "grid.h"

void Renderer::Render() {
	ClearBackground(GRAY);
	DrawRectangle(gridPosition.x, gridPosition.y, gridDimensions.x, gridDimensions.y, LIGHTGRAY);
	DrawRectangle(textboxPosition.x, textboxPosition.y, textboxDimensions.x, textboxDimensions.y, LIGHTGRAY);

	for (size_t row = 0; row < grid->rows; row++) {
		for (size_t col = 0; col < grid->cols; col++) {
			
		}
	}
}