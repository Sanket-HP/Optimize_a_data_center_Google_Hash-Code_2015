
CC = gcc
CFLAGS = -I./include
OBJ = src/hashcode.o src/main.o

all: hashcode

hashcode: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f src/*.o hashcode
