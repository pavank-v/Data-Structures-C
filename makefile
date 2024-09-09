CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/deque.o
	mkdir -p lib
	ar rcs $(LIB) src/deque.o

# Rule to compile the object file from deque.c
src/deque.o: src/deque.c include/deque.h
	$(CC) $(CFLAGS) -c src/deque.c -o src/deque.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_deque.c -Iinclude -Llib -lmylibrary -o test/test_deque

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_deque