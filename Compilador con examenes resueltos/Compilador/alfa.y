%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "alfa.h"
	#include "tablaHash.h"

	void yyerror(char const *cad);
	extern int linea, columna, flagError;
	extern FILE *yyin;
	extern FILE *out;
	extern int yylex();
	
	TIPO tipo_actual;
	CLASE clase_actual;
	int tamVector;


	INFO_SIMBOLO simbolo;
	INFO_SIMBOLO *buscar;

	int num_no = 0;
	int num_comparaciones = 0;
	int num_If = 0;
	int num_bucles = 0;
	int pos_variable_local_actual = 0;
	int num_variables_locales_actual = 0;
	int num_parametros_actual = 0;
	int pos_parametro_actual = 0;

	int es_funcion = 0;
	int es_llamada = 0;
	int params = 0;
	int hay_return = 0;
%}

%union
{
	tipo_atributos atributos;
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
%token TOK_MODULO
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

%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE
%token TOK_ERROR

%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> constante
%type <atributos> exp
%type <atributos> id

%type <atributos> if_exp
%type <atributos> if_exp_sentencias

%type <atributos> while
%type <atributos> while_exp

%type <atributos> elemento_vector

%type <atributos> fn_name
%type <atributos> fn_declaration

%type <atributos> call_func

%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_DIVISION TOK_ASTERISCO TOK_AND
%left TOK_NOT
%start programa
%%
/*El txt de while no lo he usado porque no veo donde ponerlo*/
programa:
	TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones tabla funciones main sentencias TOK_LLAVEDERECHA{
		fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
	};

declaraciones:
	declaracion {
		fprintf(out,";R2:\t<declaraciones> ::= <declaracion>\n");
	} | declaracion declaraciones{
		fprintf(out,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
	};

declaracion:
	clase identificadores TOK_PUNTOYCOMA{
		fprintf(out,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
	};

clase:
	clase_escalar {
		fprintf(out,";R5:\t<clase> ::= <clase_escalar>\n");
		clase_actual = ESCALAR;
	} | clase_vector{
		fprintf(out,";R7:\t<clase> ::= <clase_vector>\n");
		clase_actual = VECTOR;
	};

clase_escalar:
	tipo {
		fprintf(out,";R9:\t<clase_escalar> ::= <tipo>\n");
	};

tipo:
	TOK_INT {
		tipo_actual = ENTERO;
		fprintf(out, ";R10:\t<tipo> ::= int\n");
	} | TOK_BOOLEAN {
		tipo_actual = BOOLEANO;
		fprintf(out, ";R11:\t<tipo> ::= boolean\n");
	};

clase_vector:
	TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO {
		//EN $4.valor TENEMOS EL TAMAÑO DEL VECTOR 
		tamVector = $4.valor_numerico;	/*DE DONDE SACAS QUE ES $4.VALOR*/
  		//COMPROBACIONES SEMANTICAS (TAMANO > 0 y TAMANO < MAX) Y PROPAGACION EN $$.valor
		if (tamVector <= 0 || tamVector > MAX_TAMANIO_VECTOR){
			fprintf(stdout, "Error en el tamaño del vector\n");
			return -1;
		}
		fprintf(out,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
	};

identificadores:
	identificador {
		fprintf(out,";R18:\t<identificadores> ::= <identificador>\n");
	} | identificador TOK_COMA identificadores {
		fprintf(out,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
	};

funciones:
	funcion funciones {
		fprintf(out,";R20:\t<funciones> ::= <funcion> <funciones>\n");
	} | {
		fprintf(out,";R21:\t<funciones> ::=\n");
	};


funcion: 
	fn_declaration sentencias TOK_LLAVEDERECHA {
		/*ERROR SI LA FUNCION NO TIENE SENTENCIA DE RETORNO*/
		if(!hay_return) {
			fprintf(stdout, "***Error semantico en lin %d: Funcion %s sin sentencia de retorno.\n", linea, $1.nombre);
			return -1;
		}
		CerrarFuncion();
  		retornarFuncion(out, $1.es_direccion);
		buscar = UsoLocal($1.nombre);
	
		//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
		// Buscamos si ese simbolo existe en la tabla de simbolos local con categoria funcion
		if(buscar == NULL){
			fprintf(stdout, "Error en la función %s,función ya declarada.\n", $1.nombre);
			return -1;
		}

		//CIERRE DE AMBITO, ETC
		buscar->adicional1 = num_parametros_actual;
  		es_funcion = 0;
		fprintf(out,";R22 :\t<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) { <declaraciones_funcion> <sentencias> }\n");
	};


fn_declaration: fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
  	//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
	buscar = UsoLocal($1.nombre);
	if(buscar == NULL){
		fprintf(stdout, "Error en la declaracion %s, ya declarada d\n", $1.nombre);
		return -1;
	}
 	buscar->adicional1 = num_parametros_actual;
 	strcpy($$.nombre, $1.nombre);
 	$$.tipo = $1.tipo;
 	//GENERACION DE CODIGO
 	declararFuncion(out, $1.nombre, num_variables_locales_actual);	
};

fn_name: 
	TOK_FUNCTION tipo TOK_IDENTIFICADOR {
		//COMPROBACIONES SEMANTICAS
		hay_return = 0;
		es_funcion = 1;
		buscar = UsoLocal($3.nombre);
		if(buscar != NULL) {
			fprintf(stdout, "****Error semantico en lin %d : Declaracion duplicada.\n", linea);
			return -1;
		}

		simbolo.lexema = $3.nombre;
		simbolo.categoria = FUNCION;
		simbolo.clase = ESCALAR;
		simbolo.tipo = tipo_actual;
		$$.tipo = tipo_actual;
		strcpy($$.nombre, $3.nombre);

		//ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.nombre
		DeclararFuncion($3.nombre, &simbolo); /*POR QUE*/ 

		//RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
		//posicion_variable_local, num_variables_locales, posicion_parametro, num_parametros
		pos_variable_local_actual = 0;
		num_variables_locales_actual=0;
		num_parametros_actual = 0;
		pos_parametro_actual = 0;
	};

parametros_funcion:
	parametro_funcion resto_parametros_funcion {
		fprintf(out,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
	} | {
		fprintf(out,";R24:\t<parametros_funcion> :=\n");
};

resto_parametros_funcion:
	TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {
		fprintf(out,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
	} | {
		fprintf(out,";R26:\t<resto_parametros_funcion> ::=\n");
	};

parametro_funcion: tipo idpf {
	//INCREMENTAR CONTADORES, POR EJEMPLO
	num_parametros_actual++;
	pos_parametro_actual++;
	fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
};

idpf: TOK_IDENTIFICADOR {
    //COMPROBACIONES SEMANTICAS PARA $1.nombre
    //EN ESTE CASO SE MUESTRA ERROR SI EL NOMBRE DEL PARAMETRO YA SE HA UTILIZADO
	buscar = UsoLocal($1.nombre);
	if(buscar != NULL){
		fprintf(stdout, "Error, parametro ya utilizado en la linea %d\n", linea);
		return -1;
	}
    simbolo.lexema = $1.nombre;
    simbolo.categoria = PARAMETRO;
    simbolo.tipo = tipo_actual;
    simbolo.clase = ESCALAR;
    simbolo.adicional1 = num_parametros_actual;

    //DECLARAR SIMBOLO EN LA TABLA
	Declarar($1.nombre, &simbolo);
}

declaraciones_funcion:
	declaraciones {
		fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
	} | {
		fprintf(out, ";R29:\t<declaraciones_funcion> ::=\n");
	};

sentencias:
	sentencia {fprintf(out,";R30:\t<sentencias> ::= <sentencia>\n");
	} | sentencia sentencias {
		fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
};

sentencia:
	sentencia_simple TOK_PUNTOYCOMA {
		fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
	} | bloque {
		fprintf(out, ";R33:\t<sentencia> ::= <bloque>\n");
	};

sentencia_simple:
	asignacion {
		fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
	} | modulo {
		fprintf(out, ";R36:\t<sentencia_simple> ::= <modulo>\n");
	} | lectura {
		fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");
	} | escritura {
		fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");
	} | retorno_funcion {
		fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
	};

bloque:
	condicional {
		fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
	| bucle {
		fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");
	};

modulo:
	id TOK_MODULO exp { 
		buscar = UsoLocal($1.nombre);
		if(buscar==NULL) {
			fprintf(stdout, "***Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.nombre);
			return -1;
		}
		if(buscar->categoria == FUNCION) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
	
		if(buscar->tipo != $3.tipo) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		
		if (UsoGlobal($1.nombre) == NULL) {
		/* Estamos en una funcion y la variable es local */
			if(buscar->categoria == PARAMETRO) {
				modulo(out, $1.es_direccion, $3.es_direccion);		
				escribirParametro(out, buscar->adicional1, num_parametros_actual + 2, 0);
			} else {
				modulo(out, $1.es_direccion, $3.es_direccion); //CUIDADO, ESTO ES CON 0 PORQUE NO SE BUSCARÁ UNA DIRECCION !!!!!
				escribirParametro(out, buscar->adicional1, 0, 0);
			}
		}
		else{
			modulo(out, $1.es_direccion, $3.es_direccion);
			asignar(out, $1.nombre, 0);
			fprintf(out, ";R43:\t<modulo> ::= <identificador> = <exp>\n");
		}

	} | elemento_vector TOK_MODULO exp {
		if ($1.tipo != $3.tipo){
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		modulo(out, $1.es_direccion, $3.es_direccion);
 		asignarDestinoEnPila(out, $3.es_direccion);
		fprintf(out, ";R44 :\t<Modulo> ::= <elemento_vector> = <exp>\n");
	};

id:
	TOK_IDENTIFICADOR{
		strcpy($$.nombre, $1.nombre);
    	buscar = UsoLocal($1.nombre);
		if(buscar == NULL) {
			fprintf(stdout, "***Error semantico en lin %d : Acceso a variable no declarada (%s).\n", linea, $1.nombre);
			return -1;
		}
		if (UsoGlobal($1.nombre) == NULL) {
		/* Estamos en una funcion y la variable es local */
			if(buscar->categoria == PARAMETRO) {
				escribirVariableLocal(out, (num_parametros_actual-buscar->adicional1)+1);
			} else {
				escribirVariableLocal(out, -(buscar->adicional1+1));
			}

		} else {
			if(buscar->categoria==FUNCION) {
				/* NUNCA SUCEDE */
				fprintf(stdout,"Identificador no valido\n");
				return -1;
			}
			escribir_operando(out, $1.nombre, 1);

		}
		$$.es_direccion = 1;
		$$.tipo = buscar->tipo;
	}

asignacion:
	TOK_IDENTIFICADOR TOK_ASIGNACION exp {
		buscar = UsoLocal($1.nombre);
		if(buscar==NULL) {
			fprintf(stdout, "***Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.nombre);
			return -1;
		}
		if(buscar->categoria == FUNCION) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		if(buscar->clase == VECTOR) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		if(buscar->tipo != $3.tipo) {
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
		if (UsoGlobal($1.nombre) == NULL) {
		/* Estamos en una funcion y la variable es local */
			if(buscar->categoria == PARAMETRO) {
				escribirParametro(out, buscar->adicional1, num_parametros_actual+2, $3.es_direccion);
			} else {
				escribirParametro(out, buscar->adicional1, 0, $3.es_direccion);
			}
		}
		else{
			asignar(out, $1.nombre, $3.es_direccion);
			fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
		}
	} | elemento_vector TOK_ASIGNACION exp {
		if ($1.tipo != $3.tipo){
			fprintf(stdout, "***Error semantico en lin %d: Asignacion incompatible.\n", linea);
			return -1;
		}
 		asignarDestinoEnPila(out, $3.es_direccion);
		fprintf(out, ";R44 :\t<asignacion> ::= <elemento_vector> = <exp>\n");
	};

elemento_vector:
	TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
		//COMPROBACIONES SEMANTICAS PARA EL SIMBOLO CON IDENTIFICADOR $1.nombre
 		//NECESITAMOS EN $$: tipo, es_variable = 1, valor de $3 (ES EL INDICE DEL VECTOR)
  		buscar = UsoLocal($1.nombre);
		if(buscar == NULL) {
			fprintf(stdout, "***Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.nombre);
			return -1;
		}  
		if(buscar->categoria == FUNCION) { /***REVISAR*/
			fprintf(stdout,"***Error semantico en lin %d: Identificador no valido\n", linea);
			return -1;  
		}  
		if(buscar->clase == ESCALAR) {
			fprintf(stdout, "***Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", linea);
			return -1;
		}
		$$.tipo = buscar->tipo;  
		$$.es_direccion = 1;
		if($3.tipo != ENTERO) {
			fprintf(stdout, "***Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", linea);
			return -1;
		}
		escribir_elemento_vector(out, $1.nombre, buscar->adicional1, $3.es_direccion);

		fprintf(out, ";R48 :\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
	};

condicional:
	if_exp_sentencias TOK_LLAVEDERECHA {
		ifthenelse_fin(out, $1.etiqueta);
		fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
	} | if_exp_sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA	{
		ifthenelse_fin(out, $1.etiqueta);
		fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
};

if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
 	 //COMPROBACIONES SEMANTICAS
	if($3.tipo != BOOLEANO){
		fprintf(stdout, "****Error semantico en lin %d: Condicional con condicion de tipo int.\n", linea);
		return -1;
	}
 	//GESTION ETIQUETA
	$$.etiqueta =  num_If++;
 	ifthenelse_inicio(out, $3.es_direccion, $$.etiqueta);
};

if_exp_sentencias: if_exp sentencias {
  $$.etiqueta = $1.etiqueta;
  ifthenelse_fin_then(out, $$.etiqueta);
}

bucle:
	while_exp sentencias TOK_LLAVEDERECHA {
		while_fin(out, $1.etiqueta);
		fprintf(out,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
	};

while:
	TOK_WHILE TOK_PARENTESISIZQUIERDO {
		$$.etiqueta = num_bucles++;
		while_inicio(out, $$.etiqueta);
	}

while_exp: 
	while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
		if($2.tipo != BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d: Bucle con condicion de tipo int.\n", linea);
			return -1;
  	}

  $$.etiqueta = $1.etiqueta;
  while_exp_pila(out, $2.es_direccion, $$.etiqueta);
};

lectura:
	TOK_SCANF TOK_IDENTIFICADOR {
		buscar = UsoLocal($2.nombre);
		if(buscar == NULL) {
			fprintf(stdout, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $2.nombre);
			return -1;
		}
		leer(out, $2.nombre, buscar->tipo); 
		fprintf(out, ";R54:\t<lectura> ::= scanf <identificador>\n");
	};

escritura:
	TOK_PRINTF exp {
		escribir(out, ($2.es_direccion), ($2.tipo));
		fprintf(out,";R56:\t<escritura> ::= printf <exp>\n");
	};

retorno_funcion:
	TOK_RETURN exp {
		if(!es_funcion){
			fprintf(stdout, "Error en la linea, escribiendo retorno fuera de una función d\n");
			return -1;
		}
		hay_return = 1;
		retornarFuncion(out, $2.es_direccion);/*NO SE QUE PONER EN LA SEGUNDA, COMO SE SI ES VAR O NO*/
		fprintf(out,";R61:\t<retorno_funcion> ::= return <exp>\n");
	};

exp:
	exp TOK_MAS exp {
		if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		sumar(out, $1.es_direccion, $3.es_direccion);
		$$.es_direccion = 0;
		$$.tipo = ENTERO;
		fprintf(out,";R72:\t<exp> ::= <exp> + <exp>\n");
	} | exp TOK_MENOS exp {
		if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		$$.tipo = ENTERO;
		restar(out, $1.es_direccion, $3.es_direccion);
		$$.es_direccion = 0;
		fprintf(out,";R73:\t<exp> ::= <exp> - <exp>\n");
	} | exp TOK_DIVISION exp {
		if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		$$.tipo = ENTERO;
		dividir(out, $1.es_direccion, $3.es_direccion);
		$$.es_direccion = 0;
		fprintf(out,";R74:\t<exp> ::= <exp> / <exp>\n");
	} | exp TOK_ASTERISCO exp {
		if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1;
		}
		$$.tipo = ENTERO;
		multiplicar(out, $1.es_direccion, $3.es_direccion);
		$$.es_direccion = 0;
		fprintf(out,";R75:\t<exp> ::= <exp> * <exp>\n");
	} | TOK_MENOS exp {
		if($2.tipo!=ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion aritmetica con operandos boolean.\n", linea);
			return -1; 
		}
		$$.tipo = ENTERO;
		cambiar_signo(out, $2.es_direccion);
		$$.es_direccion = 0;
		fprintf(out,";R76:\t<exp> ::= - <exp>\n");
	} | exp TOK_AND exp {
		if($1.tipo!=BOOLEANO || $3.tipo != BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion logica con operandos int.\n", linea);
			return -1;
		}
		$$.tipo = BOOLEANO;
		y(out, $1.es_direccion, $3.es_direccion);
		$$.es_direccion = 0;
		fprintf(out,";R77:\t<exp> ::= <exp> && <exp>\n");
	} | exp TOK_OR exp {
		if($1.tipo!=BOOLEANO || $3.tipo != BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion logica con operandos int.\n", linea);
			return -1;
		}
		$$.tipo = BOOLEANO;
		o(out, $1.es_direccion, $3.es_direccion);
		$$.es_direccion = 0;
		fprintf(out,";R78:\t<exp> ::= <exp> || <exp>\n");
	} | TOK_NOT exp {
		if($2.tipo!=BOOLEANO) {
			fprintf(stdout, "****Error semantico en lin %d : Operacion logica con operandos int.\n", linea);
			return -1;
		}
		$$.tipo = BOOLEANO;
		no(out, $2.es_direccion, num_no++);
		$$.es_direccion = 0;
		fprintf(out,";R79:\t<exp> ::= ! <exp>\n");
	} | TOK_IDENTIFICADOR {
		strcpy($$.nombre, $1.nombre);
    	buscar = UsoLocal($1.nombre);
		if(buscar == NULL) {
			fprintf(stdout, "***Error semantico en lin %d : Acceso a variable no declarada (%s).\n", linea, $1.nombre);
			return -1;
		}
		if (UsoGlobal($1.nombre) == NULL) {
		/* Estamos en una funcion y la variable es local */
			if(buscar->categoria == PARAMETRO) {
				escribirVariableLocal(out, (num_parametros_actual-buscar->adicional1)+1);
			} else {
				escribirVariableLocal(out, -(buscar->adicional1+1));
			}

		} else {
			if(buscar->categoria==FUNCION) {
				/* NUNCA SUCEDE */
				fprintf(stdout,"Identificador no valido\n");
				return -1;
			}
			escribir_operando(out, $1.nombre, 1);

		}
		$$.es_direccion = 1;
		$$.tipo = buscar->tipo;
		fprintf(out, ";R80:\t<exp> ::= <identificador>\n");
	} | constante {
		$$.tipo =$1.tipo;
		$$.es_direccion = $1.es_direccion;
		escribir_operando(out, $1.nombre, 0);
		fprintf(out,";R81:\t<exp> ::= <constante>\n");
	} | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
		$$.tipo = $2.tipo;
    	$$.es_direccion = $2.es_direccion;
		fprintf(out,";R82:\t<exp> ::= ( <exp> )\n");
	} | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
		$$.tipo =BOOLEANO;
		$$.es_direccion = 0;
		fprintf(out,";R83:\t<exp> ::= ( <comparacion> )\n");
	} | elemento_vector {
		fprintf(out,";R85:\t<exp> ::= <elemento_vector>\n");

	} | call_func lista_expresiones TOK_PARENTESISDERECHO {
		buscar = UsoLocal($1.nombre);
		if(buscar == NULL) {
			fprintf(stdout, "***Error semantico en lin %d : Funcion no declarada (%s).\n", linea, $1.nombre);
			return -1;
		}
		if(buscar->categoria != FUNCION){
			fprintf(stdout, "***Error semantico en lin %d : El identificador no es una funcion (%s).\n", linea, $1.nombre);
			return -1;
		}
		if(buscar->adicional1 != params) {
			fprintf(stdout, "***Error semantico en lin %d : Numero incorrecto de parametros en llamada a funcion.\n", linea);
			return -1;
		}
		es_llamada = 0;
		$$.tipo = buscar->tipo;
		llamarFuncion(out, $1.nombre, buscar->adicional1);
		fprintf(out,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
	};

call_func: 
	TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO {
	if(es_llamada) {
		fprintf(stdout, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
		return -1;
	}
	es_llamada = 1;
	params = 0;
	strcpy($$.nombre, $1.nombre);
	};

lista_expresiones: 
	expf resto_lista_expresiones {
		es_llamada = 0;
		params++;
		
		fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
	} |   {
		es_llamada = 0;
		fprintf(out, ";R90:\t<lista_expresiones> ::=\n");
	};

resto_lista_expresiones:
	TOK_COMA expf resto_lista_expresiones {
  		params++;
  		fprintf(out, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
|   {
	fprintf(out, ";R92:\t<resto_lista_expresiones> ::=\n");
};

expf: exp {
  if($1.es_direccion) {
    operandoEnPilaAArgumento(out, $1.es_direccion);
  }
}

comparacion:
	exp TOK_IGUAL exp {
		if($1.tipo != ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		igual(out, $1.es_direccion, $3.es_direccion, num_comparaciones++);
		fprintf(out,";R93:\t<comparacion> ::= <exp> == <exp>\n");
	} | exp TOK_DISTINTO exp {
		if($1.tipo != ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		distinto(out, $1.es_direccion, $3.es_direccion, num_comparaciones++);
		fprintf(out,";R94:\t<comparacion> ::= <exp> != <exp>\n");
	} | exp TOK_MENORIGUAL exp {
		if($1.tipo != ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		menor_igual(out, $1.es_direccion, $3.es_direccion, num_comparaciones++);
		fprintf(out,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
	} | exp TOK_MAYORIGUAL exp {
		if($1.tipo != ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		mayor_igual(out, $1.es_direccion, $3.es_direccion, num_comparaciones++);
		fprintf(out,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
	} | exp TOK_MENOR exp {
		if($1.tipo != ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		menor(out, $1.es_direccion, $3.es_direccion, num_comparaciones++);
		fprintf(out,";R97:\t<comparacion> ::= <exp> < <exp>\n");
	} | exp TOK_MAYOR exp {
		if($1.tipo != ENTERO || $3.tipo != ENTERO) {
			fprintf(stdout, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
			return -1;
		}
		mayor(out, $1.es_direccion, $3.es_direccion, num_comparaciones++);
		fprintf(out,";R98:\t<comparacion> ::= <exp> > <exp>\n");
	};

constante:
	constante_logica {
		$$.tipo = $1.tipo;
		$$.es_direccion = $1.es_direccion;
		strcpy($$.nombre, $1.nombre);
		fprintf(out,";R99:\t<constante> ::= <constante_logica>\n");
	} | constante_entera {
		$$.tipo = $1.tipo;
		$$.es_direccion = $1.es_direccion;
		strcpy($$.nombre, $1.nombre);
		fprintf(out,";R100:\t<constante> ::= <constante_entera>\n");
	};

constante_logica:
	TOK_TRUE {
		$$.tipo = BOOLEANO;
		$$.es_direccion = 0;
		strcpy($$.nombre,"1");
		fprintf(out,";R102:\t<constante_logica> ::= true\n");
	} | TOK_FALSE {
		$$.tipo = BOOLEANO;
		$$.es_direccion = 0;
		strcpy($$.nombre,"0");
		fprintf(out,";R103:\t<constante_logica> ::= false\n");
};

constante_entera:
	TOK_CONSTANTE_ENTERA {
		$$.tipo = ENTERO;
		$$.es_direccion = 0;
		fprintf(out,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
	};

identificador:
	TOK_IDENTIFICADOR {
		buscar = UsoLocal($1.nombre);
		if(buscar != NULL && !EsLocal($1.nombre)) {
			fprintf(stdout, "***Error semantico en lin %d: Declaracion duplicada.\n", linea);
			return -1;
		}
		simbolo.lexema = $1.nombre;
		simbolo.categoria = VARIABLE;
		simbolo.clase = clase_actual;
		simbolo.tipo = tipo_actual;
    	if(clase_actual == VECTOR) {
    	  simbolo.adicional1 = tamVector;

    	}
		else {
			simbolo.adicional1 = 1;
		}
    	if(es_funcion) {
      		if(clase_actual == VECTOR) {
        		fprintf(stdout, "***Error semantico en lin %d : Variable local de tipo no escalar.\n", linea);
        		return -1;
      		}
			simbolo.adicional1 = num_variables_locales_actual;
			num_variables_locales_actual++;
			pos_variable_local_actual++;
    	}
		else {
      		declarar_variable(out, $1.nombre, tipo_actual,  simbolo.adicional1);
        }
    	Declarar($1.nombre, &simbolo);

		fprintf(out,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
	};

tabla: 
	{ 
	escribir_segmento_codigo(out); 
	};

main:
	{ 
	escribir_inicio_main(out);
	};

%%
void yyerror (char const *cad)
{
	if(flagError == 0)
		fprintf(stdout,"*** Error sintáctico en [lin %d, col %d]\n",linea,columna);
	flagError = 0;
}
