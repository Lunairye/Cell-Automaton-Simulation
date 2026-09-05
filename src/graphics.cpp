#include "raylib.h"
#include "raymath.h"

#include "graphics.h"
#include "grid.h"

void Panel::Update() {
	for (auto& child : children) child->Update();
}

void Panel::Draw(const UIStyle& style) {
	DrawRectangleV(position, dimensions, style.background);
	for (auto& child : children) child->Draw(style);
}

void Button::Update() {
	Rectangle bounds{ position.x, position.y, dimensions.x, dimensions.y };
	if (CheckCollisionPointRec(GetMousePosition(), bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		if (onClick) onClick();
	}
}

void Button::Draw(const UIStyle& style) {
	Rectangle bounds{ position.x, position.y, dimensions.x, dimensions.y };
	DrawRectangleRec(bounds, style.background);
	DrawTextEx(style.font, label.c_str(), position, style.fontSize, 1, style.foreground);
}

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