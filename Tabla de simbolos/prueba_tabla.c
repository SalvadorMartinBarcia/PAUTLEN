#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"

#define BUF_SIZE 1024

void procesa(char *buf, FILE *out) {
    INFO_SIMBOLO *info = NULL;
    char *id = NULL;
    int scan, value;
    scan = sscanf(buf, "%ms\t%i", &id, &value);
    if(scan == 2) {
        if(value < 0) {
            if(!strcmp(id, "cierre") && value == -999) {
                fprintf(out, "cierre\n");
                free(id);
                CerrarFuncion();
            } else {
                info = crear_info_simbolo(id, FUNCION, ENTERO, ESCALAR, value, 0);
                if(info == NULL) {
                    free(id);
                    return;
                }
                if(DeclararFuncion(id, info) == OK){
                    fprintf(out, "%s\n", id);}
                else
                    fprintf(out, "-1\t%s\n", id);

                liberar_info_simbolo(info);
                free(id);
            }
        } else if(value > 0) {
            info = crear_info_simbolo(id, VARIABLE, ENTERO, ESCALAR, value, 0);
            if(info == NULL) {
                free(id);
                return;
            }
            if(Declarar(id, info) == OK)
                fprintf(out, "%s\n", id);
            else
                fprintf(out, "-1\t%s\n", id);
            liberar_info_simbolo(info);
            free(id);
        }
    } else if(scan == 1) {
        info = UsoLocal(id);
        if(info == NULL)
            fprintf(out, "%s\t%d\n", id, -1);
        else
            fprintf(out, "%s\t%d\n", id, info->adicional1);
        free(id);
    }
}

int main(int argc, char **argv) {
    FILE *in = NULL, *out = NULL;
    char buf[BUF_SIZE];
    if(argc != 3) {
        printf("Faltan argumentos\n");
        return 0;
    }
    in = fopen(argv[1], "r");
    if(in == NULL) {
        printf("Error al abrir el archivo de entrada\n");
        return 1;
    }
    out = fopen(argv[2], "w");
    if(out == NULL) {
        printf("Error al abrir el archivo de salida\n");
        return 1;
    }
    while(fgets(buf, BUF_SIZE, in) != NULL) {
        procesa(buf, out);
    }
    Terminar();
    fclose(in);
    fclose(out);
}