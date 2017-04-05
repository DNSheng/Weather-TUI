#ifndef DRAW_MAIN_H
#define DRAW_MAIN_H

#define DEFAULT_BACKGROUND_COLOR -1
#define DEFAULT_FOREGROUND_COLOR -1

/* Init colors past the 16 default */
#define YELLOW		16
#define GREY		17
#define BLUE		18

/* Start init-ing color pairs */
#define SUNNY_YELLOW	1
#define RAINY_BLUE	2
#define CLOUDY_GREY	3


/*
 * Window functions
 */
void initialize_main();
void initialize_colors();
void initialize_colors_dark();
void refresh_main();
void error_message(char *message);
void quit();

/*=================================================================
 * DRAWING
 *=================================================================
 */

/*
 * Drawing window sections
 * TODO: Decide arguments for hour, hourly, day, and week
 */
void draw_main();
void draw_now();
void draw_hour();
void draw_hourly();
void draw_day();
void draw_week();

/*
 * Implicit drawing, draws with current cursor as top left corner
 */
void draw_sunny();
void draw_party_cloudy();
void draw_cloudy();
void draw_drizzle();
void draw_rain();
void draw_snow();
void draw_thunder();
void draw_fog();

/*
 * Drawing window details, coords represent top left corner
 */
void xydraw_sunny(int x, int y);
void xydraw_partly_cloudy(int x, int y);
void xydraw_cloudy(int x, int y);
void xydraw_drizzle(int x, int y);
void xydraw_rain(int x, int y);
void xydraw_snow(int x, int y);
void xydraw_thunder(int x, int y);
void xydraw_fog(int x, int y);

/*=================================================================
 * PRINTING
 *=================================================================
 */

/*
 * Printing value functions
 */
void print_temp(float temp);
void print_feel_temp(float temp);		// Feels like XX degrees
void print_wind(float speed, char direction); 	// Change direction to enum later
void print_humid(float humidity);
void print_rain_chance(float pop);
void print_rain_amount(float amount);

/*
 * Printing title and info
 */
void print_title();
void print_location(char *city, char *country);
void print_time(char *time_string);

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
