#include "inputManager.h"

Button::Button(const char* imageFilePath, Vector2 imagePosition, float scale) {
	Image image = LoadImage(imageFilePath);

	int originalWidth = image.height;
	int originalHeight = image.width;

	int newWidth = static_cast<int>(originalWidth * scale);
	int newHeight = static_cast<int>(originalHeight * scale);

	ImageResize(&image, newWidth, newHeight);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	position = imagePosition;
}

Button::~Button() {
	UnloadTexture(texture);
}

void Button::DrawButton() {
	DrawTextureV(texture, position, WHITE);
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {
	Rectangle rect = { position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height) };

	if (CheckCollisionPointRec(mousePos, rect) && mousePressed) {
		return true;
	}
	return false;
}