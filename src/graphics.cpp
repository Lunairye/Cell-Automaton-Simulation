#include "graphics.h"

void BuildMainMenu() {}
void BuildSimulator() {}
void BuildSettings() {}

void Renderer::Update() {
	uiRoot.Update();
}

void Renderer::Render() {
	ClearBackground(GRAY);
	DrawRectangle(gridPosition.x, gridPosition.y, gridDimensions.x, gridDimensions.y, LIGHTGRAY);
	DrawRectangle(textboxPosition.x, textboxPosition.y, textboxDimensions.x, textboxDimensions.y, LIGHTGRAY);

	float cellW = gridDimensions.x / grid->cols;
	float cellH = gridDimensions.y / grid->rows;

	for (int row = 0; row < grid->rows; row++) {
		for (int col = 0; col < grid->cols; col++) {
			Rectangle bounds{
				gridPosition.x + col * cellW,
				gridPosition.y + row * cellH,
				cellW, cellH
			};
			drawCell(bounds, grid->GetCell(row, col));
		}
	}

	uiRoot.Draw(style);
}

void Renderer::SwapScene(const Scene& scene) {
	uiRoot.children.clear();

	switch (scene)
	{
	case Scene::MAINMENU:
		BuildMainMenu();
		break;
	case Scene::SIMULATOR:
		BuildSimulator();
		break;
	case Scene::SETTINGS:
		BuildSettings();
		break;
	}
}