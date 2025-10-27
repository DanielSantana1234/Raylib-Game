#include "menuScene.h"

std::string printHello() {
	return "Hello from menuScene!";
}

void strt_menu() {
	int currentMonitor = GetCurrentMonitor();
	int monitorWidth = GetMonitorWidth(currentMonitor);
	int monitorHeight = GetMonitorHeight(currentMonitor);

	InitWindow(monitorWidth, monitorHeight, "Menu Scene");
	ToggleFullscreen();

	bool isFullscreen = true;
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_F)) {
			if (!isFullscreen) {
				int monitorWidth = GetMonitorWidth(currentMonitor); // Why can this not be global?
				int monitorHeight = GetMonitorHeight(currentMonitor);
				SetWindowSize(monitorWidth, monitorHeight);
				ToggleFullscreen();
				isFullscreen = true;
			}
			else {
				ToggleFullscreen();
				SetWindowSize(800, 640);
				isFullscreen = false;
			}
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}
	CloseWindow();
}