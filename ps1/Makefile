# premenne
CC=gcc
CFLAGS=-std=c11 -Wall -Werror 
LDLIBS=-lm
OUTPUT=ps1

# nase ciele
all: $(OUTPUT)

$(OUTPUT): playfair.o bmp.o main.o
	cppcheck --enable=performance *.c
	$(CC) $(CFLAGS) playfair.o bmp.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

playfair.o: playfair.c playfair.h
	$(CC) $(CFLAGS) -c playfair.c $(LDLIBS) -o playfair.o

bmp.o: bmp.c bmp.h
	$(CC) $(CFLAGS) -c bmp.c $(LDLIBS) -o bmp.o

# nakoniec zmazanie kompilovanych suborov
clean:
	rm -rf $(OUTPUT) *.o
	rm -rf $(OUTPUT) test

tests: tests_bmp.c bmp.c
	$(CC) $(CFLAGS)  tests_bmp.c bmp.c $(LDLIBS) -o test
	
