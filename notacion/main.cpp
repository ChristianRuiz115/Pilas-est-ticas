#include <iostream>
#include "Pila.h"
#include "Lista.h"

using namespace std;

int preferencia(char simbolo) {
	switch(simbolo){
		case '^':
			return 3;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;	
	}
}

bool es_operando(char simbolo){
	if((simbolo >= 'a' && simbolo <= 'z') || (simbolo >= 'A' && simbolo <= 'Z')){
		return true;
	}
	return false;
}

int main() {
    Pila pila;
    Lista lista;
	int cont_lista = 0;
	string exp;
    cout << "Ingrese una expresion: ";
    cin >> exp;    
	int tam_exp;
	tam_exp = exp.size();
    for (int i = 0; i < tam_exp; i++) {
        if (es_operando(exp[i])){
            lista.inserta(exp[i],cont_lista);
            cont_lista++;
        }
        else {
            while (!pila.vacia() && preferencia(pila.top()) >= preferencia(exp[i])) {
                lista.inserta(pila.top(),cont_lista);
                cont_lista++;
                pila.pop();
            }
            pila.push(exp[i]);
        }
    }
    while (!pila.vacia()) {
        lista.inserta(pila.top(),cont_lista);
        pila.pop();
        cont_lista++;
    }
    cout << "Resultado: ";
    lista.imprime();
    return 0;
}
