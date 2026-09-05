#pragma once

#include "raymath.h"

#include "grid.h"

struct UIStyle {

};

class UIElement {
private:

public:
	Vector2 position{};
	Vector2 dimensions{};

	virtual void Update() {}
	virtual void Draw(const UIStyle& style) = 0;
	virtual ~UIElement() = default;
};

class Renderer {
private:

public:
	Grid* grid;
	
	Vector2 gridPosition{ 25, 25 };
	Vector2 gridDimensions{ 750, 750 };

	Vector2 textboxPosition{ 850, 25 };
	Vector2 textboxDimensions{ 725, 750};

	Renderer(Grid* grid)
		:grid(grid)
	{
	};

	void Render();
};