weather: main.o draw_main.o input_handler.o
	gcc main.o draw_main.o input_handler.o -o weather -lncursesw

draw_input.o: draw_main.c draw_main.h
	gcc -c draw_main.c -lncursesw

input_handler.o: input_handler.c input_handler.h
	gcc -c input_handler.c -lncursesw

main.o: main.c
	gcc -c main.c -lncursesw

clean:
	rm -f *.o weather
