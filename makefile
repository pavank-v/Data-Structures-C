CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/min_heap.o
	mkdir -p lib
	ar rcs $(LIB) src/min_heap.o

# Rule to compile the object file from min_heap.c
src/min_heap.o: src/min_heap.c include/min_heap.h
	$(CC) $(CFLAGS) -c src/min_heap.c -o src/min_heap.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_min_heap.c -Iinclude -Llib -lmylibrary -o test/test_min_heap

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_min_heap