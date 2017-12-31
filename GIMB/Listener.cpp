#include "Listener.h"
#include "Filters.h"


Listener::Listener()
{
	this->mode = 's';
}

void Listener::choice(BITMAP *buffer)
{

	if(key[KEY_1]) mode ='s';
	if(key[KEY_2]) mode ='c';
	if(mode == 's')
		Filters::average_filter(buffer);
	
}


Listener::~Listener()
{
}
