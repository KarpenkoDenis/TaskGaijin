#include "Player.h"

Player::Player(unsigned x, unsigned y, unsigned width, unsigned height):RectangleBase(x, y, width, height)
{
}

void Player::move_left()
{
	if(this->x > 0)
		this->x -= speed;
}

void Player::move_right()
{
	if (this->x < max_X)
		this->x += speed;
}

void Player::set_max_X(unsigned max_X)
{
	this->max_X = max_X;
}

