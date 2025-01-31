CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

TESTS = $(wildcard $(TEST_DIR)/*.c)
TEST_BIN = $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%, $(TESTS))


tests: $(TEST_BIN)

$(BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

