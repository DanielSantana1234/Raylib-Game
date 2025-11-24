#include "menuScene.h"

std::string printHello() {
	return "Hello from menuScene!";
}

void strt_menu() {
	int currentMonitor = GetCurrentMonitor();
	int monitorWidth = GetMonitorWidth(currentMonitor);
	int monitorHeight = GetMonitorHeight(currentMonitor);

	// InitWindow(800, 450, "Wander");
	InitWindow(monitorWidth, monitorHeight, "Wander");
	ToggleFullscreen();

	bool isFullscreen = false;

	// For the height as well as width of the game art
	Texture2D background = LoadTexture("C:\\Users\\danie\\Downloads\\Wander\\Wander\\assets\\sprites\\Sprite-0001.png");

	// Creating a render texture at the pixel art resolution
	// RenderTexture2D target = LoadRenderTexture(gameWidth, gameHeight);
	// SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

	// Image image = LoadImage("C:\\Users\\danie\\Downloads\\Wander\\Wander\\assets\\sprites\\Sprite-0001.png");
	// Texture2D background = LoadTexture("C:\\Users\\danie\\Downloads\\Wander\\Wander\\assets\\sprites\\Sprite-0001.png");
	if (background.id == 0) {
		std::cerr << "error while trying to load the texture!" << std::endl;
	}
	SetTextureFilter(background, TEXTURE_FILTER_POINT);

	int gameWidth = background.width;
	int gameHeight = background.height;
	

	SetTargetFPS(60);

	std::cout << "Monitor Width: " << monitorWidth << "\n";
	std::cout << "Monitor Height: " << monitorHeight << "\n";

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_F)) {
			if (!isFullscreen) {
				ToggleFullscreen();
				SetWindowSize(800, 640);
			}
			else {
				SetWindowSize(GetScreenWidth(), GetScreenHeight());
				ToggleFullscreen();
			}
			isFullscreen = !isFullscreen;
		}

		/*BeginTextureMode(target);
		ClearBackground(WHITE);
		DrawTexture(target.texture, 0, 0, WHITE);
		EndTextureMode();*/

		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexturePro(
			background,
			Rectangle{ 0, 0, (float)gameWidth, (float)gameHeight}, // So the part of the texture to draw
			Rectangle{ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, // So where to draw the texture on the screen
			Vector2{ 0, 0 },
			0.0f,
			WHITE
		);
		//DrawTextureEx(background, { 0, 0 }, 0, 7, WHITE);
		EndDrawing();
	}

	//UnloadRenderTexture(target);
	UnloadTexture(background);
	CloseWindow();
}