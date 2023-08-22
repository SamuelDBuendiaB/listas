#include<iostream>
#include<conio.h>
using namespace std;

struct lista
{
    int numero;
    lista *next;
};

lista *orden = NULL ;
void eleccion();
void agregaralista(lista*&,int);
void show(lista*);

int main(){

eleccion();
getch();
return 0;
}


void agregaralista(lista *&orden,int i){
    lista * nuevo_nodo = new lista();

    nuevo_nodo->numero = i;

    lista * nodo1 = orden;
    lista * nodo2;

while((nodo1 !=NULL )&&(nodo1->numero < i)){
    nodo2 = nodo1;
    nodo1 = nodo1->next;    
}

if(orden == nodo1 ){

orden = nuevo_nodo;

}
else {
    nodo2->next = nuevo_nodo;
}
nuevo_nodo->next = nodo1;

cout<<"\ndato ingresado";
}

void show(lista *orden){

    lista * mostrar = new lista();
    mostrar = orden;

    while(mostrar != NULL){
        cout<<mostrar->numero<<" -- ";
        mostrar = mostrar->next;
    }

}

void eleccion(){
    int opcion,numero;

    do
    {
        cout<<"\n 1. Agregar numeros:  "<<endl;
        cout<<"2. Agregar ver lista"<<endl;
        cout<<"3. salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1 : cout<<"Numero a digitar:   ";
        cin>>numero;
        agregaralista(orden,numero);
            break;


        case 2 : show(orden);
        cout<<"   "<<endl;
            break;
    
        }

    } while (opcion !=3);
    
}