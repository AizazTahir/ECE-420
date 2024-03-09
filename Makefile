# Specify the compiler
CC=gcc-13

# Specify compiler flags
CFLAGS=-fopenmp

# Specify the target executable name
TARGET=intro

# Default target
all: $(TARGET)

# Rule for building the target executable
$(TARGET): intro.c
	$(CC) $(CFLAGS) intro.c -o $(TARGET)

# Clean target for removing compiled binary
clean:
	rm -f $(TARGET)
