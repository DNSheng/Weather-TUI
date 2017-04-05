#include <stdlib.h>
#include <ncurses.h>

#include "locale.h"
#include "draw_main.h"
#include "draw_images.h"
#include "input_handler.h"
#include "weather_model.h"

/*
 * A once-called function to create the main window and handle input, and
 * update the view. It is called by main()
 */
void initialize_main()
{
	setlocale(LC_CTYPE, "");
	initscr();
	printw("Weather App - Initial build");
	if (!has_colors())
	{
		printw("Warning - Your terminal does not support colors");
		throw_error(COLOR_NOT_SUPPORTED);

	}
	start_color();
	initialize_colors();

	/* Draw a box */
	box(stdscr, ACS_VLINE, ACS_HLINE);
	/* Testing draw functions */
	refresh();
	/* End of debug functions */
	
	for(;;)
	{
		/* Hide cursor and keypresses to screen */
		cbreak();	/* What does this do again? */
		noecho();
		curs_set(0);
		/* Get input to update model and refresh */
		main_screen_input();
		refresh();
	}
}

void initialize_colors()
{
	use_default_colors();
	init_color(GREY, 675, 675, 675);
	init_color(BLUE, 280, 600, 1000);

	init_pair(SUNNY_YELLOW, COLOR_YELLOW, DEFAULT_BACKGROUND_COLOR);
	init_pair(CLOUDY_GREY, GREY, DEFAULT_BACKGROUND_COLOR);
	init_pair(RAINY_BLUE, BLUE, DEFAULT_BACKGROUND_COLOR);
}
/*
 * Updates and refreshes main window after each model update
 */
void refresh_main()
{
	/* Run various draw routines, then refresh the window*/
	erase();
	box(stdscr, ACS_VLINE, ACS_HLINE);
	int x, y;
	getyx(stdscr, y, x);
	xydraw_sunny(3, y+2);
	getyx(stdscr, y, x);
	xydraw_cloudy(3, y+2);
	getyx(stdscr, y, x);
	xydraw_drizzle(3, y+2);
	getyx(stdscr, y, x);
	xydraw_partly_cloudy(3, y+2);
	getyx(stdscr, y, x);
	xydraw_rain(3, y+2);
	getyx(stdscr, y, x);
	xydraw_heavy_rain(3, y+2);
	refresh();
}

/*
 * Print out a brief error message in red at the bottom.
 * Leave for few seconds and erase, or erase with new user input.
 */
void error_message(char *message)
{

}

/*
 * Exit the program, designated here as it calls endwin();
 */
void quit()
{
	endwin();
	exit(0);
}
