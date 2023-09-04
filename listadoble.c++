#include<iostream>
#include<conio.h>
using namespace std;

struct nodo
{
    int numero;
    nodo *next;
  
};
nodo *cabeza = NULL;
nodo*cola;
void eleccion();
void agregarcola();

int main(){
int opcion;
eleccion();

}


void agregarcola(int n){

nodo * nuevo = new nodo();
nuevo->numero = n;

if (cabeza==NULL)
{
    cabeza=nuevo;
    cabeza->next = NULL;
    cola = cabeza;
}
else{
    cola->next = nuevo;
    cola = nuevo;

}
cout<<"\nDato ingresado"<<endl;
}

void agregarinicio(int x){

nodo * nuevo = new nodo();
nuevo->numero = x;

if (cabeza==NULL)
{
    cabeza=nuevo;
    cabeza->next = NULL;
    cola = nuevo;
}
else{
    nuevo->next = cabeza;
    cabeza = nuevo;

}
cout<<"\nDato ingresado"<<endl;
}



void show(nodo *cabeza){

    nodo * mostrar = new nodo();
    mostrar = cabeza;

  
    
        while (mostrar != NULL)
        {
            cout<<mostrar->numero<<" -- ";
            mostrar = mostrar->next;
        }
        
    

}


void busqueda(nodo *cabeza, int y){
 bool p= false;
   nodo* bus = new nodo();
    bus=cabeza;

    while((bus !=NULL)&&(bus->numero <=y)){

        if (bus->numero == y)
        {
            p=true;
        }
         bus=bus->next;
    }
    

    if (p==true)
    {
        cout<<"el numero  "<<y<<" Se ha Encontrado" <<endl;
    }
    else{
        cout<<"el numero   "<<y<<"   No se ha encontrado\n"<<endl;
    }
}

void borrar(nodo *&cabeza, int z){
    if (cabeza != NULL)
    {
        nodo * borr;
        nodo *prev = NULL;
        borr = cabeza;
    
    while ((borr != NULL)&&(borr->numero != z))
    {
        prev = borr;
        borr = borr -> next;
    }
    if (borr == NULL)
    {
        cout<<"Dato no encontrado"<<endl;

    }
    else if (prev == NULL)
    {
       cabeza = cabeza -> next;
        delete borr;
    }
    
    else{
        prev ->next = borr ->next;
        delete borr;
    }
    

    }
}




void eleccion(){
    int opcion,numero;

    do
    {
        cout<<"\n"<<endl;
        cout<<"1. Agregar numeros en la cola:  "<<endl;
        cout<<"2. Agregar numeros al Inicio  "<<endl;
        cout<<"3. ver lista "<<endl;
        cout<<"4. Buscar numero en lista "<<endl;
        cout<<"5. Numero a borrar "<<endl;
        cout<<"6. salir"<<endl;
        cout<<"\n"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1 : cout<<"Numero a digitar:   ";
        cin>>numero;
        agregarcola(numero);
            break;

        case 2 : cout<<"Numero a digitar:   ";
        cin>>numero;
       cout<<"\n"<<endl;
        agregarinicio(numero);
            break;

        case 3: show(cabeza);
        cout<<"  "<<endl;
        break;

         case 4:cout<<"Digite numero a buscar:   "<<endl;
        cin>>numero;
        busqueda(cabeza,numero);
        break;

        case 5:cout<<"Digite numero a Borrar:   "<<endl;
        cin>>numero;
        borrar(cabeza,numero);
        break;

        }

    } while (opcion !=6);
    
}