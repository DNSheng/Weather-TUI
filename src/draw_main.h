#ifndef DRAW_MAIN_H
#define DRAW_MAIN_H

/*
 * Window functions
 */
void initialize_main();
void draw_main_window();
void error_message(char *message);

/*
 * Printing title and info
 */
void print_title();
void print_location(char *city, char *country);
void print_time(char *time_string);

/*
 * Drawing window sections
 * TODO: Decide arguments for hour, hourly, day, and week
 */
void draw_now();
void draw_hour();
void draw_hourly();
void draw_day();
void draw_week();

/*
 * Drawing window details, coords represent top left corner
 */
void draw_sunny(int x, int y);
void draw_partly_cloudy(int x, int y);
void draw_cloudy(int x, int y);
void draw_drizzle(int x, int y);
void draw_rain(int x, int y);
void draw_snow(int x, int y);
void draw_thunder(int x, int y);
void draw_fog(int x, int y);

/*
 * Printing value functions
 */
void print_temp(float temp);
void print_wind(float speed, char direction); // Change direction to enum later
void print_humid(float humidity);
void print_rain_chance(float pop);
void print_rain_amount(float amount);

/*
 * Formatting the print value functions above
 * TODO: Decide argument type
 */
void print_red();
void print_orange();
void print_green();
void print_lime();
void print_yellow();
void print_light_blue();
void print_blue();

#endif
