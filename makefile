#!/usr/bin/env bash
#script to compile and run maze game

gcc -Wall -Werror -Wextra -pedantic /Maze_Project/src/*.c -lm `sdl2-config --cflags` `sdl2-config --libs` -g -o maze;

./maze;

rm maze;
