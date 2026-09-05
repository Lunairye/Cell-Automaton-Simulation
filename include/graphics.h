#pragma once

#include "raymath.h"

#include "grid.h"

#include <memory>
#include <string>
#include <functional>

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

class Panel : public UIElement {
private:

public:
	std::vector<std::unique_ptr<UIElement>> children;

	void Update() override;
	void Draw(const UIStyle& style) override;
};

class Button : public UIElement {
private:

public:
	std::string label;
	std::function<void()> onClick;

	void Update() override;
	void Draw(const UIStyle& style) override;
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