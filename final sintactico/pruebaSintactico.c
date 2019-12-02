#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
extern FILE *yyout;

int main (int argc, char **argv) {
  if(argc != 3){
    printf("FALTAN ARGUMENTOS\n");
    return -1;
  }
  /*Abrimos el fichero en modo lectura*/
  yyin=fopen(argv[1],"r");

  if(yyin == NULL){
    printf("ERROR AL ABRIR FICHERO: %s\n", argv[1]);
    return -1;
  }

  /*Escribimos en el fichero de salida*/
  yyout = fopen(argv[2],"w");

  if(yyout == NULL){
    printf("ERROR AL ABRIR FICHERO: %s\n", argv[2]);
    fclose(yyin);
    return-1;
  }

  yyparse();

  fclose(yyout);
  fclose(yyin);
  return 0;
}
