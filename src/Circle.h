#pragma once
#include "raylib.h"
#include "Shape.h"

class Circle : public Shape{
public:
	Circle() = default;
	Circle(const Vector2& position, const Color& color, float size = 20) :
		Shape(position, color, size) {
	}

	void Update() override;

	void Draw() override;

	Type getType() override { return Type::Circle; }

};
