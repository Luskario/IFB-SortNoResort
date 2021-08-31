TARGET = SortNoResort
CFLAGS = -Wall
CC = gcc
LDFLAGS = `pkg-config --cflags --libs gtk+-3.0`

SRC = $(wildcard ./src/*.c)
OBJ = $(SRC:.c =.o)

main: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<


.PHONY: clean

clean:
	rm main $(OBJ)