CC = gcc
CFLAGS = -Iinclude
LIB = lib/libmylibrary.a

all: $(LIB) test

# Rule to compile the library
$(LIB): src/list_graph.o
	mkdir -p lib
	ar rcs $(LIB) src/list_graph.o

# Rule to compile the object file from list_graph.c
src/list_graph.o: src/list_graph.c include/list_graph.h
	$(CC) $(CFLAGS) -c src/list_graph.c -o src/list_graph.o

# Rule to compile the test program
test: $(LIB)
	$(CC) test/test_list_graph.c -Iinclude -Llib -lmylibrary -o test/test_list_graph

# Clean rule to remove all generated files
clean:
	rm -f src/*.o lib/*.a test/test_list_graph