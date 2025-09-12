CC=gcc
CFLAGS=-g -Wall
SDL_LIBS=-I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2
all: main enclosed
main: main.c
	$(CC) $(CFLAGS) main.c -o main
enclosed: enclosed.c
	$(CC) $(CFLAGS) $(SDL_LIBS) enclosed.c -o enclosed
clean:
	rm -f main enclosed *.o
.PHONY: all clean
