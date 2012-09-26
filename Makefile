CC=clang++
CFLAGS=--stdlib=libc++
LIBS=-lpng

SRC=$(filter-out unit_test.cc, $(wildcard *.cc))
OBJ=$(SRC:.cc=.o)
HDR=$(wildcard *.h)

SYSTEM=$(shell uname -s)

ifeq ($(SYSTEM), Linux)
LIBS += -Wl,-lstdc++
endif

.PHONY: all debug unit clean

all: CLFAGS += -O3
all: $(OBJ)

debug: CFLAGS += -DDEBUG -g
debug: $(OBJ)

unit: CFLAGS += -DDEBUG -g
unit: $(OBJ) unit_test.o
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

%.o: %.cc $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o unit
