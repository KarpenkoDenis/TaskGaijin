#pragma once
class Rectangle
{
protected:
	unsigned x;
	unsigned y;
	unsigned width;
	unsigned height;
public:
	Rectangle(unsigned x, unsigned y, unsigned width, unsigned height);
	unsigned get_x();
	unsigned get_y();
	unsigned get_width();
	unsigned get_height();
};

