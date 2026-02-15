CC = gcc
CFLAGS = -Wall
LDFLAGS = -lglut -lGLU -lGL -lm

TARGET = 11-05.out

SRCS = 07-03-EmbededObjects.c \
       08-01-GLTools.c \
       09-02-Projection.c \
       09-03-Callback.c \
       11-02-ReadModel.c \
       11-04-FileObjects.c \
       11-04-MainFunction.c \
       11-05-Initialization.c \
       11-05-Rendering.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)
	rm -f $(OBJS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c ic2-CommonHeaders.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
