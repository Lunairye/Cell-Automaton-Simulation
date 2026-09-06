
#include "raylib.h"
#include "raymath.h"

#include "automaton.h"

int main() {
	InitWindow(1600, 800, "tuff");

	Automaton automaton(10, 10);

	automaton.renderer.SwapScene(automaton.renderer.currentScene);

	while (!WindowShouldClose()) {
		BeginDrawing();
		automaton.renderer.Update();
		automaton.renderer.Render();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}