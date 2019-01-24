#ifndef ALIST_H
#define ALIST_H

template <class T>
class AList{
private:
    //************* Estructura que almacena la lista **********************//
    struct Nodo{
        T objeto;
        unsigned int pos = 0;
        Nodo *sig;
    };
    Nodo *lista;
    //*********************************************************************//
    void insertar_inicio_private(Nodo *&lista,T objeto);
    void insertar_final_private(Nodo *&lista, T objeto);
    void borrar_at_private(Nodo *&lista, unsigned int pos);
    unsigned int tamano;
public:
    AList();
    AList(T objeto);
    //*************************************************************************//
    //**************************** Funciones publicas *************************//
    void insertar(T objeto);
    void insertar_final(T objeto);
    T obtener_at(unsigned int pos);
    void borrar_at(unsigned int pos);
    void borrar_todosElementos();
    unsigned int get_tamano();
    //*************************************************************************//
    //*************************************************************************//

    //*************************************************************************//
    //**************************** Operadores *********************************//
    AList<T> operator=(AList<T> lista);
    T operator[](const unsigned int indice);
    //*************************************************************************//
    //*************************************************************************//
};

template <class T>
AList<T>::AList(){
    this->lista = NULL;
    this->tamano = 0;
}

template<class T>
AList<T>::AList(T objeto){
    this->lista = NULL;
    this->tamano = 0;
    this->insertar_inicio_private(this->lista,objeto);
    this->tamano++;
}

template<class T>
void AList<T>::insertar(T objeto){
    this->insertar_inicio_private(this->lista,objeto);
    this->tamano++;
}

template<class T>
void AList<T>::insertar_inicio_private(Nodo *&lista, T objeto){
    Nodo *p = new(struct Nodo);
    p->objeto = objeto;
    p->pos = tamano + 1;
    p->sig = lista;
    lista = p;
}

template<class T>
void AList<T>::insertar_final(T objeto){
    this->insertar_final_private(this->lista,objeto);
    this->tamano++;
}

template <class T>
void AList<T>::insertar_final_private(Nodo *&lista, T objeto){
    Nodo *p = new(struct Nodo), *aux;
    p->objeto = objeto;
    p->pos = this->tamano + 1;
    p->sig = lista;

    if(lista == NULL){
        lista = p;
    }
    else{
        aux = lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = p;
    }
}

template <class T>
T AList<T>::obtener_at(unsigned int pos){
    T objeto_nulo;

    if(pos > this->tamano){
        return objeto_nulo;
    }
    else
    if(this->lista == NULL){
        return objeto_nulo;
    }
    else{
        Nodo *aux = this->lista;
        unsigned int i = 0;
        while(aux != NULL){
            if(i == pos){
                return aux->objeto;
            }
            i++;
            aux = aux->sig;
        }

        return objeto_nulo;
    }
}

template <class T>
void AList<T>::borrar_at(unsigned int pos){
    this->borrar_at_private(this->lista,pos);
    this->tamano = 0;
}

template <class T>
void AList<T>::borrar_at_private(Nodo *&lista, unsigned int pos){
    Nodo *p, *ant;
    p = lista;

    if(pos > this->tamano){
        return;
    }
    else{
        if(lista != NULL){
            unsigned int i = 0;
            while(p != NULL){
                if(i == pos){
                    if(p == lista){
                        lista = lista->sig;
                    }
                    else{
                        ant->sig = p->sig;
                    }

                    delete(p);
                    this->tamano = this->tamano - 1;
                    return;
                }
                ant = p;
                p->pos = i;
                p = p->sig;
                i++;
            }
        }
        else{
            return;
        }
    }
}

template<class T>
unsigned int AList<T>::get_tamano(){return this->tamano;}

template<class T>
void AList<T>::borrar_todosElementos(){
    if(this->lista == NULL){
        return;
    }
    else{
        Nodo *aux = this->lista;
        while(aux != NULL){
            aux = this->lista;
            if(lista != NULL){
                lista = aux->sig;
            }
            delete(aux);
        }
        this->tamano = 0;
    }
}

template<class T>
AList<T> AList<T>::operator=(const AList<T> lista){
    if(lista.get_tamano() > 0){
        this->borrar_todosElementos();
        for(unsigned int i = 0; i < lista.get_tamano(); i++){
            this->insertar(lista.obtener_at(i));
        }
        return this;
    }
    else{
        this->borrar_todosElementos();
        return this;
    }
}

template<class T>
T AList<T>::operator[](const unsigned int indice){
    T objeto_nulo;

    if(indice > this->tamano){
        return objeto_nulo;
    }
    else
    if(this->lista == NULL){
        return objeto_nulo;
    }
    else{
        Nodo *aux = this->lista;
        unsigned int i = 0;
        while(aux != NULL){
            if(i == indice){
                return aux->objeto;
            }
            i++;
            aux = aux->sig;
        }

        return objeto_nulo;
    }
}

#endif // ALIST_H
