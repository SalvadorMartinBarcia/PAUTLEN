CC = gcc
CFLAGS = -Wall


all: lex.yy.c
	$(CC) $(CFLAGS) -o pruebaMorfo lex.yy.c
lex.yy.c: alfa.l
	$flex alfa.l
clean:
	rm pruebaMorfo lex.yy.c