#ifndef DRAW_IMAGES_H
#define DRAW_IMAGES_H

/* This is meant to draw images of clouds and such */

/* Draw at current cursor location */
void draw_sunny();
void draw_partly_cloudy();
void draw_cloudy();
void draw_drizzle();
void draw_rain();
void draw_showers();
void draw_snow();
void draw_thunder();
void draw_fog();

/* Draw at specific cursor location, given top left coords */
void xydraw_sunny(int x, int y);
void xydraw_partly_cloudy(int x, int y);
void xydraw_cloudy(int x, int y);
void xydraw_drizzle(int x, int y);
void xydraw_rain(int x, int y);
void xydraw_showers(int x, int y);
void xydraw_heavy_rain(int x, int y);
void xydraw_snow(int x, int y);
void xydraw_thunder(int x, int y);
void xydraw_fog(int x, int y);

#endif
