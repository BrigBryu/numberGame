# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -I$(SRC_DIR)

# Directories
SRC_DIR = src

# Source files
SRC = $(SRC_DIR)/Card.c \
      $(SRC_DIR)/Deck.c \
      $(SRC_DIR)/Game.c \
      $(SRC_DIR)/Hand.c \
      $(SRC_DIR)/Ui.c \
      $(SRC_DIR)/main.c

# Object files
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = game

# Build rule
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lncurses

# Compile source files into object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
