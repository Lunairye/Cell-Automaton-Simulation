
#include "raylib.h"
#include "raymath.h"

#include "automaton.h"

int main() {
	Automaton automaton(10, 10);

	InitWindow(1600, 800, "tuff");

	while (!WindowShouldClose()) {
		BeginDrawing();
		automaton.renderer.Render();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}