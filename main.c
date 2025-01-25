/*******************************************************************************************
 *
 *   raylib [text] example - Text formatting
 *
 *   Example complexity rating: [★☆☆☆] 1/4
 *
 *   Example originally created with raylib 1.1, last time updated with raylib 3.0
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/
#include <raylib.h>

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 400;

	InitWindow(screenWidth, screenHeight, "buffer");

	int x = 0, y = 0;

	SetTargetFPS(60);

	Vector2 pos, size;
	Font f = GetFontDefault();
	size.x = 25;
	size.y = 40;
	float blink = 0.0f;

	char lines[10][33];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 32; j++) {
			lines[i][j] = ' ';
		}
		lines[i][32] = '\0';
	}

	while (!WindowShouldClose()) {
		blink += GetFrameTime();
		if (IsKeyPressed(KEY_RIGHT)) {x += 1;}
		if (IsKeyPressed(KEY_LEFT)) {x -= 1;}
		if (IsKeyPressed(KEY_UP)) {y -= 1;}
		if (IsKeyPressed(KEY_DOWN)) {y += 1;}
		int key = GetCharPressed();

		// Check if more characters have been pressed on the same frame
		while (key > 0)
		{
			// NOTE: Only allow keys in range [32..125]
			if (key >= 32 && key <= 125)
			{
				lines[y % 10][x % 32] = (char)key;
			}

			key = GetCharPressed();  // Check next character in the queue
		}

		pos.x = x * 25;
		pos.y = y * 40;
		BeginDrawing();
			if (blink < 0.5f) {
				DrawRectangleV(pos, size, BLACK);  
			} else if (blink < 1.0f) {
				// DO nothing
			} else {
				blink = 0.0f;
			}
	
			ClearBackground(RAYWHITE);
	
			for (int i = 0; i < 10; i++) {
				DrawText(lines[i], 0, i * 40, 38, BLACK);
			}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
