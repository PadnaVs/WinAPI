#define _USE_MATH_DEFINES
#include "Vector2D.h"

float Vector2D::getLenght() {
	lenght = sqrt(x*x + y*y);
	return lenght;
};

void Vector2D::show(HDC& hdc) {
	POINT pt;
	MoveToEx(hdc, 0, 0, &pt);
	LineTo(hdc, x, y);
};

float Vector2D::getAngle() {
	return (atan2((double)(x), (double)(y))) * (180 / M_PI);
};

void Vector2D::rotation(float angle) {
	angle *= M_PI / 180;
	float rx = x * sinf(angle) - y * cosf(angle);
	float ry = x * cosf(angle) + y * sinf(angle);
	
	x = rx;
	y = ry;
};

Vector2D Vector2D::operator-(Vector2D v) {
	return Vector2D((x - v.x), (y - v.y));
};
Vector2D Vector2D::operator*(Vector2D v) {
	return Vector2D((x * v.x), (y * v.y));
};
Vector2D Vector2D::operator+(Vector2D v) {
	return Vector2D((x + v.x), (y + v.y));
};
Vector2D Vector2D::operator*(float s) {
	return Vector2D((x * s), (y * s));
};
Vector2D Vector2D::operator+=(Vector2D v) {
	x += v.x;
	y += v.y;
	return *this;
};
bool Vector2D::operator==(Vector2D v) {
	if (x == v.x && y == v.y) {
		return true;
	}
	else {
		return false;
	}
}
bool Vector2D::operator<(Vector2D v) {
	if (x < v.x || y < v.y) {
		return true;
	}
	else {
		return false;
	}
}

Vector2D Vector2D::Normal() {
	getLenght();
	return Vector2D(x / lenght, y / lenght);
};

