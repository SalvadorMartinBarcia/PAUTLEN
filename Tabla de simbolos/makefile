CC = gcc
CFLAGS = -Wall
EXE = prueba_tabla
OBJECTS = prueba_tabla.o tablaSimbolos.o tablaHash.o

all: $(EXE)

$(EXE):%: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm $(EXE) $(OBJECTS) mi*

