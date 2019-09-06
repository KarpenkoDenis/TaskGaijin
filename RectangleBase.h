#pragma once
class RectangleBase
{
protected:
	unsigned x;
	unsigned y;
	unsigned width;
	unsigned height;
public:
	RectangleBase(unsigned x = 0, unsigned y = 0, unsigned width = 0, unsigned height = 0);
	unsigned get_x();
	unsigned get_y();
	unsigned get_width();
	unsigned get_height();
};

