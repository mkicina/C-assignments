# premenne
CC=gcc
CFLAGS=-std=c11 -Wall -Werror 
LDLIBS=-lm 
OUTPUT=ps3

# nase ciele
all: $(OUTPUT)

$(OUTPUT): hof.o k.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) hof.o k.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

hof.o: hof.c hof.h
	$(CC) $(CFLAGS) -c hof.c $(LDLIBS) -o hof.o

k.o: k.c k.h
	$(CC) $(CFLAGS) -c k.c $(LDLIBS) -o k.o


# nakoniec zmazanie kompilovanych suborov
clean:
	rm -rf $(OUTPUT) *.o

