
#include "raylib.h"
#include "raymath.h"

#include "grid.h"
#include "graphics.h"

int main() {
	Grid grid(10, 10);

	InitWindow(1600, 800, "tuff");

	while (!WindowShouldClose()) {
		BeginDrawing();
		RenderGrid(grid, {25, 25}, {750, 750});
		EndDrawing();
	}

	CloseWindow();

	return 0;
}