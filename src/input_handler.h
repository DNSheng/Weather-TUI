#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

/* Defined commands in the program for parsing purposes */

/* Commands with arguments */
const char SET_COMMAND[]	= "set";

/* Commands without arguments */
const char QUIT_COMMAND[]	= "quit";
const char QUIT_COMMAND_2[]	= "q";
const char HELP_COMMAND[]	= "help";

/* Main functions to handle input (receive/parse) */
void main_screen_input();
void get_command();
void parse_command(char a_command[]);
int match_command(char a_command[], const char* prog_command);
void match_argument(char a_command[]);	//Return type TBDecided

#endif
