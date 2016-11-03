# Constant variables
CC=gcc
CFLAGS=-c -Wall -g -std=c11
LDFLAGS=
EXECUTABLE=dict-game
ROOT=..
SRCDIR=$(ROOT)/src
OBJDIR=./obj
INCLUDE=-I$(ROOT)/include

# Functions
IF_NOT_EXIST_MKDIR = $(if $(wildcard $1),,$(shell mkdir -p $1))

# All c sources
SOURCES  = main.c
SOURCES += gen/gen_main.c

# Auto objects
OBJECTS=$(SOURCES:.c=.o)

.PHONY: all
all: $(addprefix $(SRCDIR)/, $(SOURCES)) $(EXECUTABLE)
    
$(EXECUTABLE): $(addprefix $(OBJDIR)/, $(OBJECTS))
	$(CC) $(LDFLAGS) $^ -o $@


$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	$(call IF_NOT_EXIST_MKDIR, $(@D))
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

.PHONY: clean
clean:
	find . \( -name '*.o' \) -exec rm {} +
	rm -f $(EXECUTABLE)
