#include "RectangleBase.h"

RectangleBase::RectangleBase(unsigned x, unsigned y, unsigned width, unsigned height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

unsigned RectangleBase::get_x()
{
	return x;
}

unsigned RectangleBase::get_y()
{
	return y;
}

unsigned RectangleBase::get_width()
{
	return width;
}

unsigned RectangleBase::get_height()
{
	return height;
}
