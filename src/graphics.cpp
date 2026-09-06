#include "graphics.h"

void BuildMainMenu(Panel& uiRoot, Grid& grid) {
	auto playButton = std::make_unique<Button>();

	const float PLAYWIDTH = 100;
	const float PLAYHEIGHT = 40;

	playButton->position = { 
		uiRoot.position.x + (uiRoot.dimensions.x / 2) - (PLAYWIDTH / 2), 
		uiRoot.position.y + (uiRoot.dimensions.y / 2) - (PLAYHEIGHT / 2)
	};

	playButton->dimensions = { PLAYWIDTH, PLAYHEIGHT };
	playButton->label = "auera";

	uiRoot.children.push_back(std::move(playButton));
}

void BuildSimulator(Panel& uiRoot, Grid& grid) {}

void BuildSettings(Panel& uiRoot, Grid& grid) {}

void Renderer::Update() {
	uiRoot.Update();
}

void Renderer::Render() {
	ClearBackground(GRAY);

	if (currentScene == Scene::SIMULATOR) {
		DrawRectangle(gridPosition.x, gridPosition.y, gridDimensions.x, gridDimensions.y, LIGHTGRAY);
		DrawRectangle(textboxPosition.x, textboxPosition.y, textboxDimensions.x, textboxDimensions.y, LIGHTGRAY);

		float cellW = gridDimensions.x / grid.cols;
		float cellH = gridDimensions.y / grid.rows;

		for (int row = 0; row < grid.rows; row++) {
			for (int col = 0; col < grid.cols; col++) {
				Rectangle bounds{
					gridPosition.x + col * cellW,
					gridPosition.y + row * cellH,
					cellW, cellH
				};
				drawCell(bounds, grid.GetCell(row, col));
			}
		}
	}
	

	uiRoot.Draw(style);
}

void Renderer::SwapScene(const Scene& scene) {
	uiRoot.children.clear();

	switch (scene)
	{
	case Scene::MAINMENU:
		currentScene = Scene::MAINMENU;
		BuildMainMenu(uiRoot, grid);
		break;
	case Scene::SIMULATOR:
		currentScene = Scene::SIMULATOR;
		BuildSimulator(uiRoot, grid);
		break;
	case Scene::SETTINGS:
		currentScene = Scene::SETTINGS;
		BuildSettings(uiRoot, grid);
		break;
	}
}