#include "Rectangle.h"

Rectangle::Rectangle(unsigned x, unsigned y, unsigned width, unsigned height)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
}

unsigned Rectangle::x()
{
	return x_;
}

unsigned Rectangle::y()
{
	return y_;
}

unsigned Rectangle::width()
{
	return width_;
}

unsigned Rectangle::height()
{
	return height_;
}
