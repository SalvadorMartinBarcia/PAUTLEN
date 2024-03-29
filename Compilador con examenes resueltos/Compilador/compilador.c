#include <stdio.h>
#include <string.h>
#include "alfa.h"

int yylex();
int yyparse();
FILE * out = NULL;

int main(int argc, char ** argv) {
    extern FILE * yyin;

    if(argc != 3){
        printf("Faltan argumentos\n");
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        return 1;
    }
    out = fopen(argv[2], "w");
    if(out == NULL) {
        fclose(yyin);
        return 1;
    }
    escribir_subseccion_data(out);
    escribir_cabecera_bss(out);

    if(yyparse()!=0){
        /* Caso de error */
    } else {
        escribir_fin(out);
    }

    fclose(yyin);
    fclose(out);
    return 0;
}