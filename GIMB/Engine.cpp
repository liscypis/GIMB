#include "Engine.h"
#include "UserInput.h"
#include "Text.h"
#include "Font.h"
#include "Buffer.h"
#include "Timer.h"
#include "Images.h"

Engine::Engine(const char* title, int x, int y)
{
	this->x = x;
	this->y = y;
	createWindow(title, x, y, vX, vY);
	UserInput u;
	running();
	deleteWindow();
}
Engine::~Engine()
{
	deleteWindow();
}


void Engine::createWindow(const char* title, int x, int y, int vX, int vY) {

	if (!allegro_init() == 0){
		allegro_message("ERROR: Window has not been created\n", allegro_error);
		allegro_exit();
	}
	set_color_depth(32);
	set_window_title(title);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, x, y, vX, vY);
}
void Engine::createWindow(char title, int x, int y, int vX, int vY, char* mode) {

	if (!allegro_init() == 0) {
		allegro_message("ERROR: Window has not been created\n", allegro_error);
		allegro_exit();
	}
	set_color_depth(32);
	set_window_title(&title);
	if(mode=="fullscreen")
		set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, x, y, vX, vY);
	else if(mode=="windowed")
		set_gfx_mode(GFX_AUTODETECT_WINDOWED, x, y, vX, vY);
	else {
		allegro_message("ERROR: Can't specify display mode\n", allegro_error);
		allegro_exit();
	}
}
void Engine::deleteWindow() {
	allegro_exit();
}

void Engine::running() {
	Buffer buff, buffB;
	BITMAP *buffer = buff.getBuff();
	BITMAP *bufferB = buffB.getBuff();
	Font Font("OpenSansXL.pcx");
	Images i(buffer, "Sample.bmp");
	Text Text(buffer, *Font.getFont());
	Timer t(2555);

	while (-1)
	{
		while ( t.getCount()> 0 ) {
			Text.print("by Zwierzu & Lisu", 1000, 690, 52, 152, 219);
			i.printImage(365, 160, 600,400);
			buff.clear();
			t.decreaseCount();
		}
	}
}