CC = gcc
CFLAGS = -Wall
OBJECTS = lex.yy.o y.tab.o pruebaSintactico.o
CLEAN = pruebaSintactico lex.yy.c y.tab.c y.output

all: $(OBJECTS)
	$(CC) $(CFLAGS) -o pruebaSintactico $(OBJECTS)

pruebaSintactico.o: pruebaSintactico.c y.tab.h
	$(CC) $(CFLAGS) -c pruebaSintactico.c

lex.yy.o: lex.yy.c y.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -c y.tab.c

lex.yy.c: alfa.l
	$ flex alfa.l

y.tab.h: alfa.y
	$ bison -d -y -v alfa.y

clean :
	rm -f *.o *.h core  $(CLEAN) mi*
