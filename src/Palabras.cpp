#include "Palabras.h"
#include "../sqlite/sqlite3.h"
#include "AList.h"
#include <stdlib.h>
#include <cstring>
#include <memory>
#include "Funciones.h"

using namespace std;

Palabras::Palabras()
{
    func = new Funciones();
    this->error = false;
    this->msgError = "";
    const int rc = sqlite3_open(this->nom_db,&this->db);
    if(rc){
        this->msgError = "No se pudo abrir la base datos...";
        this->error = true;
    }
    else{
        const char *tb_tokens = "CREATE TABLE IF NOT EXISTS bot_tokens(id INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT, token varchar(15) not null);";

        if(sqlite3_exec(db, tb_tokens,0,0,&this->msgError) != SQLITE_OK){
            this->error = true;
        }
        else{
            sqlite3_close(db);
            this->error = false;
            this->msgError = "";
        }
    }
}

Palabras::~Palabras()
{
    this->listaTokens.borrar_todosElementos();
}

bool Palabras::get_message_error(string &msgError){
    msgError = this->msgError;
    return this->error;
}

string Palabras::get_message_error(){
    return this->msgError;
}

AList<string> Palabras::getListaTokens(){
    if(sqlite3_open(this->nom_db,&this->db) != SQLITE_OK){
        this->msgError = "Error al abrir base de datos...";
        this->error = true;
        return this->listaTokens;
    }
    else{
        const char* strquery = "SELECT * FROM bot_tokens";
        sqlite3_stmt *stmt;
        this->listaTokens.borrar_todosElementos();
        int rc = sqlite3_prepare_v2(this->db,strquery,-1,&stmt,NULL);
        if(rc != SQLITE_OK){
            this->msgError = "Error al consultar el listado de tokens";
            this->error = true;
        }
        else{
            while((rc = sqlite3_step(stmt)) == SQLITE_ROW){
                const string palabra = (char*) sqlite3_column_text(stmt,1);
                this->listaTokens.insertar(palabra);
            }
            sqlite3_finalize(stmt);
            sqlite3_close(this->db);
            return this->listaTokens;
        }
    }
}

bool Palabras::insertar_token(const char* token){
    if(sqlite3_open(this->nom_db,&this->db) != SQLITE_OK){
        this->msgError = "Error al abrir base de datos...";
        this->error = true;
        return false;
    }
    else{
        //----------------------- Concatenar tres cadenas -------------------------------------//
        char* strquery = "INSERT INTO bot_tokens(token) VALUES('";
        const char* fin = "')";
        char *query = (char *) malloc(1 + strlen(strquery) + strlen(fin) + strlen(token));
        strcpy(query,strquery);
        strcat(query,token);
        strcat(query,fin);
        //------------------------------------------------------------------------------------//
        if(sqlite3_exec(db, query,0,0,&this->msgError) != SQLITE_OK){
            this->error = true;
            sqlite3_close(db);
            return false;
        }
        else{
            sqlite3_close(db);
            this->error = false;
            this->msgError = "";
            return true;
        }
        free(&strquery);
    }
}

AList<string> Palabras::listar_tokensEncontrados(string texto,AList<string> tokens){
    AList<string> _palabras = func->separar(texto," ");
    AList<string> encontrados;

    if(_palabras.get_tamano() == 0){
        return encontrados;
    }
    unsigned int contador = 0;
    string pala = "";
    for(unsigned int i = 0; i < _palabras.get_tamano(); i++){
        contador = 0;
        pala = "";
        for(unsigned int j = 0; j < tokens.get_tamano(); j++){
            if(tokens.obtener_at(j) == _palabras.obtener_at(i)){
                contador++;
            }
        }

        if(contador > 0){
            encontrados.insertar(_palabras.obtener_at(i) + " - " + std::to_string(contador));
        }
    }
}
