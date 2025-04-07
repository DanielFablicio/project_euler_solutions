CC := gcc
CSTD := -std=c99
CFLAGS := -Wall -Wextra -pedantic $(CSTD) -g

SRCS_DIR := problems
BASE_SRC_PREFIX := problem_

src := 1

CHOICED_PROBLEM := $(SRCS_DIR)/$(BASE_SRC_PREFIX)$(src).c
OUTPUT := $(patsubst %.c,%,$(notdir $(CHOICED_PROBLEM)))

all:
	$(CC) $(CFLAGS) $(CHOICED_PROBLEM) -o $(OUTPUT)
	@./$(OUTPUT)
	@rm $(OUTPUT)

print:
	@echo $(CHOICED_PROBLEM) $(OUTPUT)
