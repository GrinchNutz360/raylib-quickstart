/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "Circle.h"
#include <vector> 
#include <Square.h>

int main()
{
    Color currentColor = WHITE;
    float currentSize = 20.0f; 

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(1280, 800, "Hello Raylib");

    SearchAndSetResourceDir("resources");
    Texture wabbit = LoadTexture("wabbit_alpha.png");

    std::vector<Shape*> shapes;
    bool drawCircle = false;
    bool drawSquare = false;

    Shape* previewShape = nullptr;

    while (!WindowShouldClose())
    {

       
        
        if (IsKeyPressed(KEY_R)) currentColor = RED;
        if (IsKeyPressed(KEY_G)) currentColor = GREEN;
        if (IsKeyPressed(KEY_B)) currentColor = BLUE;
        if (IsKeyPressed(KEY_Y)) currentColor = YELLOW;
        if (IsKeyPressed(KEY_W)) currentColor = WHITE;
		if (IsKeyPressed(KEY_P)) currentColor = PURPLE;
        

        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            currentSize += wheel * 5.0f;
        }


        // Input
        if (IsKeyPressed(KEY_C)) {
            drawCircle = true;
            drawSquare = false;
            previewShape = new Circle(GetMousePosition(), currentColor, currentSize);
        }
        if (IsKeyPressed(KEY_S)) {
            drawSquare = true;
            drawCircle = false;
            previewShape = new Square(GetMousePosition(), currentColor, currentSize);
            
        }

        if (previewShape) {
            previewShape->setPosition(GetMousePosition());
            previewShape->setColor(currentColor);     
            previewShape->setSize(currentSize);       
        }

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 pos = GetMousePosition();
            if (drawCircle) {
                shapes.push_back(new Circle(pos, currentColor, currentSize));
            }
            if (drawSquare) {
                shapes.push_back(new Square(pos, currentColor, currentSize));
            }
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        if (previewShape) {
            previewShape->Draw();
        }

        // Draw all shapes
        for (Shape* s : shapes) {
            s->Draw();
        }

        EndDrawing();
    }

    // Cleanup
    for (Shape* s : shapes) delete s;
    UnloadTexture(wabbit);
    CloseWindow();
    return 0;
}


