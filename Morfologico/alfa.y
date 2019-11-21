%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tokens.h"
  void yyerror(char *cad);
  extern FILE *yyin;
  extern FILE *yyout;
	int linea=1,columna=1;
%}
%union
{
 char* cadena;
 int numero;
}
%token SI
%token ENTONCES
%token SINO
%token <cadena> ID
%token <numero> NUM


%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR
%token TOK_IDENTIFICADOR
%token TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE
%token TOK_ERROR

%%
programa: TOK_MAIN TOK_LLAVEIZQUIERDA TOK_INT TOK_PUNTOYCOMA TOK_LLAVEDERECHA {fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}

declaraciones: declaracion {fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");}



























%%
void yyerror (char *cad){
		fprintf(stdout,"ERROR: "%s", cad);
}
