CC     = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -g -fsanitize=address,undefined -Iinclude
BIN    = bin

all: $(BIN)/demo $(BIN)/test_vec

$(BIN)/demo: examples/demo_vec.c src/vec.c include/vec.h | $(BIN)
	$(CC) $(CFLAGS) examples/demo_vec.c src/vec.c -o $@

$(BIN)/test_vec: tests/test_vec.c src/vec.c include/vec.h | $(BIN)
	$(CC) $(CFLAGS) tests/test_vec.c src/vec.c -o $@

$(BIN):
	mkdir -p $(BIN)

run: $(BIN)/demo
	./$(BIN)/demo

test: $(BIN)/test_vec
	./$(BIN)/test_vec

clean:
	rm -rf $(BIN)

.PHONY: all run test clean
