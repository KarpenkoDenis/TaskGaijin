#pragma once
#include "RectangleBase.h"
#include <vector>

class Wall
{
public:
	std::vector<RectangleBase> blocks;
	unsigned block_size=40;
	unsigned indent = 20;
	unsigned count = 8;

public:
	Wall(unsigned x, unsigned y);
	

};
