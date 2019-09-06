#include "Ball.h"



Ball::Ball(unsigned x, unsigned y, unsigned width, unsigned height) : RectangleBase(x, y, width, height)
{
}

void Ball::move()
{
	unsigned next_x = x + speed * direction_x;
	unsigned next_y = y + speed * direction_y;

	if (next_x + width > max_X)
	{
		change_direction_x();
		return;
	} else if (next_x <= 0)
	{
		change_direction_x();
		return;
	}

	if (next_y + height > max_Y)
	{
		game_over = true;
		return;
	} else	if (next_y <= 0)
	{
		change_direction_y();
		return;
	}
	x = next_x;
	y = next_y;

}

void Ball::set_max(unsigned x, unsigned y)
{
	max_X = x;
	max_Y = y;
}

bool Ball::is_game_over()
{
	return game_over;
}

void Ball::change_direction_x()
{
	direction_x = -direction_x;
}

void Ball::change_direction_y()
{
	direction_y = -direction_y;
}
