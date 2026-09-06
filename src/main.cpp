
#include "raylib.h"
#include "raymath.h"

#include "application.h"

int main() {
	InitWindow(1600, 800, "tuff");

	Application application(10, 10);

	application.renderer.SwapScene(application.renderer.currentScene);

	while (!WindowShouldClose()) {
		BeginDrawing();
		application.renderer.Update();
		application.renderer.Render();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}