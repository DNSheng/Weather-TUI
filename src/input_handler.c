#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "draw_main.h"
#include "input_handler.h"
#include "weather_model.h"

/*
 * Get keypresses in main window where:
 * 	- ':'		Lets users enter commands
 * 	- 'q'		Gives users an exit prompt
 * 	- 'c'		Changes to celsius
 * 	- 'f'		Changes to farenheit
 * 	- other		Does nothing
 * Once finished, routine exits back to draw_main_window();
 */
void main_screen_input()
{
	int inputChar = getch();
	switch (inputChar) {
		case 58:
			// ':' pressed
			get_command();
			break;
		case 81:
			// 'Q' pressed
			quit();
		case 113:
			// 'q' pressed
			quit();
		case 99:
			// 'c' pressed for celsius
			break;
		case 102:
			// 'f' pressed for farenheit
			break;
		default:
			break;
	}
}

/*
 * Get a user command in the form of a string
 * Parse string for command and associated arguments
 * Modify model with user input
 * Currently writes command to window for debugging purposes
 */
void get_command()
{
	int x_size, y_size;
	int current_x, current_y;

	/* Size 256 for now, may change to something flexible in the future */
	char command_str[256];
	
	/* Store locations for cursor traversal */
	getmaxyx(stdscr, y_size, x_size);
	getyx(stdscr, current_y, current_x);

	/* Move to botton of screen */
	wmove(stdscr, y_size-1, 0);
	clrtoeol();
	printw(":");

	/* Show input and cursor */
	echo();
	curs_set(1);

	/* TODO: Detect when escape is pressed and go back */
	getnstr(command_str, sizeof command_str);

	/* Parse the command */
	parse_command(command_str);

	/* Bottom line to remove fragments after entering */
	clrtoeol();

	/* Go back to previous location and print command (DEBUG)*/
	wmove(stdscr, current_y+1, 0);
	//printw("%s", command_str);
}

/*
 * Compare a_command with all programmed commands from header file
 * Update model for each command
 * View updated in parent function get_
 */
void parse_command(char a_command[256])
{
	int i, x, y;
	if (match_command(a_command, "set")) {
		//Call the set command from the model
		match_argument(a_command);
	} else if (match_command(a_command, "draw")) {
		refresh_main();
	} else if (match_command(a_command, "clear")) {
		erase();
	} else if (match_command(a_command, "view")) {
		/* Change the view to:
		 * 	- Simple
		 * 	- Today
		 * 	- Hourly
		 * 	- Week
		 */
		match_argument(a_command);
	} else if (match_command(a_command, "quit")) {
		quit();
	} else if (match_command(a_command, "q")) {
		quit();
	} else if (match_command(a_command, "help")) {
		//Call help command from the model
		i++;
	} else {
		//Command not found, print in red text and show for few secs, delete
		printw("Command not recognized...");
		i++;
	}
}

/*
 * Return 1 if the user input called prog_command
 * Return 0 otherwise (command not called)
 */
int match_command(char a_command[], const char* prog_command)
{
	size_t a_size= strlen(a_command);
	size_t size = strlen(prog_command);
	char *command = (char *) malloc(size);

	if (a_size == size)
	{
		/* Copy string and add escape char */
		strncpy(command, a_command, size);
		command[size] = '\0';
		if (strcmp(command, prog_command) == 0)
			return 1;
	}
	else
	{
		return 0;
	}
	free(command);
}

/*
 * Once the command type is found, receive the arguments from the command
 * Return type to be decided
 * Arguments taken to be decided
 */
void match_argument(char a_command[])
{

}
