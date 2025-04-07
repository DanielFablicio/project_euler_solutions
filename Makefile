CC := gcc
CSTD := -std=c99
CFLAGS := -Wall -Wextra -pedantic $(CSTD) -g

SRCS_DIR := problems
BASE_SRC_PREFIX := problem_

src := 1

CHOSEN_PROBLEM := $(SRCS_DIR)/$(BASE_SRC_PREFIX)$(src).c
OUTPUT := $(patsubst %.c,%,$(notdir $(CHOSEN_PROBLEM)))

all:
	$(CC) $(CFLAGS) $(CHOSEN_PROBLEM) -o $(OUTPUT)
	@./$(OUTPUT)
	@rm $(OUTPUT)

print:
	@echo $(CHOSEN_PROBLEM) $(OUTPUT)
