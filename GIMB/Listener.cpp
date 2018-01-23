#include "Listener.h"
#include "Filters.h"


Listener::Listener()
{
	this->mode = 's';
}

void Listener::choice(BITMAP *buffer,Text text, Images *images, Buffer *buff)
{
	if(mouse_b & 1){
		Filters::set_cursor_position_x(mouse_x);
		Filters::set_cursor_position_y(mouse_y);
	} 
	if(key[KEY_P]){
		if(Filters::get_power() < 255)
			Filters::set_power(Filters::get_power() +5);
	}	
	if(key[KEY_L]){
		if(Filters::get_power() > 0)
			Filters::set_power(Filters::get_power() -5);
	}
	if(key[KEY_Q]) mode ='a';
	if(key[KEY_W]) mode ='h';
	if(key[KEY_E]) mode ='v';
	if(key[KEY_R]) mode ='n';
	if(key[KEY_T]) mode ='m';
	if(key[KEY_Y]) mode ='x';
	if(key[KEY_U]) mode ='r';

	if(mode == 'a')
	{
		Filters::linear_filters(buffer,"Mean Filter");
		text.printMatrix();
	}
		
	if(mode == 'h')
	{
		Filters::linear_filters(buffer,"Horizontal Edges");
		text.printMatrix();
	}
		
	if(mode == 'v')
	{
		Filters::linear_filters(buffer,"Vertical Edges");
		text.printMatrix();
	}
		
	if(mode == 'r')
	{
		Filters::linear_filters(buffer,"Random");
		text.printMatrix();
	}
		
	if(mode == 'n')
		Filters::negative_filter(buffer);
	if(mode == 'm')
		Filters::minimal_filter(buffer);
	if(mode == 'x')
		Filters::maxinum_filter(buffer);

	if(key[KEY_S])
		images->saveImage();
	if(key[KEY_I]) 
		text.inputMatrix(buff);
}

Listener::~Listener()
{
}
