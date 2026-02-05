# Makefile for Program 07-05-ex1
# OpenGL/GLUT Event Handling Example

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
       07-03-Projection.c \
       07-04-Initialization.c \
       07-05-Callback.c \
       07-05-MainFunction.c \
			 08-01-GLTools.c \
			 08-04-Rendering.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = prog08-04.o

# Default target
all: $(TARGET)

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
