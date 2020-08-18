/*Mostrar los elementos de la lista
 *
 * Para mostrar los elementos de la lista sólo hay que seguir 3 pasos.
 *
 * 1. Crear un nuevo nodo(actual).
 * 2. Igualar ese nuevo nodo(actual) a lista.
 * 3. Recorrer la lista de inicio a fin.*/

#include<iostream>
#include<stdlib.h>
#include <stdio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void menu();
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);
void eliminarNodo(Nodo *&,int);
void eliminarLista(Nodo *&,int &);

Nodo *lista = NULL;

int main(){
    
    menu();

    return 0;
}
void menu(){
    int opcion,dato;

    do{
        cout<<"\t....:Menu:....\n";
        cout<<"1. Insertar elementos a la lista\n";
        cout<<"2. Mostrar elementos en la lista\n";
        cout<<"3. Buscar un elemento en la lista\n";
        cout<<"4. Borrar elemento\n";
        cout<<"5. Eliminar todos los elementos de la lista\n";
        cout<<"6. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion){
            
            case 1: cout<<"\nDigite un numero: ";
                    cin>>dato;
                    insertarLista(lista,dato);
                    cout<<"\n";
                    dato=getchar();
                    break;

            case 2: mostrarLista(lista);
                    cout<<"\n";
                    dato=getchar();
                    break;
            
            case 3: cout<<"\nDigite un numero a buscar: ";
                    cin>>dato;
                    buscarLista(lista,dato);
                    cout<<"\n";
                    dato=getchar();
                    break;
            
            case 4: cout<<"\nDigite el nodo a eliminar: ";
                    cin>>dato;
                    eliminarNodo(lista,dato);
                    cout<<"\n";
                    dato=getchar();
                    break;
            
            case 5: while (lista != NULL){
                        eliminarLista(lista,dato);
                        cout<<dato<<" -> ";
                    }
                    cout<<"\n";
                    dato=getchar();
                    break;
        }                
        cout<<"\n";
        dato=getchar();
        system("clear");
    }while(opcion != 6);
}
void insertarLista(Nodo *&lista,int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;

    }

    if(lista == aux1){
        lista = nuevo_nodo;
    }
    else{
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cout<<"\nElemento "<<n<<" incertado a lista correctamente. Presione enter para continuar\n";
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();

    actual = lista;
    while (actual != NULL){
        
        cout<<actual->dato<<" -> ";
        actual = actual->siguiente;
    }
}

void buscarLista(Nodo *lista,int n){
    bool band = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while((actual != NULL) && (actual->dato <= n)){
        if(actual->dato == n){
            band = true;

        }
        actual = actual ->siguiente;
    }
    if(band == true){
        cout<<"\nElemento "<<n<<" Si a sido encontrado en la lista. Presione enter para continuar\n";

    }
    else{
        cout<<"\nElemento "<<n<<" No a sido encontrado en la lista\n";
    }
}
void eliminarNodo(Nodo *&lista,int n){
    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        while((aux_borrar != NULL) && (aux_borrar->dato != n)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar == NULL){
            cout<<"\nElemento "<<n<<" no existe. Presione enter para continuar\n";
        }
        else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
            cout<<"\nElemento "<<n<<" ha sido borrado con exito. Presione enter para continuar\n";
        }
        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout<<"\nElemento "<<n<<" ha sido borrado con exito. Presione enter para continuar\n";
        }
    }
}
void eliminarLista(Nodo *&lista,int &n){
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;
}



