#include "graphics.h"

void BuildMainMenu(Panel& uiRoot, Grid& grid, std::function<void(Scene)> swapScene) {
	auto playButton = std::make_unique<Button>();

	const float PLAYWIDTH = 100;
	const float PLAYHEIGHT = 40;

	playButton->position = { 
		uiRoot.position.x + (uiRoot.dimensions.x / 2) - (PLAYWIDTH / 2), 
		uiRoot.position.y + (uiRoot.dimensions.y / 2) - (PLAYHEIGHT / 2)
	};

	playButton->dimensions = { PLAYWIDTH, PLAYHEIGHT };
	playButton->label = "auera";

	playButton->onClick = [swapScene]() {
		swapScene(Scene::SIMULATOR);
		};

	uiRoot.children.push_back(std::move(playButton));
}

void BuildSimulator(Panel& uiRoot, Grid& grid, Rectangle& gridRect, Rectangle& textBoxRect, std::function<void()> stepForward) {
	auto gridPanel = std::make_unique<Panel>();

	gridPanel->position = { gridRect.x, gridRect.y };
	gridPanel->dimensions = { gridRect.width, gridRect.height };
	gridPanel->background = DARKGRAY;
	uiRoot.children.push_back(std::move(gridPanel));

	auto textBoxPanel = std::make_unique<Panel>();

	textBoxPanel->position = { textBoxRect.x, textBoxRect.y };
	textBoxPanel->dimensions = { textBoxRect.width, textBoxRect.height };
	textBoxPanel->background = WHITE;
	uiRoot.children.push_back(std::move(textBoxPanel));

	auto forwardSimulationStep = std::make_unique<Button>();

	forwardSimulationStep->position = { textBoxRect.x + 50, textBoxRect.y + 50 };
	forwardSimulationStep->dimensions = { 100,100 };
	forwardSimulationStep->label = "Next Step";

	forwardSimulationStep->onClick = [stepForward] {
		stepForward();
		};
	uiRoot.children.push_back(std::move(forwardSimulationStep));
}

void BuildSettings(Panel& uiRoot, Grid& grid) {}

void Renderer::Update() {
	uiRoot.Update();
}

void RenderGrid(Grid& grid, Rectangle& gridRect, std::function<void(Rectangle bounds, const Cell& cell)> drawCell) {
	float cellW = gridRect.width / grid.cols;
	float cellH = gridRect.height / grid.rows;

	for (int row = 0; row < grid.rows; row++) {
		for (int col = 0; col < grid.cols; col++) {
			Rectangle bounds{
				gridRect.x + col * cellW,
				gridRect.y + row * cellH,
				cellW, cellH
			};
			drawCell(bounds, grid.GetCellFromCells(row, col));
		}
	}
}

void Renderer::Render() {
	ClearBackground(GRAY);

	uiRoot.Draw(style);

	if (currentScene == Scene::SIMULATOR) {
		RenderGrid(grid, gridRect, drawCell);
	}
}

void Renderer::SwapScene(const Scene& scene) {
	uiRoot.children.clear();

	switch (scene)
	{
	case Scene::MAINMENU:
		currentScene = Scene::MAINMENU;
		BuildMainMenu(uiRoot, grid, [this](Scene scene) {this->SwapScene(scene); });
		break;
	case Scene::SIMULATOR:
		currentScene = Scene::SIMULATOR;
		BuildSimulator(uiRoot, grid, gridRect, textBoxRect, [this]() {this->automaton.Update(); });
		break;
	case Scene::SETTINGS:
		currentScene = Scene::SETTINGS;
		BuildSettings(uiRoot, grid);
		break;
	}
}