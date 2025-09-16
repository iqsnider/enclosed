CC=gcc
CFLAGS=-g -Wall
SDL_LIBS=-I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2
all: main enclosed enclosed_prototype
main: main.c
	$(CC) $(CFLAGS) main.c -o main
enclosed: enclosed.c
	$(CC) $(CFLAGS) $(SDL_LIBS) enclosed.c -o enclosed

enclosed_prototype: enclosed_prototype.c
	$(CC) $(CFLAGS) enclosed_prototype.c -o proto
clean:
	rm -f main enclosed proto *.o
.PHONY: all clean
