CC = gcc
TARGET = mi_programa
C_FILES = main.c 
CFLAGS = -Wall


all: $(TARGET)

$(TARGET): $(C_FILES) 
	$(CC) $(CFLAGS) $(C_FILES) -o $(TARGET)

clean: 
	rm -f $(TARGET)

 
