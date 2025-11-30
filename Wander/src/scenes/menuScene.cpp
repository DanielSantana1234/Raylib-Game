#include "menuScene.h"
#include "..\systems\inputManager.h"

std::string printHello() {
	return "Hello from menuScene!";
}

void strt_menu() {
	InitWindow(1920, 1080, "Wander");
	ToggleFullscreen();

	int currentMonitor = GetCurrentMonitor();
	int monitorWidth = GetMonitorWidth(currentMonitor);
	int monitorHeight = GetMonitorHeight(currentMonitor);

	bool isFullscreen = false;

	// For the height as well as width of the game art
	Image image = LoadImage("assets/sprites/Sprite-0001.png");
	Texture2D background = LoadTextureFromImage(image);

	Button playButton("assets/sprites/Play-button.png", { 1920 / 2.0f, 1080 / 2.0f }, 10.0f);

	bool playButtonAction = false;

	if (background.id == 0) {
		std::cerr << "error while trying to load the texture!" << std::endl;
	}
	SetTextureFilter(background, TEXTURE_FILTER_POINT);

	int gameWidth = background.width;
	int gameHeight = background.height;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		// Updating mouse pointer position
		Vector2 mousePoint = GetMousePosition();
		playButtonAction = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		if (IsKeyPressed(KEY_F)) {
			if (!isFullscreen) {
				ToggleFullscreen();
				SetWindowSize(800, 640);
			}
			else {
				// SetWindowSize(GetMonitorWidth(currentMonitor), GetMonitorHeight(currentMonitor));
				std::cout << "Monitor Width: " << monitorWidth << "\n";
				std::cout << "Monitor Height: " << monitorHeight << "\n";
				SetWindowSize(1920, 1080);
				ToggleFullscreen();
			}
			isFullscreen = !isFullscreen;
		}

		if (playButton.isPressed(mousePoint, playButtonAction)) {
			std::cout << "It works!" << std::endl;
		}

		BeginDrawing();
		ClearBackground(WHITE);

		// Drawing the background
		DrawTexturePro(
			background,
			Rectangle{ 0, 0, (float)gameWidth, (float)gameHeight}, // So the part of the texture to draw
			Rectangle{ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, // So where to draw the texture on the screen
			Vector2{ 0, 0 },
			0.0f,
			WHITE
		);

		playButton.DrawButton();

		EndDrawing();
	}

	//UnloadRenderTexture(target);
	UnloadTexture(background);
	CloseWindow();
}