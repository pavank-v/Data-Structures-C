CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/binary_tree.o
	mkdir -p lib
	ar rcs $(LIB) src/binary_tree.o

# Rule to compile the object file from binary_tree.c
src/binary_tree.o: src/binary_tree.c include/binary_tree.h
	$(CC) $(CFLAGS) -c src/binary_tree.c -o src/binary_tree.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_binary_tree.c -Iinclude -Llib -lmylibrary -o test/test_binary_tree

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_binary_tree