#include "Funciones.h"
#include <stdlib.h>
#include <cstring>
#include <string>
#include <memory>
#include "AList.h"

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

AList<string> Funciones::separar(string texto, string separador){
    AList<string> lista;
    if((texto == "") || (separador == "")){
        return lista;
    }
    else{
        string pala = "";
        for(unsigned int i = 0; i < texto.size(); i++){
            if(texto[i] != '\0' && texto[i] != '\n' && texto[i] != separador[0]){
                pala += texto[i];
            }
            else
            if(texto[i] == separador[0]){
                lista.insertar(pala);
                pala = "";
            }
        }
        return lista;
    }
}
