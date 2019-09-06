#include "Rectangle.h"

Rectangle::Rectangle(unsigned x=0, unsigned y=0, unsigned width=0, unsigned height=0)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

unsigned Rectangle::get_x()
{
	return x;
}

unsigned Rectangle::get_y()
{
	return y;
}

unsigned Rectangle::get_width()
{
	return width;
}

unsigned Rectangle::get_height()
{
	return height;
}
