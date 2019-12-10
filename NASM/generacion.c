
#include <stdio.h>
#include "generacion.h"
#include "alfa.h"
/*leer escribir escribir subseccion data*/

/*
Código para el principio de la sección .bss.
Con seguridad sabes que deberás reservar una variable entera para guardar el
puntero de pila extendido (esp). Se te sugiere el nombre __esp para esta variable.*/
void escribir_cabecera_bss(FILE* fpasm){

	fprintf(fpasm,"segment .bss\n");
	fprintf(fpasm,"\t__esp resd 1\n");

	return;
}

/*
Declaración (con directiva db) de las variables que contienen el texto de los
mensajes para la identificación de errores en tiempo de ejecución.
En este punto, al menos, debes ser capaz de detectar la división por 0.*/
void escribir_subseccion_data(FILE* fpasm){

	fprintf(fpasm,"segment .data\n");
	fprintf(fpasm, "\tmsg_error db \"Error en el programa\" , 0\n");
	fprintf(fpasm, "\tmsg_rango db \"Indice de vector fuera de rango\" , 0\n");
	fprintf(fpasm, "\terror_div0 db \"Error al dividir entre 0\", 0\n");

	return;
}

/*
Para ser invocada en la sección .bss cada vez que se quiera declarar una
variable:
- El argumento nombre es el de la variable.
- tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes
del principio del fichero).
- Esta misma función se invocará cuando en el compilador se declaren
vectores, por eso se adjunta un argumento final (tamano) que para esta
primera práctica siempre recibirá el valor 1.
*/
void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){

	fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano); /*4 bytes*/

	return;
}

/*
Para escribir el comienzo del segmento .text, básicamente se indica que se
exporta la etiqueta main y que se usarán las funciones declaradas en la librería
alfalib.o
*/
void escribir_segmento_codigo(FILE* fpasm){

	fprintf(fpasm, "segment .text \n");
	fprintf(fpasm, "\tglobal main \n");
	fprintf(fpasm, "\textern scan_int, scan_boolean, print_int, scan_float, print_boolean, print_endofline, print_blank, print_string, alfa_malloc, alfa_free, ld_float\n");

	return;
}

/*
En este punto se debe escribir, al menos, l
a etiqueta main y la sentencia que
guarda el puntero de pila en su variable (se recomienda usar __esp).
*/
void escribir_inicio_main(FILE* fpasm){

	fprintf(fpasm, "main: \n");
	fprintf(fpasm, "\tmov dword [__esp], esp ; Guarda el puntero de la pila \n");

	return;
}

/*
Al final del programa se escribe:
- El código NASM para salir de manera controlada cuando se detecta un error
en tiempo de ejecución (cada error saltará a una etiqueta situada en esta
zona en la que se imprimirá el correspondiente mensaje y se saltará a la
zona de finalización del programa).
- En el final del programa se debe:
·Restaurar el valor del puntero de pila (a partir de su variable __esp)
·Salir del programa (ret).
*/
void escribir_fin(FILE* fpasm){

	fprintf(fpasm, "\tjmp fin\n");
	fprintf(fpasm, "fin_div0: \n");
	fprintf(fpasm, "\tpush dword error_div0\n");
	fprintf(fpasm, "\tcall print_string\n");
	fprintf(fpasm, "\tadd esp, 4\n");
	fprintf(fpasm, "\tcall print_endofline\n");
	fprintf(fpasm, "\tjmp fin\n");

	fprintf(fpasm, "fin_error: \n");
	fprintf(fpasm, "\tpush dword msg_error\n");
	fprintf(fpasm, "\tcall print_string\n");
	fprintf(fpasm, "\tadd esp, 4\n");
	fprintf(fpasm, "\tcall print_endofline\n");
	fprintf(fpasm, "\tjmp fin\n");

	fprintf(fpasm, "fin:\n");
	fprintf(fpasm, "\tmov dword esp, [__esp]\n");
	fprintf(fpasm, "\tret\n");

	fprintf(fpasm, "fin_indice_fuera_rango: \n");
	fprintf(fpasm, "\tpush dword msg_rango\n");
	fprintf(fpasm, "\tcall print_string\n");
	fprintf(fpasm, "\tadd esp, 4\n");
	fprintf(fpasm, "\tcall print_endofline\n");
	fprintf(fpasm, "\tjmp fin\n");

}

