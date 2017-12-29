#include "UserInput.h"
#include <allegro.h>

UserInput::UserInput()
{
	installKeyboard();
	installMouse();
}

void UserInput::installKeyboard() {
	if (!install_keyboard() == 0) {
		allegro_message("ERROR: Keyboard has not been installed\n", allegro_error);
		allegro_exit();
	}
}
void UserInput::installMouse() {
	if (!install_mouse() == 0) {
		enable_hardware_cursor();
		select_mouse_cursor(MOUSE_CURSOR_QUESTION);
		show_mouse(screen);
	}
	}