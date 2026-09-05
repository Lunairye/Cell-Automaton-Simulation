#pragma once

#include "raymath.h"

#include "grid.h"
#include "ui.h"

#include <memory>
#include <string>
#include <functional>



using DrawCell = std::function<void(Rectangle bounds, const Cell& cell)>;


class Renderer {
private:

public:
	Grid* grid;
	
	Vector2 gridPosition{ 25, 25 };
	Vector2 gridDimensions{ 750, 750 };

	Vector2 textboxPosition{ 850, 25 };
	Vector2 textboxDimensions{ 725, 750};

	UIStyle style;
	Panel uiRoot;

	DrawCell drawCell = [](Rectangle bounds, const Cell& cell) {
		DrawRectangleRec(bounds, cell.value == 0 ? BLACK : RAYWHITE);
	};

	Renderer(Grid* grid)
		:grid(grid)
	{
	};

	void Update();
	void Render();
};