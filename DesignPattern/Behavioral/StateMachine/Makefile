# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRCS = main.c \
       MusicPlayer.c \
       StoppedState.c \
       PlayingState.c \
       PausedState.c

# Output executable
TARGET = music_player

# Default rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