/*
Función que debe ser invocada cuando se sabe un operando de una operación
aritmético-lógica y se necesita introducirlo en la pila.
- nombre es la cadena de caracteres del operando tal y como debería aparecer
en el fuente NASM
- es_variable indica si este operando es una variable (como por ejemplo b1)
con un 1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el
primer caso internamente se representará como _b1 y, sin embargo, en el
segundo se representará tal y como esté en el argumento (34).
*/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){ /*no estoy segura si este funcionará*/

	if(es_variable == 1){
		fprintf(fpasm, "\tpush dword _%s \n",nombre);
	}else{
		fprintf(fpasm, "\tpush dword %s \n", nombre);
	}
	/*Aqui falta hacer un push*/

}

/*
- Genera el código para asignar valor a la variable de nombre nombre.
- Se toma el valor de la cima de la pila.+
- El último argumento es el que indica si lo que hay en la cima de la pila es
una referencia (1) o ya un valor explícito (0).
*/
void asignar(FILE* fpasm, char* nombre, int es_variable){

	fprintf(fpasm, "\tpop eax\n");

	if(es_variable == 1){
		fprintf(fpasm, "\tmov dword eax, [eax] \n");
	}
	fprintf(fpasm, "\tmov [_%s], eax\n", nombre);

	return;
}




/*- Se extrae de la pila los operandos
- Se realiza la operación
- Se guarda el resultado en la pila
Los dos últimos argumentos indican respectivamente si lo que hay en la pila es
una referencia a un valor o un valor explícito.
Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido
sí hay que mencionar explícitamente que, en el caso de la división, se debe
controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error
controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno
que no se produce “Segmentation Fault”)*/


