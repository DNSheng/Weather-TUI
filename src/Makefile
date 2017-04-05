weather: main.o draw_main.o input_handler.o weather_model.o
	gcc main.o draw_main.o input_handler.o weather_model.o -o weather -lncursesw

draw_input.o: draw_main.c draw_main.h
	gcc -c draw_main.c -lncursesw

input_handler.o: input_handler.c input_handler.h
	gcc -c input_handler.c -lncursesw

weather_model.o: weather_model.c weather_model.h
	gcc -c weather_model.c -lncursesw

main.o: main.c
	gcc -c main.c -lncursesw

clean:
	rm -f *.o weather
