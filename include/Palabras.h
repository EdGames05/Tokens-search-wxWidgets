/*--------------------- Ed Company ---------------------*/

#ifndef PALABRAS_H
#define PALABRAS_H

#include <string>
#include "AList.h"

class sqlite3;
class Funciones;
using namespace std;

class Palabras
{
    public:
        Palabras();
        virtual ~Palabras();
        bool get_message_error(string &msgError);
        string get_message_error();
        AList<string> getListaTokens();
        bool insertar_token(const char* token);
        AList<string> listar_tokensEncontrados(string texto, AList<string> tokens);
        bool eliminar_token(const char* token);
    protected:

    private:
        const char* nom_db = "archi.ala";
        Funciones *func;
        sqlite3 *db;
        char* msgError = "";
        bool error = false;
        AList<string> listaTokens;
};

#endif // PALABRAS_H
