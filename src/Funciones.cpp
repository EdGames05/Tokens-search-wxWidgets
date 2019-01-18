#include "Funciones.h"
#include <stdlib.h>
#include <cstring>
#include <memory>

using namespace std;

Funciones::Funciones()
{
    //ctor
}

Funciones::~Funciones()
{
    //dtor
}

char* Funciones::concatenar_char(const char* cadena,const char* concatenar){
    char *cadena_final = (char*) malloc(1 + strlen(cadena) + strlen(concatenar));
    strcpy(cadena_final,cadena);
    strcat(cadena_final,concatenar);
    free(&cadena);
    free(&concatenar);
    return cadena_final;
}
