CC = gcc
BISON = bison
FLEX = flex
ASM=nasm
ALFA=./alfa

BIN = alfa
CFLAGS = -Wall 
CYYFLAGS = 

FLEXFLAGS =

BISONFLAGS = -dyv

ASMFLAGS=-g -f elf32
NASM_LDFLAGS=-m32 -g

ZIPNAME = Fuentes_Perdices_5_compilador.zip
ZIPFILES = *.l *.y *.c *.h Makefile programas_correctos/* programas_error/* ficheros_correccion/* ficheros_correccion_errores/* pytest.py correccion alfalib.o

OBJ = tablaSimbolos.o tablaHash.o generacion.o

# Compilacion de los tests y programas de prueba


all: ${BIN}


alfa: y.tab.o lex.yy.o compilador.o $(OBJ)
	$(CC) -o $(ALFA) $^

lex.yy.o: lex.yy.c
	$(CC) ${CYYFLAGS} -c -o $@ $<

y.tab.o: y.tab.c
	$(CC) ${CYYFLAGS} -c -o $@ $<

%.o: %.c
	$(CC) ${CFLAGS} -c -o $@ $<

y.tab.c: alfa.y
	$(BISON) $(BISONFLAGS) alfa.y

y.tab.h: alfa.y
	$(BISON) $(BISONFLAGS) alfa.y

lex.yy.c: alfa.l y.tab.h
	$(FLEX) $(FLEXFLAGS) alfa.l

clean: 
	@rm -rvf $(ZIPNAME) $(BIN) $(OBJ) lex.yy.c lex.yy.o y.tab.h y.tab.c y.tab.o y.output alfa *.o *.asm

zip: clean
	zip $(ZIPNAME) $(ZIPFILES)
