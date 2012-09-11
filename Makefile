CC=clang++
CFLAGS=--stdlib=libc++
LIBS=-lpng

OBJ=png.o pixel.o
HDR=png.h pixel.h

SYSTEM=$(shell uname -s)

ifeq ($(SYSTEM), Linux)
LIBS += -Wl,-lstdc++
endif

.PHONY: all debug unit clean

all: CLFAGS += -O4
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
