#include "Lista.h"

int Lista::buscar(char elem){
    int i=0;
    while(i<=ult){
        if(elem ==datos[i]){
            return i;
        }
        i++;
    }
    return -1;
}

void Lista::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            std::cout<<datos[i];
        }
    }
}

bool Lista::vacia()const{
    return ult==-1;
}
bool Lista::llena()const{
    return ult==TAM-1;
}

bool Lista::inserta(char elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"No se pudo insertar" << endl;
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

bool Lista::elimina(int pos){
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

char Lista::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

int Lista::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}
int Lista::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}
