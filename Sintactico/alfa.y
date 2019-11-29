%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
void yyerror(char *cad);
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern FILE* out;
int linea=1,columna=1;
%}
%union
{
 int ival;
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

programa:
	TOK_MAIN | TOK_LLAVEIZQUIERDA | TOK_INT | TOK_PUNTOYCOMA | TOK_LLAVEDERECHA | TOK_PRINTF | {fprintf(out,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}


expression:
	TOK_INT	{ fprintf(out, ;R10: <tipo> ::= int \n"); }
	| expression TOK_BOOLEAN expression	{ fprintf(out, "R: expression TOK_BOOLEAN expression\n"); $$ = $1 + $3; }
	| expression T_MINUS expression	{ fprintf(out, "R: expression T_MINUS expression\n"); $$ = $1 - $3; }
	| expression T_MULTIPLY expression	{ fprintf(out, "R: expression T_MULTIPLY expression\n"); $$ = $1 * $3; }
	| T_LEFT expression T_RIGHT		{ fprintf(out, "R: T_LEFT expression T_RIGHT\n"); $$ = $2; }
;

declaracion:























%%
void yyerror (char *cad){
		fprintf(stderr,"ERROR: "%s", cad);
		exit(1);
}
