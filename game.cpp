#include "stdafx.h"
#include "svga/svga.h"
#include <utility>
#include "RectangleBase.h"
#include "Player.h"
#include "Ball.h"
#include "Wall.h"

//This function update full screen from scrptr. The array should be at least sv_height*scrpitch bytes size;
void w32_update_screen(void* scrptr, unsigned scrpitch);

//If this variable sets to true - game will quit

extern bool game_quited;

// these variables provide access to joystick and joystick buttons
// In this version joystick is simulated on Arrows and Z X buttons

// [0]-X axis (-501 - left; 501 - right)
// [1]-Y axis (-501 - left; 501 - right)
extern int gAxis[2];
//0 - not pressed; 1 - pressed
extern int gButtons[6];

//sv_width and sv_height variables are width and height of screen
extern unsigned int sv_width, sv_height;


Player player;
Ball ball;
Wall* wall;

//These functions called from another thread, when a button is pressed or released
void win32_key_down(unsigned k) {
	if (k == VK_F1) game_quited = true;
	if (k == VK_LEFT) player.move_left();
	if (k == VK_RIGHT) player.move_right();


}
void win32_key_up(unsigned) {}

//This is default fullscreen shadow buffer. You can use it if you want to.
static unsigned* shadow_buf = NULL;

void start_game()
{
	//set start place
	unsigned player_size_width = 50;
	unsigned player_size_height = 20;
	player = Player((sv_width - player_size_width) / 2,
		sv_height - player_size_height * 2,
		player_size_width,
		player_size_height);
	player.set_max_X(sv_width);

	unsigned ball_size = 30;
	ball = Ball((sv_width - ball_size) / 2,
		(sv_height - ball_size) / 2,
		ball_size,
		ball_size);
	ball.set_max(sv_width, sv_height);
	wall = new Wall(100, 50);
}

void init_game() {
	shadow_buf = new unsigned[sv_width * sv_height];
	start_game();
}



void close_game() {
	if (shadow_buf) delete shadow_buf;
	shadow_buf = NULL;
}

void draw_rectangle(unsigned x, unsigned y, unsigned width, unsigned height)
{
	for (size_t i = y; i < y + height; i++)
	{
		memset(shadow_buf + i * sv_width + x, 250, width * 4);
	}
}

//draw the game to screen
void draw_game() {
	if (!shadow_buf)return;
	memset(shadow_buf, 0, sv_width * sv_height * 4);

	//here you should draw anything you want in to shadow buffer. (0 0) is left top corner

	//draw_rectangle(100, 30, 100, 100);
	draw_rectangle(player.get_x(), player.get_y(), player.get_width(), player.get_height());
	draw_rectangle(ball.get_x(), ball.get_y(), ball.get_width(), ball.get_height());

	for (auto curr : wall->blocks)
	{
		draw_rectangle(curr.get_x(), curr.get_y(), curr.get_width(), curr.get_height());
	}

	w32_update_screen(shadow_buf, sv_width * 4);
}

bool is_crossing(RectangleBase* first, RectangleBase* second)
{
	if (ball.get_y() + ball.get_height() > first->get_y() && ball.get_y() < first->get_y() + first->get_height())
	{

		if (((second->get_x() > first->get_x() && second->get_x() < first->get_x() + first->get_width()) ||

			(second->get_x() + second->get_width() > first->get_x() && second->get_x() + second->get_width() < first->get_x() + first->get_width())))
		{
			return true;
		}
	}
	return false;
}

//act the game. dt - is time passed from previous act
void act_game(float dt) {
	static const  float time_interval = 0.03;
	static float time_to_move = 0;
	time_to_move += dt;
	//move every time_interval seconds
	if (time_to_move > time_interval)
	{
		ball.move();
		time_to_move = 0;
		if (ball.is_game_over())
		{
			start_game();
		}
		if (is_crossing(&player, &ball))
		{
			ball.change_direction_y();
			ball.move();
		}
		for (auto block = wall->blocks.begin(); block != wall->blocks.end(); block++)
		{
			if (is_crossing(&(*block), &ball))
			{
				ball.change_direction_y();
				wall->blocks.erase(block);
				break;
			}
		}


	}
}
