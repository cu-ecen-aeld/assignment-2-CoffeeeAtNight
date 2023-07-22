# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra

# Default target (build the "writer" application)
.PHONY: all
all: writer

# Cross-compiler settings
ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
CC := $(CROSS_COMPILE)$(CC)
endif

# Build the "writer" application
writer: writer.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile the source code to object file
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target (remove the "writer" application and all .o files)
.PHONY: clean
clean:
	rm -f writer *.o
