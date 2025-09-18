CC=gcc
CFLAGS=-g -Wall
SDL_LIBS=-I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2

BIN_DIR=bin
TARGETS=$(BIN_DIR)/main $(BIN_DIR)/eis $(BIN_DIR)/eas

all: $(TARGETS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/main: main.c | $(BIN_DIR)
	$(CC) $(CFLAGS) main.c -o $@ $(SDL_LIBS)

$(BIN_DIR)/eis: enclosed_iterating_solver.c | $(BIN_DIR)
	$(CC) $(CFLAGS) enclosed_iterating_solver.c -o $@ $(SDL_LIBS)

$(BIN_DIR)/eas: enclosed_additive_solver.c | $(BIN_DIR)
	$(CC) $(CFLAGS) enclosed_additive_solver.c -o $@ $(SDL_LIBS)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean

