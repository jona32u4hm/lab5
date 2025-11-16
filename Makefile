CC = gcc
CFLAGS = -Wall -Iinclude   # -Iinclude para que encuentre stack.h
TARGET = mi_programa
C_FILES = src/main.c src/stack.c


all: $(TARGET)

$(TARGET): $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES) -o $(TARGET)

clean:
	rm -f $(TARGET)

