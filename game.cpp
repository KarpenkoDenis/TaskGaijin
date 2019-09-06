#include "stdafx.h"
#include "svga/svga.h"
#include <utility>
#include "Rectangle.h"
#include "Player.h"

//This function update full screen from scrptr. The array should be at least sv_height*scrpitch bytes size;
void w32_update_screen(void *scrptr,unsigned scrpitch);

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
extern unsigned int sv_width,sv_height;


Player player;

//These functions called from another thread, when a button is pressed or released
void win32_key_down(unsigned k){
  if(k==VK_F1) game_quited=true;
  if(k== VK_LEFT) player.move_left();
  if(k== VK_RIGHT) player.move_right();
  
	  
}
void win32_key_up(unsigned){}

//This is default fullscreen shadow buffer. You can use it if you want to.
static unsigned *shadow_buf=NULL;


void init_game(){
  shadow_buf=new unsigned [sv_width*sv_height];

  //set start place
  unsigned player_size_width = 50;
  unsigned player_size_height = 20;
  player = Player((sv_width - player_size_width) / 2, 
				  sv_height - player_size_height * 2, 
				  player_size_width, 
				  player_size_height);
  player.set_max_X(sv_width);
}

void close_game(){
  if(shadow_buf) delete shadow_buf;
  shadow_buf=NULL;
}

void draw_rectangle(unsigned x, unsigned y, unsigned width, unsigned height)
{
	for (size_t i = y; i < y + height; i++)
	{
		memset(shadow_buf + i* sv_width + x , 250, width * 4);
	}
}

//draw the game to screen
void draw_game(){
  if(!shadow_buf)return;
  memset(shadow_buf,0,sv_width*sv_height*4);
  
  //here you should draw anything you want in to shadow buffer. (0 0) is left top corner

  //draw_rectangle(100, 30, 100, 100);
  draw_rectangle(player.get_x(), player.get_y(), player.get_width(), player.get_height());

  w32_update_screen(shadow_buf,sv_width*4);
}

//act the game. dt - is time passed from previous act
void act_game(float dt){
}
