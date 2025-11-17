CC = gcc
CFLAGS = -Wall -Iinclude
TARGET = test
C_FILES = src/main.c src/stack.c src/dynamic_arrays.c src/doubly_linked_list.c

all: $(TARGET)

$(TARGET): $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES) -o $(TARGET)

clean:
	rm -f $(TARGET)

