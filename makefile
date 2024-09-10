CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/dll.o
	mkdir -p lib
	ar rcs $(LIB) src/dll.o

# Rule to compile the object file from dll.c
src/dll.o: src/dll.c include/dll.h
	$(CC) $(CFLAGS) -c src/dll.c -o src/dll.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_dll.c -Iinclude -Llib -lmylibrary -o test/test_dll

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_dll