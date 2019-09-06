#pragma once
class Rectangle
{
private:
	unsigned x_;
	unsigned y_;
	unsigned width_;
	unsigned height_;
public:
	Rectangle(unsigned x, unsigned y, unsigned width, unsigned height);
	unsigned x();
	unsigned y();
	unsigned width();
	unsigned height();
};

