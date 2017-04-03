#include <ncurses.h>

#include "locale.h"
#include "draw_main.h"
#include "input_handler.h"

/*
 * A once-called function to create the main window
 * Called by main()
 */
void initialize_main()
{
	setlocale(LC_CTYPE, "");
	initscr();
	printw("Weather App - Initial build");
	draw_main_window();
}

/*
 * Runs routines to draw and format
 * Refreshes for new input
 * Calls Input.h to handle input
 */
void draw_main_window()
{
	// Run routines to draw here
	refresh();
	// Hide cursor and don't print presses to screen
	cbreak();
	noecho();
	curs_set(0);
	// Move to handle input using input_handler.h
	main_screen_input();
	// Move endwin() to the exit function in Input.h
	endwin();
}

void error_message(char *message)
{

}

void draw_sunny(int x, int y)
{
}