void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){

	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword eax\n");
	fprintf(fpasm, "\tpop dword edx\n");

	if(es_variable_1 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}
	if(es_variable_2 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}
	/*Se realiza la operacion*/
	fprintf(fpasm, "\tadd eax, edx\n");

	/*Se guarda el res en pila*/
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){

	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword edx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable_1 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}
	if(es_variable_2 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}
	/*Se realiza la operacion*/
	fprintf(fpasm, "\tsub eax, edx\n");

	/*Se guarda el res en pila*/
	fprintf(fpasm, "\tpush dword eax\n");

	return;

}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){

	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword eax\n");
	fprintf(fpasm, "\tpop dword ebx\n");

	if(es_variable_1 == 1){
		fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}
	if(es_variable_2 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}
	/*Se realiza la operacion*/
	fprintf(fpasm, "\t imul ebx\n");

	/*Se guarda el res en pila*/
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
    /*Se extraen de la pila los operandos*/
    fprintf(fpasm, "\tpop dword ecx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    fprintf(fpasm, "\tcdq\n");

    if(es_variable_1 == 1){
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }
    if(es_variable_2 == 1){
        fprintf(fpasm, "\tmov dword ecx, [ecx]\n");
    }
    /*Se realiza la operacion*/
    fprintf(fpasm, "\tcmp ecx, 0\n");
    fprintf(fpasm, "\tje error_div0\n"); /*Si es 0, que salte la etiqueta de error*/
    fprintf(fpasm, "\tidiv ecx\n");

    /*Se guarda el res en pila*/
    fprintf(fpasm, "\tpush dword eax\n");

    return;
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){

	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword eax\n");
	fprintf(fpasm, "\tpop dword ebx\n");

	if(es_variable_1 == 1){
		fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}
	if(es_variable_2 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}
	/*Se realiza la operacion*/
	fprintf(fpasm, "\t or eax, ebx\n");

	/*Se guarda el res en pila*/
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}
void y(FILE* fpasm, int es_variable_1, int es_variable_2){
	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword eax\n");
	fprintf(fpasm, "\tpop dword edx\n");

	if(es_variable_1 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}
	if(es_variable_2 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}
	/*Se realiza la operacion*/
	fprintf(fpasm, "\t and eax, edx\n");

	/*Se guarda el res en pila*/
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}
void cambiar_signo(FILE* fpasm, int es_variable){
	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	/*Se realiza la operacion*/
	fprintf(fpasm, "\tneg eax\n");

	/*Se guarda el res en pila*/
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}

void no(FILE* fpasm, int es_variable, int cuantos_no){
	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	fprintf(fpasm, "\tor eax, eax\n");
	fprintf(fpasm, "\tjz near negar_falso%d\n", cuantos_no);

	fprintf(fpasm, "\tmov dword eax, 0\n");
	fprintf(fpasm, "\tjmp near fin_negacion%d\n", cuantos_no);

	fprintf(fpasm, "negar_falso%d:\n", cuantos_no);
	fprintf(fpasm, "\tmov dword eax,1\n");

	fprintf(fpasm, "fin_negacion%d:\n", cuantos_no);

	/*Se guarda el res en pila*/
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}
/*Funciones comparativas*/

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	/*Se extraen de la pila los operandos*/
	fprintf(fpasm, "\tpop dword edx\n");
	fprintf(fpasm, "\tpop dword eax\n");


	if(es_variable1 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable2 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}

	fprintf(fpasm, "\tcmp eax,edx\n");
	fprintf(fpasm, "\tje near igual%d\n", etiqueta);
	fprintf(fpasm, "\tpush dword 0\n");
	fprintf(fpasm, "\tjmp near fin_igual%d\n", etiqueta);

	fprintf(fpasm, "igual%d:\n", etiqueta);
	fprintf(fpasm, "\tpush dword 1\n");
	fprintf(fpasm, "fin_igual%d:\n", etiqueta);

	return;
}
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

	fprintf(fpasm, "\tpop dword edx\n");
	fprintf(fpasm, "\tpop dword eax\n");


	if(es_variable1 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable2 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}

	fprintf(fpasm, "\tcmp eax,edx\n");
	fprintf(fpasm, "\tjne near distinto%d\n", etiqueta);
	fprintf(fpasm, "\tpush dword 0\n");
	fprintf(fpasm, "\tjmp near fin_distinto%d\n", etiqueta);

	fprintf(fpasm, "distinto%d:\n", etiqueta);
	fprintf(fpasm, "\tpush dword 1\n");
	fprintf(fpasm, "fin_distinto%d:\n", etiqueta);
	return;
}
void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

	fprintf(fpasm, "\tpop dword edx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable1 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable2 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}

	fprintf(fpasm, "\tcmp eax,edx\n");
	fprintf(fpasm, "\tjle near menorigual%d\n", etiqueta);
	fprintf(fpasm, "\tpush dword 0\n");
	fprintf(fpasm, "\tjmp near fin_menorigual%d\n", etiqueta);

	fprintf(fpasm, "menorigual%d:\n", etiqueta);
	fprintf(fpasm, "\tpush dword 1\n");
	fprintf(fpasm, "fin_menorigual%d:\n", etiqueta);

	return;
}
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

	fprintf(fpasm, "\tpop dword edx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable1 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable2 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}

	fprintf(fpasm, "\tcmp eax,edx\n");
	fprintf(fpasm, "\tjge near mayorigual%d\n", etiqueta);;
	fprintf(fpasm, "\tpush dword 0\n");
	fprintf(fpasm, "\tjmp near fin_mayorigual%d\n", etiqueta);

	fprintf(fpasm, "mayorigual%d:\n", etiqueta);
	fprintf(fpasm, "\tpush dword 1\n");
	fprintf(fpasm, "fin_mayorigual%d:\n", etiqueta);

	return;
}
void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

	fprintf(fpasm, "\tpop dword edx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable1 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable2 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}

	fprintf(fpasm, "\tcmp eax,edx\n");
	fprintf(fpasm, "\tjl near menor%d\n", etiqueta);
	fprintf(fpasm, "\tpush dword 0\n");
	fprintf(fpasm, "\tjmp near fin_menor%d\n", etiqueta);;

	fprintf(fpasm, "menor%d:\n", etiqueta);;
	fprintf(fpasm, "\tpush dword 1\n");
	fprintf(fpasm, "fin_menor%d:\n", etiqueta);

	return;
}
void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

	fprintf(fpasm, "\tpop dword edx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable1 == 1){
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable2 == 1){
		fprintf(fpasm, "\tmov dword edx, [edx]\n");
	}

	fprintf(fpasm, "\tcmp eax,edx\n");
	fprintf(fpasm, "\tjg near mayor%d\n", etiqueta);
	fprintf(fpasm, "\tpush dword 0\n");
	fprintf(fpasm, "\tjmp near fin_mayor%d\n", etiqueta);

	fprintf(fpasm, "mayor%d:\n", etiqueta);
	fprintf(fpasm, "\tpush dword 1\n");
	fprintf(fpasm, "fin_mayor%d:\n", etiqueta);

	return;
}

