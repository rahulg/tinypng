CC=clang++
CFLAGS=
LIBS=-lpng

.PHONY: all unit debug clean

all: CLFAGS += -O4
all: tinypng.o

debug: CFLAGS += -DDEBUG -g
debug: tinypng.o

unit: CFLAGS += -DDEBUG -g
unit: tinypng.o tinypng_test.o
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o unit
