#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

/* Main functions to handle input (receive/parse) */
void main_screen_input();
void get_command();
void parse_command(char a_command[]);
int match_command(char a_command[], const char* prog_command);
void match_argument(char a_command[]);	//Return type TBDecided

#endif
