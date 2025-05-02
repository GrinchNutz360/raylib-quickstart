#pragma once
#include "raylib.h"
class Shape {
public: 
	enum class Type {
		Circle,
		Square,
	};
public:
	Shape() = default;
	Shape(const Vector2& position, const Color& color = WHITE, float size = 20) :
		position(position), color(color), size(size) {
	}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual Type getType() = 0;

	const Vector2& getPosition() const {
		return position;
	}
	void setPosition(const Vector2& position) {
		this->position = position;
	}

	float getSize() const {
		return size;
	}
	void setSize(float size) {
		this->size = size;
	}

	const Color& getColor() const {
		return color;
	}
	void setColor(const Color& color) {
		this->color = color;
	}
protected:
	Vector2 position = { 0, 0 };
	float size = 20;
	Color color = WHITE;

};