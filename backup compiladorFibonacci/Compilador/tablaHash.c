
#include <string.h>
#include <stdlib.h>
#include "tablaHash.h"


/*Tenemos que crear el tad Info_Simbolo*/
INFO_SIMBOLO *crear_info_simbolo(const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2){
    INFO_SIMBOLO* newInfoSimb = NULL;

    newInfoSimb = (INFO_SIMBOLO*) malloc(sizeof(INFO_SIMBOLO));
    if(newInfoSimb == NULL) return NULL;

    newInfoSimb->lexema= strdup(lexema);
    if(newInfoSimb->lexema == NULL){
        free(newInfoSimb);
        return NULL;
    }
    newInfoSimb->categoria = categ;
    newInfoSimb->tipo = tipo;
    newInfoSimb->clase = clase;
    newInfoSimb->adicional1 = adic1;
    newInfoSimb->adicional2 = adic2;

    return newInfoSimb;
}

void liberar_info_simbolo(INFO_SIMBOLO *is){
    if (!is){
        return;
    }
    if(is->lexema)
        free(is->lexema);
    free(is);
    return;
}

NODO_HASH *crear_nodo(INFO_SIMBOLO *is){
    NODO_HASH* newNodo = NULL;

    newNodo = (NODO_HASH*) malloc(sizeof(NODO_HASH));
    if(newNodo == NULL) return NULL;

    newNodo->info = is;
    newNodo->siguiente = NULL;
    
    return newNodo;
}

void liberar_nodo(NODO_HASH *nh){
    if (!nh){
        return;
    }
    liberar_info_simbolo(nh->info);
    free(nh);
    return;    
}

TABLA_HASH *crear_tabla(int tam){
    TABLA_HASH *newTabla = NULL;

    newTabla = (TABLA_HASH*) malloc(sizeof(TABLA_HASH));
    if(newTabla == NULL) return NULL;

    newTabla->tabla =  (NODO_HASH **) calloc(tam, sizeof(NODO_HASH *));
    if(newTabla->tabla == NULL){
        free(newTabla);
            return NULL;
    }

    newTabla->tam = tam;

    return newTabla;
}

void liberar_tabla(TABLA_HASH *th){
    int i;
    NODO_HASH *naux1, *naux2;
    if (!th){
        return;
    }

    for(i = 0; i < th->tam; i++){
        naux1 = th->tabla[i];
                /* Liberar lista enlazada de cada uno */
                while (naux1) {
                    naux2 = naux1->siguiente;
                    liberar_nodo(naux1);
                    naux1 = naux2;      
                }
    }
    free(th->tabla);

    free(th);
    return;
}
unsigned long hash(const char *str){ /*Puede tener errores*/
    unsigned long hash = HASH_INI;
    unsigned char *c;

    for (c = (unsigned char *) str; *c; c++) {
        hash = hash*HASH_FACTOR + *c;
    }

    return hash;
}

INFO_SIMBOLO *buscar_simbolo(const TABLA_HASH *th, const char *lexema){ /*Ojala este bien*/
    NODO_HASH* nodo = NULL;

    nodo = th->tabla[(hash(lexema) % th->tam)]; /*Hash div*/
    if(!nodo) return NULL;
    while(strcmp(nodo->info->lexema, lexema)){ /*Vamos buscando el símbolo por los nodos*/
        if(nodo->siguiente == NULL) return NULL; /*Si no hay mas nodos y no lo hemos encontrado, es que no está*/
        nodo = nodo->siguiente;
    }
    return nodo->info;
}

STATUS insertar_simbolo(TABLA_HASH *th, const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2){
    INFO_SIMBOLO *newSimb = NULL;
    NODO_HASH *newNodo = NULL;
    int indice;

    if(buscar_simbolo(th, lexema) != NULL){
        return ERR; /*Ya está en la tabla*/
    }

    newSimb = crear_info_simbolo(lexema,categ,tipo,clase,adic1,adic2);
    if(newSimb == NULL) return ERR;

    newNodo = crear_nodo(newSimb);
    if(newNodo == NULL){
        liberar_info_simbolo(newSimb);
        return ERR;
    }

    /*Insertamos el simbolo en la tabla*/
    indice = hash(lexema) % th->tam;
    newNodo->siguiente = th->tabla[indice];
    th->tabla[indice] = newNodo;

    return OK;
}    

void borrar_simbolo(TABLA_HASH *th, const char *lexema){
    NODO_HASH *nodo, *anterior = NULL;
    int indice;


    indice =  hash(lexema) % th->tam;
    /*Primero buscamos el nodo que contiene el simbolo*/
    nodo = th->tabla[indice];

    while(strcmp(nodo->info->lexema, lexema)){ /*Vamos buscando el símbolo por los nodos*/
        if(nodo->siguiente == NULL) return; /*Si no hay mas nodos y no lo hemos encontrado, es que no está*/
        anterior = nodo;
        nodo = nodo->siguiente;
    }

    /*Reasignamos los enlaces de cada nodo para que sigan conectados*/
    if(anterior == NULL){ /*Si es el primero*/
        th->tabla[indice] = nodo->siguiente;
        liberar_nodo(nodo);
        return;
    }

    anterior->siguiente = nodo->siguiente;
    liberar_nodo(nodo);
    return;
}
