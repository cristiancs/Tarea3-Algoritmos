
TARGET = output
CC = g++
CFLAGS = -Wall

.PHONY: default all clean

default: 
	$(CC) libros.cpp -o p1.out $(CFLAGS)
	$(CC) sarcofago.cpp -o p2.out $(CFLAGS)

all: default

OBJECTS = libros.cpp sarcofago.cpp
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

libro:
	./p1.out < input.txt > output.txt
	
sarcofago:
	./p2.out < input.txt > output.txt

test:
	./$(TARGET) < input.txt
clean:
	-rm -f *.out
	-rm -f $(TARGET)