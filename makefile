CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/hashmap.o
	mkdir -p lib
	ar rcs $(LIB) src/hashmap.o

# Rule to compile the object file from hashmap.c
src/hashmap.o: src/hashmap.c include/hashmap.h
	$(CC) $(CFLAGS) -c src/hashmap.c -o src/hashmap.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_hashmap.c -Iinclude -Llib -lmylibrary -o test/test_hashmap

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_hashmap