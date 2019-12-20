%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "tablaHash.h"
	void yyerror(char const *cad);
	extern int linea, columna, flagError;
	extern FILE *yyin;
	extern FILE *yyout;
	extern int yylex();
	extern int yyleng;
	int tamVector;
	int MAXVector = 65; /*POR EJEMPLO*/	
	int numIf = 0;
	int retorno = -1;
	boolean escribiendoEnFuncion = false;
	TIPO tipo_actual;
	INFO_SIMBOLO simbolo;
%}

%union
{
	char str[1000];
	int ival;
}

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
%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_DIVISION TOK_ASTERISCO TOK_AND
%left TOK_NOT
%start programa
%%
/*El txt de while no lo he usado porque no veo donde ponerlo*/
programa:
	TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA{
		escribir_inicio_main(yyout);
	};

declaraciones:
	declaracion {
		fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");
	} | declaracion declaraciones{
		fprintf(yyout,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
	};

declaracion:
	clase identificadores TOK_PUNTOYCOMA{
		fprintf(yyout,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
	};

clase:
	clase_escalar {
		fprintf(yyout,";R5:\t<clase> ::= <clase_escalar>\n");
	} | clase_vector{
		fprintf(yyout,";R7:\t<clase> ::= <clase_vector>\n");
	};

clase_escalar:
	tipo {
		fprintf(yyout,";R9:\t<clase_escalar> ::= <tipo>\n");
	};

tipo:
	TOK_INT {
		tipo_actual = ENTERO;
		declarar_variable(yyout, $1.nombre, tipo_actual, $4.valor);
	} | TOK_BOOLEAN {
		tipo_actual = BOOLEANO;
		declarar_variable(yyout, $1.nombre, tipo_actual, $4.valor); /*Supongo que sacas el tamaño de ahi*/
	};

clase_vector:
	TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {
		//EN $4.valor TENEMOS EL TAMAÑO DEL VECTOR 
		tamVector = $4.valor;	/*DE DONDE SACAS QUE ES $4.VALOR*/
  		//COMPROBACIONES SEMANTICAS (TAMANO > 0 y TAMANO < MAX) Y PROPAGACION EN $$.valor
		if (tamVector < 0 || tamVector > MAXVector){
			fprintf(stdout, "Error en el tamaño del vector\n", yyin);
			return -1;
		}
		fprintf(yyout,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
	};

identificadores:
	identificador {
		fprintf(yyout,";R18:\t<identificadores> ::= <identificador>\n");
	} | identificador TOK_COMA identificadores {
		fprintf(yyout,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
	};

funciones:
	funcion funciones {
		fprintf(yyout,";R20:\t<funciones> ::= <funcion> <funciones>\n");
	} | {
		fprintf(yyout,";R21:\t<funciones> ::=\n");
	};

/*miraR ESTO BIEN DSFJKJGÑKLAGDFJGÑLÑOD*/

funcion: 
	fn_declaration sentencias TOK_LLAVEDERECHA {
	//COMPROBACIONES SEMANTICAS 

	//ERROR SI LA FUNCION NO TIENE SENTENCIA DE RETORNO
	if(retorno == -1){
		fprintf(stdout, "Error al crear la función %s, no hay return\n", yyin, $1.nombre);
		return -1;
	}
 	//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
	// Buscamos si ese simbolo existe en la tabla de simbolos local con categoria funcion
	if(UsoLocal($1.nombre) == NULL){
		fprintf(stdout, "Error en la función %d,función ya declarada d\n", yyin, $1.nombre));
		return -1;
	}

 	//CIERRE DE AMBITO, ETC
	CerrarFuncion();
  	simbolo->num_parametros = num_parametros;
	fprintf(yyout,";R22:\t<funcion> ::= function <tipo> <identificador> "(<parametros_funcion>) { <declaraciones_funcion> <sentencias> }\n");
	};


fn_declaration : fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
  	//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
	if(UsoLocal($1.nombre) == NULL){
		fprintf(stdout, "Error en la declaracion %d, ya declarada d\n", yyin, $1.nombre));
		return -1;
	}
 	simbolo->num_parametros = num_parametros;
 	strcpy($$.nombre, $1.nombre);
 	$$.tipo = $1.tipo;
 	//GENERACION DE CODIGO
 	declararFuncion(out, $1.nombre, num_variables_locales_actual);	
}

/*miraR ESTO BIEN DSFJKJGÑKLAGDFJGÑLÑOD*/

fn_name : TOK_FUNCTION tipo TOK_IDENTIFICADOR {
//COMPROBACIONES SEMANTICAS
retorno_funcion = 0;
escribiendoEnFuncion = TRUE;

//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.nombre
if(UsoLocal($1.nombre) == NULL){
	fprintf(stdout, "Error en la función %d,función ya declarada d\n", yyin, $1.nombre));
	return -1;
}

simbolo.identificador = $3.nombre;
simbolo.cat_simbolo = FUNCION;
simbolo.tipo = tipo_actual;
$$.tipo = tipo_actual;
strcpy($$.nombre, $3.nombre);

//ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.nombre
DeclararFuncion($3.nombre, &simbolo); /*POR QUE*/ 

//RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
//posicion_variable_local, num_variables_locales, posicion_parametro, num_parametros
posicion_variable_local = 0;
num_variables_locales = 0;
num_parametros = 0;
posicion_parametro = 0;
}

parametros_funcion:
	parametro_funcion resto_parametros_funcion {
		fprintf(yyout,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
	} | {
		fprintf(yyout,";R24:\t<parametros_funcion> :=\n");
};

resto_parametros_funcion:
	TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {
		fprintf(yyout,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
	} | {
		fprintf(yyout,";R26:\t<resto_parametros_funcion> ::=\n");
	};

parametro_funcion: tipo idpf {
	//INCREMENTAR CONTADORES, POR EJEMPLO
	num_parametros++;
	posicion_parametro++;
	fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
};

idpf : TOK_IDENTIFICADOR {
    //COMPROBACIONES SEMANTICAS PARA $1.nombre
    //EN ESTE CASO SE MUESTRA ERROR SI EL NOMBRE DEL PARAMETRO YA SE HA UTILIZADO
	if(UsoLocal($1.nombre) == NULL){
		fprintf(stdout, "Error, parametro ya utilizado en la linea %d\n", yyin));
		return -1;
	}
    simbolo.identificador = $1.nombre;
    simbolo.cat_simbolo = PARAMETRO;
    simbolo.tipo = tipo_actual;
    simbolo.categoria = ESCALAR;
    simbolo.posicion = posicion_parametro;

    //DECLARAR SIMBOLO EN LA TABLA
	Declarar($1.nombre, &simbolo);
}

declaraciones_funcion:
	declaraciones {
		fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
	} | {
		fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");
	};

sentencias:
	sentencia {fprintf(yyout,";R30:\t<sentencias> ::= <sentencia>\n");
	} | sentencia sentencias {
		fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
};

sentencia:
	sentencia_simple TOK_PUNTOYCOMA {
		fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
	} | bloque {
		fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");
	};

sentencia_simple:
	asignacion {
		fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
	} | lectura {
		fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
	} | escritura {
		fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
	} | retorno_funcion {
		fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
	};

bloque:
	condicional {
		fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");}
	| bucle {
		fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");
	};

asignacion:
	identificador TOK_ASIGNACION exp {
		fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
	} | elemento_vector TOK_ASIGNACION exp {
		if ($1.tipo != $3.tipo){
			fprintf(stdout, "Error semántico, tipos no compatibles\n", yyin);
			return -1;
		}
		escribir_operando(out, $1.valor, 0);
  		escribir_elemento_vector(out, $1.nombre, simbolo->longitud, $3.es_variable);
 		asignarDestinoEnPila(out, $3.es_variable);
		fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
	};

"/*tgesaLAFKGSLFDGLKFDGLJK*/
elemento_vector:
	identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
		//COMPROBACIONES SEMANTICAS PARA EL SIMBOLO CON IDENTIFICADOR $1.nombre
 		//NECESITAMOS EN $$: tipo, es_variable = 1, valor de $3 (ES EL INDICE DEL VECTOR)
  		escribir_elemento_vector(out, $1.nombre, simbolo->longitud, $3.es_variable);
		fprintf(yyout,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
	};

condicional:
	if_exp_sentencias TOK_LLAVEDERECHA {
		ifthenelse_fin(out, $1.etiqueta);
		fprintf(yyout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
	} | if_exp_sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA	{
		ifthenelse_fin(out, $1.etiqueta);
		fprintf(yyout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
};

if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
 	 //COMPROBACIONES SEMANTICAS
	if($3.tipo != BOOL){
		fprintf(stdout, "Error semántico, tipos no compatibles\n", yyin);
		return -1;
	}
 	//GESTION ETIQUETA
	$$.etiqueta =  numIf++;
 	ifthen_inicio(out, $3.es_variable, $$.etiqueta);
};

if_exp_sentencias: if_exp sentencias {
  $$.etiqueta = $1.etiqueta;
  ifthenelse_fin_then(out, $$.etiqueta);
}

bucle:
	TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
		while_fin(out, $1.etiqueta);
		fprintf(yyout,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
	};

lectura:
	TOK_SCANF identificador {
		fprintf(yyout,";R54:\t<lectura> ::= scanf <identificador>\n");
	};

escritura:
	TOK_PRINTF exp {
		fprintf(yyout,";R56:\t<escritura> ::= printf <exp>\n");
	};

retorno_funcion:
	TOK_RETURN exp {
		if(escribiendoEnFuncion == FALSE){
			fprintf(stdout, "Error en la linea, escribiendo retorno fuera de una función d\n", yyin));
			return -1;
		}
		retorno_funcion = 1;
		retornarFuncion(out, )/*NO SE QUE PONER EN LA SEGUNDA, COMO SE SI ES VAR O NO*/
		fprintf(yyout,";R61:\t<retorno_funcion> ::= return <exp>\n");
	};

exp:
	exp TOK_MAS exp {
		fprintf(yyout,";R72:\t<exp> ::= <exp> + <exp>\n");
	} | exp TOK_MENOS exp {
		fprintf(yyout,";R73:\t<exp> ::= <exp> - <exp>\n");
	} | exp TOK_DIVISION exp {
		fprintf(yyout,";R74:\t<exp> ::= <exp> / <exp>\n");
	} | exp TOK_ASTERISCO exp {
			fprintf(yyout,";R75:\t<exp> ::= <exp> * <exp>\n");
	} | TOK_MENOS exp {
		fprintf(yyout,";R76:\t<exp> ::= - <exp>\n");
	} | exp TOK_AND exp {
		fprintf(yyout,";R77:\t<exp> ::= <exp> && <exp>\n");
	} | exp TOK_OR exp {
		fprintf(yyout,";R78:\t<exp> ::= <exp> || <exp>\n");
	} | TOK_NOT exp {
		fprintf(yyout,";R79:\t<exp> ::= ! <exp>\n");
	} | identificador {
		fprintf(yyout,";R80:\t<exp> ::= <identificador>\n");
	} | constante {
		fprintf(yyout,";R81:\t<exp> ::= <constante>\n");
	} | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
		fprintf(yyout,";R82:\t<exp> ::= ( <exp> )\n");
	} | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
		fprintf(yyout,";R83:\t<exp> ::= ( <comparacion> )\n");
	} | elemento_vector {
		fprintf(yyout,";R85:\t<exp> ::= <elemento_vector>\n");
	} | identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {
		fprintf(yyout,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
	};

lista_expresiones:
	exp resto_lista_expresiones {
		fprintf(yyout,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
	} | {
		fprintf(yyout,";R90:\t<lista_expresiones> ::=\n");
	};

resto_lista_expresiones:
	TOK_COMA exp resto_lista_expresiones {
		fprintf(yyout,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
	} | {
		fprintf(yyout,";R92:\t<resto_lista_expresiones> ::=\n");
	};

comparacion:
	exp TOK_IGUAL exp {
		fprintf(yyout,";R93:\t<comparacion> ::= <exp> == <exp>\n");
	} | exp TOK_DISTINTO exp {
		fprintf(yyout,";R94:\t<comparacion> ::= <exp> != <exp>\n");
	} | exp TOK_MENORIGUAL exp {
		fprintf(yyout,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
	} | exp TOK_MAYORIGUAL exp {
		fprintf(yyout,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
	} | exp TOK_MENOR exp {
		fprintf(yyout,";R97:\t<comparacion> ::= <exp> < <exp>\n");
	} | exp TOK_MAYOR exp {
		fprintf(yyout,";R98:\t<comparacion> ::= <exp> > <exp>\n");
	};

constante:
	constante_logica {
		fprintf(yyout,";R99:\t<constante> ::= <constante_logica>\n");
	} | constante_entera {
		fprintf(yyout,";R100:\t<constante> ::= <constante_entera>\n");
	};

constante_logica:
	TOK_TRUE {
		fprintf(yyout,";R102:\t<constante_logica> ::= true\n");
	} | TOK_FALSE {
		fprintf(yyout,";R103:\t<constante_logica> ::= false\n");
};

constante_entera:
	TOK_CONSTANTE_ENTERA {
		fprintf(yyout,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
	};

identificador:
	TOK_IDENTIFICADOR {
		fprintf(yyout,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
	};

%%
void yyerror (char const *cad)
{
	if(flagError == 0)
		fprintf(stdout,"**** Error sintáctico en [lin %d, col %d]\n",linea,columna-yyleng);
	flagError = 0;
}
