
#include "Engine.h"
#include "UserInput.h"
#include "Text.h"
#include "Font.h"
#include "Buffer.h"
#include "Timer.h"
#include "Images.h"
#include "Listener.h"
#include "Filters.h"


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
	Timer t(1000);
	Listener lis;

	
	while (!exit)
	{
		while ( t.getCount()> 0 ) {
			Text.print("by Zwierzu & Lisu", 1000, 690, 0, 204, 0);
			Text.print(Filters::to_string_cursor_position(), 50, 20, 0, 204, 0);
			Text.print("Moc rozdzki", 250, 0, 0, 204, 0);
			Text.print(Filters::to_string_power(), 250, 20, 0, 204, 0);
			Text.print("1 - usredniajacy 2 - krawedzie poziome 3 - krawdzie pionowe 4 - negatyw 5 - minimalny 6 - max", 0, 50, 0, 40, 0);
			Text.print("7 - random 8 - losowane macierzy P - moc rozdzki + L - moc rozdzki -", 0, 75, 0, 40, 0);
			i.printImage(100, 160, 512,512);
			lis.choice(buffer);
			buff.clear();

			t.decreaseCount();
			
			if(key[KEY_ESC])
			{
				exit = true;
				break;
			}
				
		}
	}
	
}