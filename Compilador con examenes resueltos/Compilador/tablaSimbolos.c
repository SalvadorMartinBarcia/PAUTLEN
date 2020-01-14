#include <stdio.h>
#include "tablaSimbolos.h"

TABLA_HASH *TablaSimbolosGlobal = NULL;
TABLA_HASH *TablaSimbolosLocal = NULL;




STATUS tablaSet(TABLA_HASH *tabla, const char *id, INFO_SIMBOLO *desc_id){ 
    return insertar_simbolo(tabla, id, desc_id->categoria, desc_id->tipo, desc_id->clase, desc_id->adicional1, desc_id->adicional2);
}
INFO_SIMBOLO *tablaGet(TABLA_HASH *tabla, const char *id){
    return buscar_simbolo(tabla, id);
}


STATUS Declarar(const char *id, INFO_SIMBOLO *desc_id){
    if ( TablaSimbolosLocal == NULL) {
        return DeclararGlobal(id, desc_id);;
    }
    else{
        return DeclararLocal(id, desc_id);
    }
}

STATUS DeclararGlobal(const char *id, INFO_SIMBOLO *desc_id){

    /*Si no existe la tabla, se crea*/
    if (TablaSimbolosGlobal == NULL) {
        TablaSimbolosGlobal = crear_tabla(TABLA_SIMBOLOS_GLOBAL_TAM);
        if(TablaSimbolosGlobal == NULL) return ERR;
    }

    if(buscar_simbolo(TablaSimbolosGlobal, id) == NULL){ /*Si no se encuentra, se inserta en la tabla*/
        return tablaSet(TablaSimbolosGlobal, id, desc_id);
    }
    return ERR; 
}

int EsLocal(const char *id) {
    if(TablaSimbolosLocal == NULL) {
        return 0;
    }
    return buscar_simbolo(TablaSimbolosLocal, id)!=NULL;

}

STATUS DeclararLocal(const char *id, INFO_SIMBOLO *desc_id){
    
    if(buscar_simbolo(TablaSimbolosLocal, id) == NULL){ /*Si no se encuentra, se inserta en la tabla*/
        return tablaSet(TablaSimbolosLocal, id, desc_id);;
    }
    return ERR;
}

INFO_SIMBOLO *UsoGlobal(const char *id){
    INFO_SIMBOLO *info = NULL;
    if(id == NULL || TablaSimbolosGlobal == NULL) return NULL;

    info = tablaGet(TablaSimbolosGlobal, id);
    if(info == NULL) return NULL;

    return info;
}

INFO_SIMBOLO *UsoLocal(const char *id){
    INFO_SIMBOLO *info = NULL;

    if(id == NULL) return NULL;

    if(TablaSimbolosLocal == NULL){
        return UsoGlobal(id);
    }
    info = tablaGet(TablaSimbolosLocal, id);
    if(info == NULL) {
        return UsoGlobal(id);
    }

    return info;
}

STATUS DeclararFuncion(const char *id, INFO_SIMBOLO *desc_id){
    if(tablaGet(TablaSimbolosGlobal, id) != NULL) return ERR;

    /*Si no está*/
    if(tablaSet(TablaSimbolosGlobal, id, desc_id) == ERR) return ERR;

    liberar_tabla(TablaSimbolosLocal);
    TablaSimbolosLocal = crear_tabla(TABLA_SIMBOLOS_LOCAL_TAM);

    return tablaSet(TablaSimbolosLocal, id, desc_id);

}

STATUS CerrarFuncion(){
    if(TablaSimbolosLocal) liberar_tabla(TablaSimbolosLocal);
    TablaSimbolosLocal = NULL;
    return OK;
}

void Terminar(){
    if(TablaSimbolosLocal) liberar_tabla(TablaSimbolosLocal);
    if(TablaSimbolosGlobal) liberar_tabla(TablaSimbolosGlobal);
}

