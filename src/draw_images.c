#include <ncurses.h>

#include "draw_main.h"
#include "draw_images.h"
#include "weather_model.h"

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

/*
 * Draw ASCII heavy rain
 */
void xydraw_heavy_rain(int x, int y)
{
	/* Draw the cloud */
	attron(COLOR_PAIR(CLOUDY_GREY));
	mvprintw(y, x+4, ".--.");
	mvprintw(y+1, x+1, ".-(    ).");
	mvprintw(y+2, x, "(___.__)__)");
	attroff(COLOR_PAIR(CLOUDY_GREY));
	
	/* Draw the rain */
	attron(COLOR_PAIR(RAINY_BLUE));
	mvprintw(y+3, x, "```````````");
	mvprintw(y+4, x, "```````````");
	attroff(COLOR_PAIR(RAINY_BLUE));

}
