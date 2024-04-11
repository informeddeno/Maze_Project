build:
	gcc -Wall -Werror -Wextra -pedantic /Maze_Project/src/*.c -lm `sdl2-config --cflags` `sdl2-config --libs` -g -o maze;

run:
	./maze;

clean:
	rm maze;