/*SEGUNDA PARTE DE LA PRÁCTICA*/

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

	fprintf(fpasm, "\tpop eax \n");

	if (exp_es_variable == 1){
		fprintf(fpasm, "\tmov eax, [eax]\n");
	}

	fprintf(fpasm, "\tcmp eax,0\n");

	/*Si es 0, salta a la etiqueta*/
	fprintf(fpasm, "\tje near fin_then%d \n", etiqueta);

	return;
}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

	fprintf(fpasm, "\tpop eax \n");

	if (exp_es_variable == 1){
		fprintf(fpasm, "\tmov eax, [eax]\n");
	}

	fprintf(fpasm, "\tcmp eax,0\n");

	/*Si es 0, salta a la etiqueta*/
	fprintf(fpasm, "\tje near fin_then%d \n", etiqueta);

	return;
}

void ifthen_fin(FILE * fpasm, int etiqueta){

	fprintf(fpasm, "fin_then%d:\n", etiqueta);
	return;
}

void ifthenelse_fin_then( FILE * fpasm, int etiqueta){

	// SE SALTA AL FIN DEL IFTHENELSE, ES DECIR, LA RAMA ELSE
	fprintf(fpasm, "\tjmp near fin_ifelse%d \n", etiqueta);

	// SE ESCRIBE LA ETIQUETA DE FIN DE LA RAMA THEN
	fprintf(fpasm, "fin_then%d:\n", etiqueta);

	return;
}


void ifthenelse_fin( FILE * fpasm, int etiqueta){

// SE ESCRIBE LA ETIQUETA DEL FINAL DE LA ESTRUCTURA IFTHENELSE
	fprintf(fpasm, "fin_ifelse%d: \n", etiqueta);
	return;
}


void while_inicio(FILE * fpasm, int etiqueta) {
// SE ESCRIBE LA ETIQUETA DE INICIO DE WHILE
	fprintf(fpasm, "inicio_while%d: \n", etiqueta);
	return;
}


void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta) {

// SE SACA DE LA CIMA DE LA PILA EL VALOR DE LA EXPRESIÓN QUE GOBIERNA EL BUCLE
	fprintf(fpasm, "\tpop dword eax \n");

	if (exp_es_variable > 0){
		fprintf(fpasm, "\tmov dword eax, [eax] \n");
	}

    fprintf(fpasm, "\tcmp eax, 0\n");

    // SI ES 0 SE SALTA AL FINAL DEL WHILE, HABRÍAMOS TERMINADO
    fprintf(fpasm, "\tje near fin_while%d \n", etiqueta);

    return;
}


void while_fin( FILE * fpasm, int etiqueta){

	// SE SALTA DE NUEVO AL PRINCIIO DEL BUCLE PARA VOLVER A EVALUAR LA CONDICION DE SALIDA
	fprintf(fpasm, "\tjmp near inicio_while%d \n", etiqueta);

	// SE ESCRIBE LA ETIQUETA DE FIN DEL BUCLE
	fprintf(fpasm, "fin_while%d:\n", etiqueta);

	return;
}



void escribir_elemento_vector(FILE * fpasm, char * nombre_vector, int tam_max, int exp_es_direccion) {

	// SE SACA DE LA PILA A UN REGISTRO EL VALOR DEL ÍNDICE
	fprintf(fpasm, "\tpop dword eax \n");
	// HACIENDO LO QUE PROCEDA EN EL CASO DE QUE SEA UNA DIRECCIÓN (VARIABLE O EQUIVALENTE)
	if (exp_es_direccion == 1){
		fprintf(fpasm, "\tmov dword eax, [eax] \n");
	}

	// SE PROGRAMA EL CONTROL DE ERRORES EN TIEMPO DE EJECUCIÓN
	/* SI EL INDICE ES <0 SE TERMINA EL PROGRAMA, SI NO, CONTINUA */
	fprintf(fpasm, "\tcmp eax, 0 \n");
	// SE SUPONE QUE EN LA DIRECCIÓN fin_indice_fuera_rango SE PROCESA ESTE ERROR EN TIEMPO DE EJECUCIÓN

	fprintf(fpasm, "\tjl near fin_indice_fuera_rango\n");
	/* SI EL INDICE ES > MAXIMO PERMITIDO SE TERMINA EL PROGRAMA, SI NO, CONTINUA */
	// EL TAMANO MÁXIMO SE PROPORCIONA COMO ARGUMENTO
	fprintf(fpasm, "\tcmp eax, %d \n", tam_max-1);
	fprintf(fpasm, "\tjg near fin_indice_fuera_rango \n");
	// UNA OPCIÓN ES CALCULAR CON lea LA DIRECCIÓN EFECTIVA DEL ELEMENTO INDEXADO TRAS CALCULARLA
	// DESPLAZANDO DESDE EL INICIO DEL VECTOR EL VALOR DEL INDICE
	fprintf(fpasm, "\tmov dword edx, _%s \n", nombre_vector);
	fprintf(fpasm, "\tlea eax, [edx + eax*4] \n");
	fprintf(fpasm, "\tpush dword eax \n");

	return;
}


