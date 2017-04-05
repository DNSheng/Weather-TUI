#include <stdlib.h>
#include <ncurses.h>

#include "locale.h"
#include "draw_main.h"
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

	/* Testing draw functions */
	int x, y;
	getyx(stdscr, y, x);
	xydraw_sunny(0, y+2);
	getyx(stdscr, y, x);
	xydraw_cloudy(0, y+2);
	getyx(stdscr, y, x);
	xydraw_drizzle(0, y+2);
	getyx(stdscr, y, x);
	xydraw_partly_cloudy(0, y+2);
	getyx(stdscr, y, x);
	xydraw_rain(0, y+2);
	refresh_main();
	/* End of debug functions */
	
	for(;;)
	{
		/* Hide cursor and keypresses to screen */
		cbreak();
		noecho();
		curs_set(0);
		/* Get input to update model and refresh */
		main_screen_input();
		refresh_main();
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

/*===============================================================
 * Drawing stuff
 * ==============================================================
 */

/*
 * Given top left x and y coords, draw an ASCII sunny weather icon
 */
void xydraw_sunny(int x, int y)
{
	attron(COLOR_PAIR(SUNNY_YELLOW));
	mvprintw(y+1, x+4, ".-.");
	mvprintw(y+2, x+3, "(   )");
	mvprintw(y+3, x+4, "`-’");

	attron(A_BLINK);
	mvprintw(y, x+3, "\\   /");
	mvprintw(y+2, x, "――");
	mvprintw(y+2, x+9, "――");
	mvprintw(y+4, x+3, "/   \\");
	attroff(A_BLINK);

	attroff(COLOR_PAIR(SUNNY_YELLOW));
}

/*
 * Given top left x and y coords, draw an ASCII cloud covering sun
 */
void xydraw_partly_cloudy(int x, int y)
{
	/* Draw the sun */
	attron(COLOR_PAIR(SUNNY_YELLOW));
	attron(A_BLINK);
	mvprintw(y, x+2, "\\  /");
	mvprintw(y+1, x, "_");
	mvprintw(y+3, x+2, "/");
	attroff(A_BLINK);
	mvprintw(y+1, x+2, "/\"\"");
	mvprintw(y+2, x+2, "\\_");
	attroff(COLOR_PAIR(SUNNY_YELLOW));
	
	/* Draw the cloud */
	attron(COLOR_PAIR(CLOUDY_GREY));
	mvprintw(y+1, x+6, ".-.");
	mvprintw(y+2, x+5, "(   ).");
	mvprintw(y+3, x+4, "(___(__)");
	attroff(COLOR_PAIR(CLOUDY_GREY));
}

/*
 * Given top left x and y coords, draw an ASCII cloud
 */
void xydraw_cloudy(int x, int y)
{
	attron(COLOR_PAIR(CLOUDY_GREY));
	mvprintw(y, x+4, ".--.");
	mvprintw(y+1, x+1, ".-(    ).");
	mvprintw(y+2, x, "(___.__)__)");
	attroff(COLOR_PAIR(CLOUDY_GREY));
}

/*
 * Given top left x and y coords, draw an ASCII sunny drizzle
 */
void xydraw_drizzle(int x, int y)
{
	/* Draw the sun */
	attron(COLOR_PAIR(SUNNY_YELLOW));
	attron(A_BLINK);
	mvprintw(y, x, "_`");
	mvprintw(y, x+3, "\"\"");
	mvprintw(y+1, x+1, ",");
	mvprintw(y+2, x+2, "/");
	attroff(A_BLINK);
	mvprintw(y, x+2, "/");
	mvprintw(y+1, x+2, "\\_");
	attroff(COLOR_PAIR(SUNNY_YELLOW));
	
	/* Draw the cloud */
	attron(COLOR_PAIR(CLOUDY_GREY));
	mvprintw(y, x+5, ".-.");
	mvprintw(y+1, x+4, "(   ).");
	mvprintw(y+2, x+3, "(___(__)");
	attroff(COLOR_PAIR(CLOUDY_GREY));
	
	/* Draw raindrops */
	attron(COLOR_PAIR(RAINY_BLUE));
	attron(A_BLINK);
	mvprintw(y+3, x+3, "` ` ` ` `");
	mvprintw(y+4, x+4, "` ` ` ` `");
	attroff(A_BLINK);
	attroff(COLOR_PAIR(RAINY_BLUE));
}

/*
 * Given top left x and y coords, draw an ASCII cloud
 */
void xydraw_rain(int x, int y)
{
	/* Draw the cloud */
	attron(COLOR_PAIR(CLOUDY_GREY));
	mvprintw(y, x+4, ".--.");
	mvprintw(y+1, x+1, ".-(    ).");
	mvprintw(y+2, x, "(___.__)__)");
	attroff(COLOR_PAIR(CLOUDY_GREY));
	
	/* Draw the rain */
	attron(COLOR_PAIR(RAINY_BLUE));
	mvprintw(y+3, x, "` ` ` ` ` `");
	mvprintw(y+4, x, "` ` ` ` ` `");
	attroff(COLOR_PAIR(RAINY_BLUE));
}
