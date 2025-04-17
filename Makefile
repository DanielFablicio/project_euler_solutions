CC := gcc
CSTD := -std=c99
CFLAGS := -Wall -Wextra -pedantic $(CSTD) -g
#gf2 -> A GDB frontend for Linux.
DEBUGGER := gf2

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

all: compile
	@./$(OUTPUT)
	@rm $(OUTPUT)

compile:
	$(CC) $(CFLAGS) $(CHOSEN_PROBLEM) -o $(OUTPUT)

print:
	@echo $(CHOSEN_PROBLEM) $(OUTPUT)"\n"$(src)

#Needs the tool `hyperfine` (https://github.com/sharkdp/hyperfine).
#Scheduled to remove the dependency later with a simpler and equally
#accurate approach. [Waiting for laziness to pass].
benchmk: compile
	hyperfine './$(OUTPUT)'
	rm $(OUTPUT)

debug: compile
	$(DEBUGGER) $(OUTPUT)
	rm $(OUTPUT)
