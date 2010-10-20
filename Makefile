CFLAGS=-Wall -pedantic --std=c99 `pkg-config --cflags --libs sdl` -lSDL_image -lSDL_ttf -lSDL_mixer -ggdb

fashion: main.c
	$(CC) $(CFLAGS) -o $@ $^

