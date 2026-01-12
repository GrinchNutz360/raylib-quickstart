#include "Square.h"

void Square::Update()
{
}

void Square::Draw()
{
	DrawRectangleV(position, Vector2{ size, size }, this->color);
	
}

