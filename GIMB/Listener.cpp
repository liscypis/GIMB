#include "Listener.h"
#include "Filters.h"


Listener::Listener()
{
	this->mode = 's';
}

void Listener::choice(BITMAP *buffer)
{
	if(mouse_b & 1){
		Filters::set_cursor_position_x(mouse_x);
		Filters::set_cursor_position_y(mouse_y);
	} 
	if(mouse_b & 2){
		Filters::set_power(Filters::get_power() -10);
	}	
	if(key[KEY_1]) mode ='a';
	if(key[KEY_2]) mode ='h';
	if(key[KEY_3]) mode ='v';
	if(key[KEY_4]) mode ='n';
	if(key[KEY_5]) mode ='m';
	if(key[KEY_6]) mode ='r';
	if(key[KEY_7]) mode ='x';
	if(key[KEY_8]) Filters::fill_array();
	if(mode == 'a')
		Filters::linear_filters(buffer,"Mean Filter");
	if(mode == 'h')
		Filters::linear_filters(buffer,"Horizontal Edges");
	if(mode == 'v')
		Filters::linear_filters(buffer,"Vertical Edges");
	if(mode == 'r')
		Filters::linear_filters(buffer,"Random");
	if(mode == 'n')
		Filters::negative_filter(buffer);
	if(mode == 'm')
		Filters::minimal_filter(buffer);
	if(mode == 'x')
		Filters::maxinum_filter(buffer);
}

Listener::~Listener()
{
}
