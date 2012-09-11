CC=clang++
CFLAGS=
LIBS=-lpng

OBJ=png.o pixel.o

.PHONY: all unit debug clean

all: CLFAGS += -O4
all: $(OBJ)

debug: CFLAGS += -DDEBUG -g
debug: $(OBJ)

unit: CFLAGS += -DDEBUG -g
unit: $(OBJ) unit_test.o
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

%.o: %.cc tinypng.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o unit
