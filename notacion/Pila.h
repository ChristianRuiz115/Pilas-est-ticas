#ifndef PILA_H
#define PILA_H
#include <iostream>

#define TAM 50

using namespace std;

class Pila{
private:
    char datos[TAM];
    int ult;
    bool inserta(char, int);
    bool elimina(int);
    char recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Pila():ult(-1){}
    bool vacia()const;
    bool llena()const;
    int buscar(char);
    bool push(char);
    bool pop();
    char top()const;
};

#endif
