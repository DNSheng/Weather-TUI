#ifndef WEATHER_MODEL_H
#define WEATHER_MODEL_H

/* Define type error, holds all errors program throws */
typedef enum { COLOR_NOT_SUPPORTED,
	       BIG_BAD_ERROR,
	       SOME_OTHER_ERROR } error;

void throw_error(error a_error);
#endif
