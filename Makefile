build:
	gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm `sdl2-config --cflags` `sdl2-config --libs` -o maze;

run:
	./maze;

clean:
	rm maze;
