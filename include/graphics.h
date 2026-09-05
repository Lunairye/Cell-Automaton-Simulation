#pragma once

#include "raymath.h"

class Renderer {
private:

public:
	Vector2 position{};
	Vector2 dimensions{};
	
	Vector2 gridPosition{};
	Vector2 gridDimensions{};

	Vector2 textboxPosition{};
	Vector2 textboxDimensions{};

	void Render(Grid& grid);
};