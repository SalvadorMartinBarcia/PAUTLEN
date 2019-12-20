

/*El fichero alfa.l se modifica para que el analizador léxico actualice los atributos semánticos de los terminales.*/

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	int linea=1,columna=1;
	int flagError = 0;
%}
%option noyywrap

main	"main"
int	"int"
boolean	"boolean"
array	"array"
function	"function"
if	"if"
else	"else"
while	"while"
scanf	"scanf"
printf	"printf"
return	"return"
;	";"
,	","
(	"(" 
)	")"
[	"["
]	"]"
{	"{"
}	"}"
==	"=="
=	"="
+	"+"
-	"-"
*	"*"
/	"/"
&&	"&&"
||	"||"
!=	"!="
!	"!"
<=	"<="
>=	">="
>	">"
<	"<"
true	"true"
false	"false"

DIGITO[0-9]
LETRAS [a-zA-Z]
LETDIG [a-zA-Z0-9]
%%
"//".*	{columna+=yyleng;} /*no se que es*/
"main"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_MAIN;}

"int"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_INT;}
"boolean"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_BOOLEAN;}
"array"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_ARRAY;}
"function"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_FUNCTION;}
"if"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_IF;}
"else"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_ELSE;}
"while"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_WHILE;}
"scanf"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_SCANF;}
"printf"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_PRINTF;}
"return"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_RETURN;}
";"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_PUNTOYCOMA;}
","	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_COMA;}
"("	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_PARENTESISIZQUIERDO;}
")"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_PARENTESISDERECHO;}
"["	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_CORCHETEIZQUIERDO;}
"]"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_CORCHETEDERECHO;}
"{"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_LLAVEIZQUIERDA;}
"}"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_LLAVEDERECHA;}
"=="	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_IGUAL;}
"="	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_ASIGNACION;}
"+"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_MAS;}
"-"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_MENOS;}
"*"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_ASTERISCO;}
"/"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_DIVISION;}
"&&"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_AND;}
"||"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_OR;}
"!="	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_DISTINTO;}
"!"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_NOT;}
"<="	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_MENORIGUAL;}
">="	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_MAYORIGUAL;}
">"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_MAYOR;}
"<"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_MENOR;}
"true"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_TRUE;}
"false"	{columna+=yyleng;fprintf(yyout,";D:\t%s\n",yytext);return TOK_FALSE;}
"\t"	{columna+=yyleng;}
" "	{columna+=yyleng;}
"\n"	{linea++;columna=1;}
{LETRAS}({LETDIG})*	{columna+=yyleng;strcpy(yylval.str,yytext);
if(yyleng>100){fprintf(stdout,"****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",linea,columna-yyleng,yytext);flagError=1;return TOK_ERROR;}
else{fprintf(yyout,";D:\t%s\n",yytext);};
return TOK_IDENTIFICADOR;}
({DIGITO})+	{columna+=yyleng;yylval.ival=atoi(yytext);fprintf(yyout,";D:\t%s\n",yytext);return TOK_CONSTANTE_ENTERA;}
.	{flagError=1;columna+=yyleng;strcpy(yylval.str,yytext);fprintf(stdout,"****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",linea,columna-yyleng,yytext);return TOK_ERROR;}
%%