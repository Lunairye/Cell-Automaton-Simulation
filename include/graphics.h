#pragma once

#include "raylib.h"
#include "raymath.h"

#include "grid.h"
#include "ui.h"

#include <memory>
#include <string>
#include <functional>

enum Scene {
	MAINMENU,
	SIMULATOR,
	SETTINGS
};

void BuildMainMenu(Panel& uiRoot, Grid& grid);

void BuildSimulator(Panel& uiRoot, Grid& grid);

void BuildSettings(Panel& uiRoot, Grid& grid);

using DrawCell = std::function<void(Rectangle bounds, const Cell& cell)>;

class Renderer {
private:

public:
	Grid& grid;
	
	Vector2 gridPosition{ 25, 25 };
	Vector2 gridDimensions{ 750, 750 };

	Vector2 textboxPosition{ 850, 25 };
	Vector2 textboxDimensions{ 725, 750};

	UIStyle style;
	Panel uiRoot;

	Scene currentScene{ Scene::MAINMENU };

	DrawCell drawCell = [](Rectangle bounds, const Cell& cell) {
		DrawRectangleRec(bounds, cell.value == 0 ? BLACK : RAYWHITE);
	};

	Renderer(Grid& grid)
		:grid(grid)
	{
		uiRoot.position = { 0, 0 };
		uiRoot.dimensions = { static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
	};

	void Update();
	void Render();

	void SwapScene(const Scene& scene);
};