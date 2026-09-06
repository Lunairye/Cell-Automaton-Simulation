#pragma once

#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <memory>
#include <functional>
#include <string>
#include <optional>

struct UIStyle {
	Color background = LIGHTGRAY;
	Color foreground = BLACK;
	Color hoverTint = GRAY;
	Font  font = GetFontDefault();
	float fontSize = 20.0f;
	float padding = 8.0f;
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
	std::optional<Color> background = std::nullopt;

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