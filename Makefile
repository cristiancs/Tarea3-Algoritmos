
TARGET = output
CC = g++
CFLAGS = -Wall

.PHONY: default all clean

default: 
	$(CC) ejercicio1.cpp -o ejercicio1 $(CFLAGS)
	$(CC) ejercicio2.cpp -o ejercicio2 $(CFLAGS)

all: default

OBJECTS = ejercicio1.cpp ejercicio2.cpp
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

p1:
	./ejercicio1 < input.txt > output.txt
	
p2:
	./ejercicio2 < input.txt > output.txt

test:
	./$(TARGET) < input.txt
clean:
	-rm -f *.out
	-rm -f $(TARGET)