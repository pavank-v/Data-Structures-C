CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/matrix_graph.o
	mkdir -p lib
	ar rcs $(LIB) src/matrix_graph.o

# Rule to compile the object file from matrix_graph.c
src/matrix_graph.o: src/matrix_graph.c include/matrix_graph.h
	$(CC) $(CFLAGS) -c src/matrix_graph.c -o src/matrix_graph.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_matrix_graph.c -Iinclude -Llib -lmylibrary -o test/test_matrix_graph

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_matrix_graph