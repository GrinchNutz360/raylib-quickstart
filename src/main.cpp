/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <vector>

const int screenWidth = 800;
const int screenHeight = 800;

const int gridWidth = 80;
const int gridHeight = 80;

const float cellWidth = screenWidth/(float)gridHeight;
const float cellHeight = screenHeight / (float)gridHeight;

using Cells = std::vector<bool>;

bool ReadCell(int x, int y, const Cells& cells)
{
	if (x < 0) x = gridWidth - 1;
	else if (x > gridWidth - 1) x = 0;

	if (y < 0) y = gridHeight - 1;
	else if (y > gridHeight - 1) y = 0;

	return cells[x + (y * gridWidth)];
}

void WriteCell(int x, int y, bool value, Cells& cells)
{
	cells[x + (y * gridWidth)] = value;
}

void RandomizeCells(Cells& cells) 
{
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i] = (GetRandomValue(0, 1) == 1);
	}
}

int CountLiveNeighbors(int x, int y, const Cells& cells)
{
	int count = 0;
	
	if (ReadCell(x - 1, y - 1, cells)) count++;
	if (ReadCell(x, y - 1, cells)) count++;
	if (ReadCell(x + 1 , y - 1, cells)) count++;

	if (ReadCell(x - 1 , y, cells)) count++;
	if (ReadCell(x + 1 , y, cells)) count++;

	if (ReadCell(x - 1 , y + 1, cells)) count++;
	if (ReadCell(x, y + 1, cells)) count++;
	if (ReadCell(x + 1 , y + 1, cells)) count++;

	return count;
}

int main ()
{

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Game of Life");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	Cells currentGeneration(gridWidth * gridHeight);
	Cells nextGeneration(gridWidth * gridHeight);

	RandomizeCells(currentGeneration);

	
	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		std::fill(nextGeneration.begin(), nextGeneration.end(), false);

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		for (int y = 0; y < gridHeight; y++)
		{
			for (int x = 0; x < gridWidth; x++)
			{
				if (ReadCell(x, y, currentGeneration))
				{
					DrawRectangle((int)(x * cellWidth), (int)(y * cellHeight), cellWidth, cellHeight, WHITE);
				}
			}
		}

		// draw some text using the default font
		DrawText("Space: Randomize", 40, 20, 20,WHITE);
		DrawFPS(40, 40);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
