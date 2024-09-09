CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/sll.o
	mkdir -p lib
	ar rcs $(LIB) src/sll.o

# Rule to compile the object file from sll.c
src/sll.o: src/sll.c include/sll.h
	$(CC) $(CFLAGS) -c src/sll.c -o src/sll.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_sll.c -Iinclude -Llib -lmylibrary -o test/test_sll

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_sll