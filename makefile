CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/max_heap.o
	mkdir -p lib
	ar rcs $(LIB) src/max_heap.o

# Rule to compile the object file from max_heap.c
src/max_heap.o: src/max_heap.c include/max_heap.h
	$(CC) $(CFLAGS) -c src/max_heap.c -o src/max_heap.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_max_heap.c -Iinclude -Llib -lmylibrary -o test/test_max_heap

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_max_heap