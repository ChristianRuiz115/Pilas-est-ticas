#include "Pila.h"

char Pila::top()const{
    return datos[ult];
}

bool Pila::pop(){
    if(vacia()){
        return false;
    }
    else{
        elimina(ultimo());
    }
    return true;
}

bool Pila::push(char elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem,ultimo()+1);
    }
    return true;
}

int Pila::buscar(char elem){
    int i=0;
    while(i<=ult){
        if(elem ==datos[i]){
            return i;
        }
        i++;
    }
    return -1;
}

void Pila::imprime()const{
    if(!vacia()){
        char x;
        for(int i=0; i<=ult; i++){
            x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

bool Pila::vacia()const{
    return ult==-1;
}
bool Pila::llena()const{
    return ult==TAM-1;
}

bool Pila::inserta(char elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

bool Pila::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

char Pila::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

int Pila::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}
int Pila::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}
