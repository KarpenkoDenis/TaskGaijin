#pragma once

#include "RectangleBase.h"

class Player: public RectangleBase
{
	unsigned speed = 3;
	unsigned max_X = 0;
public:
	Player(unsigned x=0, unsigned y=0, unsigned width=0, unsigned height=0);
	void move_left();
	void move_right();
	void set_max_X(unsigned max_X);
};

