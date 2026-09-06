#include "ui.h"

void Panel::Update() {
	for (auto& child : children) child->Update();
}

void Panel::Draw(const UIStyle& style) {
	if (background.has_value()) {
		DrawRectangleV(position, dimensions, style.background);
	}
	
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

	Vector2 textSize = MeasureTextEx(style.font, label.c_str(), style.fontSize, 1);

	Vector2 textPosition = {
		position.x + (dimensions.x / 2) - (textSize.x / 2),
		position.y + (dimensions.y / 2) - (textSize.y / 2)
	};

	DrawTextEx(style.font, label.c_str(), textPosition, style.fontSize, 1, style.foreground);
}