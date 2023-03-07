#ifndef LISTA_H
#define LISTA_H
#include <iostream>

#define TAM 50

using namespace std;

class Lista{
private:
    char datos[TAM];
    int ult;
public:
    Lista():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool inserta(char , int);
    bool elimina(int);
    char recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
    int buscar(char);
};

#endif