void declararFuncion(FILE * fd_asm, char * nombre_funcion, int num_var_loc) {

	fprintf(fd_asm, "%s: \n", nombre_funcion);
	fprintf(fd_asm, "\tpush ebp \n");
	fprintf(fd_asm, "\tmov ebp, esp \n");
	fprintf(fd_asm, "\tsub esp, %d \n", 4*num_var_loc);

	return;
}


void retornarFuncion(FILE * fd_asm, int es_variable) {

	fprintf(fd_asm, "\tpop eax\n");
	if(es_variable == 1){
	fprintf(fd_asm, "\tmov dword eax, [eax]\n");
	}
	
	fprintf(fd_asm, "\tmov esp,ebp\n");
	fprintf(fd_asm, "\tpop ebp\n");
	fprintf(fd_asm, "\tret\n");

	return;
}


void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){
	int d_ebp = 4*( 1 + (num_total_parametros - pos_parametro));

	fprintf(fpasm, "\tlea eax ,[ebp + %d] \n", d_ebp);
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){
	int d_ebp = 4*posicion_variable_local;

	fprintf(fpasm, "\tlea eax, [ebp - %d] \n", d_ebp);
	fprintf(fpasm, "\tpush dword eax\n");

	return;
}

void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable){

	if (es_variable == 1){
		fprintf(fd_asm,"\tpop dword eax \n");
		fprintf(fd_asm,"\tmov dword eax, [eax]\n");
		fprintf(fd_asm, "\tpush dword eax \n");
	}
	return;
}

void asignarDestinoEnPila(FILE* fpasm, int es_variable){
	fprintf(fpasm,"\tpop dword ebx \n");
	fprintf(fpasm,"\tpop dword eax \n");

	if(es_variable == 1){
		fprintf(fpasm,"\tmov dword eax,[eax]\n");
	}
	fprintf(fpasm,"\tmov dword [ebx], eax\n");
	return;
}


void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos) {


	fprintf(fd_asm, "\tcall %s \n", nombre_funcion);
	fprintf(fd_asm, "\tadd esp, %d\n", num_argumentos*4);
	fprintf(fd_asm, "\tpush dword eax \n");
	return;
}


void limpiarPila(FILE * fd_asm, int num_argumentos){

	fprintf(fd_asm, "\tadd esp, %d*4\n", num_argumentos);
	return;
}


void leer(FILE* fpasm, char* nombre, int tipo){

if(tipo == 0){ /*int*/
		fprintf(fpasm, "\tpush dword _%s\n", nombre);
		fprintf(fpasm, "\tcall scan_int\n");
		fprintf(fpasm, "\tadd esp, 4\n");
	}else{ /*boolean*/
		fprintf(fpasm, "\tpush dword _%s\n", nombre);
		fprintf(fpasm, "\tcall scan_boolean\n");
		fprintf(fpasm, "\tadd esp, 4\n");

	}
	return;
}
void escribir(FILE* fpasm, int es_variable, int tipo){

	/*Se extraen de la pila los operandos*/
	if(es_variable == 1){
		fprintf(fpasm, "\tpop dword eax\n");
		fprintf(fpasm, "\tmov dword eax,[eax]\n");
		fprintf(fpasm, "\tpush dword eax\n");
	}

	if(tipo == 0){ /*int*/
		fprintf(fpasm, "\tcall print_int\n");
	}else{ /*boolean*/
		fprintf(fpasm, "\tcall print_boolean\n");
	}

	fprintf(fpasm, "\tadd esp, 4\n");
	fprintf(fpasm, "\tcall print_endofline\n");

	return;
}
