# Makefile for Program 09-03-ex1
# OpenGL/GLUT Rendering Example

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -O2

# Libraries
LIBS = -lglut -lGLU -lGL -lm

# Header files
HEADERS = ic2-CommonHeaders.h

# Source files
SRCS = 07-03-EmbededObjects.c \
       07-04-Initialization.c \
       07-05-MainFunction.c \
       08-01-GLTools.c \
       09-02-Projection.c \
       09-03-Callback.c \
       09-03-Rendering.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = 09-03.out

# Default target
all: $(TARGET)
	rm -f $(OBJS)

# Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Compile
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
