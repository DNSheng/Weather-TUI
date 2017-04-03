#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "input_handler.h"
#include "draw_main.h"

/*
 * Get keypresses in main window where:
 * 	- ':'		Lets users enter commands
 * 	- 'q'		Gives users an exit prompt
 * 	- 'c'		Changes to celsius
 * 	- 'f'		Changes to farenheit
 * 	- other		Does nothing
 */
void main_screen_input()
{
	int inputChar = getch();
	switch (inputChar) {
		case 58:
			// ':' pressed
			get_command();
			break;
		case 113:
			// 'q' pressed
			endwin();
			exit(0);
			break;
		case 99:
			// 'c' pressed for celsius
			draw_main_window();
			break;
		case 102:
			// 'f' pressed for farenheit
			draw_main_window();
			break;
		default:	
			draw_main_window();
	}
	/* Once input received and model updated, go to main window and refresh */
	draw_main_window();
}

/*
 * Get a user command in the form of a string
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
	printw("%s", command_str);
}

/*
 * Compare a_command with all programmed commands from header file
 * Update model for each command
 * View updated in parent function get_
 */
void parse_command(char a_command[256])
{
	int i;
	if (match_command(a_command, SET_COMMAND)) {
		//Call the set command from the model
		match_argument(a_command);
	} else if (match_command(a_command, QUIT_COMMAND)) {
		//Call quit command from the model
		i++;
	} else if (match_command(a_command, HELP_COMMAND)) {
		//Call help command from the model
		i++;
	} else {
		//Command not found, print in red text and show for few secs, delete
		i++;
	}
}

/*
 * Return 1 if the user input called such a command
 * Return 0 otherwise
 */
int match_command(char a_command[], const char* prog_command)
{
	size_t size = strlen(prog_command);
	char *command = (char *) malloc(size);

	strncpy(command, a_command, size);

	if(strcmp(command, prog_command) == 0) return 1;
	
	return 0;
}

/*
 * Once the command type is found, receive the arguments from the command
 * Return type to be decided
 * Arguments taken to be decided
 */
void match_argument(char a_command[])
{

}
