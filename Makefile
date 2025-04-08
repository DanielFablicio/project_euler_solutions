CC := gcc
CSTD := -std=c99
CFLAGS := -Wall -Wextra -pedantic $(CSTD) -g

SRCS_DIR := problems
BASE_SRC_PREFIX := problem_

# Get all the files in the `problems` directory and remove the
# 'problems/' path and the '.c' extension.
PROBLEMS = $(basename $(notdir $(wildcard $(SRCS_DIR)/*.c)))
# Removes the 'problem_' prefix from file names, leaving only the
# number.
PROBLEMS_ID = $(patsubst $(BASE_SRC_PREFIX)%,%,$(PROBLEMS))

# Gets the ID of the latest problem and selects it as the default to
# compile and run when using `make`, unless specified with
# `make src={ID}`.
src ?= $(lastword $(PROBLEMS_ID))

CHOSEN_PROBLEM := $(SRCS_DIR)/$(BASE_SRC_PREFIX)$(src).c
OUTPUT := $(patsubst %.c,%,$(notdir $(CHOSEN_PROBLEM)))

all:
	$(CC) $(CFLAGS) $(CHOSEN_PROBLEM) -o $(OUTPUT)
	@./$(OUTPUT)
	@rm $(OUTPUT)

print:
	@echo $(CHOSEN_PROBLEM) $(OUTPUT)"\n"$(src)
