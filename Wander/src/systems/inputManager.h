#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>
using std::cout;
using std::endl;
#include <raylib.h>

class Button {
public:
	Button(const char* imageFilePath, Vector2 imagePosition, float scale);
	~Button();
	void DrawButton();
	bool isPressed(Vector2 MousePos, bool mousePressed);
private:
	Texture2D texture;
	Vector2 position;
};

#endif