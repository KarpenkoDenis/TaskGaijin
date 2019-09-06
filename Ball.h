#pragma once
#include "RectangleBase.h"
class Ball : public RectangleBase
{
	short direction_x = 1;
	short direction_y = -1;
	unsigned speed = 1;
	unsigned max_X = 0;
	unsigned max_Y = 0;
	bool game_over = false;
public:
	Ball(unsigned x = 0, unsigned y = 0, unsigned width = 0, unsigned height = 0);
	void move();
	void set_max(unsigned x, unsigned y);
	bool is_game_over();
	void change_direction_x();
	void change_direction_y();


};

