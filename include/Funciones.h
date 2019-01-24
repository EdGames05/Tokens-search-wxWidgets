#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include "AList.h"


using namespace std;

class Funciones
{
    public:
        Funciones();
        virtual ~Funciones();
        char* concatenar_char(const char* cadena, const char* concatenar);
        AList<string> separar(string texto, string separador);
    protected:

    private:
};

#endif // FUNCIONES_H
