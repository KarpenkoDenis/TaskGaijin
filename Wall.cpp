
#include "Wall.h"

Wall::Wall(unsigned x, unsigned y)
{
	for (size_t i = 0; i < count; i++)
	{
		blocks.push_back(RectangleBase(x + (block_size + indent) * i, y, block_size, block_size));

	}
}

