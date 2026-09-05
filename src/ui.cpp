#include "ui.h"

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