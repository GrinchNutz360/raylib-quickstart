#pragma once
#include "raylib.h"
#include "Shape.h"
#include <vector>

class Square : public Shape {
public:
	Square() = default;
	Square(const Vector2& position, const Color& color, float size = 40) :
		Shape(position, color, size) {
	}

	// Inherited via Shape
	void Update() override;
	void Draw() override;
	Type getType() override { return Type::Square; }
};
