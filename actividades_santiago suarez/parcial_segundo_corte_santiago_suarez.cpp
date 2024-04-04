using namespace std;
#include <iostream>


//LEER  PLS:  este codigo no tiene la capacidad de lidiar con numeros repetido porque me quede sin tiempo, por ende la muestra del arbol esstara rota si hay valores repetidos o mayores a la raiz, sin embargo el resto deberia funcionar://

//circular//
struct Node {
    int data;
    Node* next;
};


void insertar_c(Node*& head, int valor) {
    Node* newNode = new Node;
    newNode->data = valor;

    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void display_c(Node* head) {
    if (head == nullptr) {
        cout << "Circular linked list is empty." << endl;
        return;
    }
    
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}



//arbol//

struct nodo {
    int dato;
    nodo *r;
    nodo *l;
};

nodo *crearnodo(int n) {
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->l = NULL;
    nuevo_nodo->r = NULL;
    return nuevo_nodo;
}
	
nodo *arbol = NULL;

void insertar(nodo *&arbol, int n) {
    if (arbol == NULL) {
        nodo *nuevo_nodo = crearnodo(n);
        arbol = nuevo_nodo;
    } else {
        int raiz = arbol->dato;
        if (n < raiz) {
            insertar(arbol->l, n);
        } else {
            insertar(arbol->r, n);
        }
    }
}

void display(nodo *arbol, int contador) {
    int i;
    if (arbol == NULL) {
        return;
    } else {
        display(arbol->r, contador + 1);
        for (i = 0; i < contador; i++) {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        display(arbol->l, contador + 1);
    }
}


//pila///

struct elemento_pila{
    
    int valor; 
    int prioridad;
    elemento_pila* siguiente;
    elemento_pila(int v, int p) : valor(v), prioridad(p), siguiente(nullptr) {}
};
class PilaPrioridad {
private:
    elemento_pila* tope;

public:
    PilaPrioridad() : tope(nullptr) {}

    void agregarelemento_pila(int valor, int prioridad) {
        elemento_pila* nuevo = new elemento_pila(valor, prioridad);
       
        if (tope == nullptr) {
            tope = nuevo;
        } else {
            if (prioridad <= tope->prioridad) {
                nuevo->siguiente = tope;
                tope = nuevo;
            } else {
                elemento_pila* temp = tope;
                while (temp->siguiente != nullptr && temp->siguiente->prioridad < prioridad) {
                    temp = temp->siguiente;
                }
                nuevo->siguiente = temp->siguiente;
                temp->siguiente = nuevo;
            }
        }
    }

    void mostrarPila() {
        elemento_pila* temp = tope;
        cout << "valores en la pila atendidos dada su prioridad:";
        while (temp != nullptr) {
            cout << temp->valor << "(" << temp->prioridad << ") ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

 
};




//cola//


struct elemento_cola {
    int valor;
    int prioridad;
    elemento_cola* siguiente;
   
    elemento_cola(int v, int p) : valor(v), prioridad(p), siguiente(nullptr) {}
};

class ColaPrioridad {
private:
    elemento_cola* frente;
    elemento_cola* final;

public:
    ColaPrioridad() : frente(nullptr), final(nullptr) {}

    void agregarelemento_cola(int valor, int prioridad) {
        elemento_cola* nuevo = new elemento_cola(valor, prioridad);
       
        if (frente == nullptr) {
            frente = nuevo;
            final = nuevo;

        } else {
     
            if (prioridad <= frente->prioridad) {
                nuevo->siguiente = frente;
                frente = nuevo;
            } else if (prioridad >= final->prioridad) {
                final->siguiente = nuevo;
                final = nuevo;
            } else {
                elemento_cola* temp = frente;
                while (temp->siguiente->prioridad < prioridad) {
                    temp = temp->siguiente;
                }
                nuevo->siguiente = temp->siguiente;
                temp->siguiente = nuevo;
            }
        }
    }

    void mostrarCola() {
        elemento_cola* temp = frente;
        cout << "valores en la cola atendidos dada su prioridad: \n";
        while (temp != nullptr) {
            cout << temp->valor << "(" << temp->prioridad << ") ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

};


void menu(){
    Node* head = nullptr;
    PilaPrioridad pila;
    ColaPrioridad cola;
    int dato, input, contador =0,n = 0,valor,input2,prioridad,keep;
    do {
        cout << "Menu:" << endl;
        cout << "1: crear una pila" << endl;
        cout << "2: crear una cola" << endl;
        cout<<"3: atender pila"<<endl;
        cout<<"4: atender cola"<<endl;
        cout<<"5: mostrar conversion: arbol"<<endl;
        cout<<"6: mostrar conversion: lista circular"<<endl; 
        cout << "0: salir" << endl;
        cout << "opcion: ";
        cin >> input;

        switch (input) {
            case 1:
                do {
                
                cout<<"PILA:\n"<<endl;
                cout<<"1:ingresar valor: "<<endl;
                cout<<"2:regresar"<<endl;
                cin>>input2;
                switch(input2){
                    case 1:
                    do{
                        cout<<"ingrese el valor:"<<endl;
                        cin>>valor;
                        dato = valor;
                        insertar_c(head,valor);
                        insertar(arbol, dato);
                        
                        cout<<"ingrese la priridad del valor (siendo 1 la menor-3 la mayor)"<<endl;
                        cin>>prioridad;
                            pila.agregarelemento_pila(valor, prioridad);
                        
                        cout<<"desea ingresar otro valor?\n"<<endl;
                        cout<<"1:si 2:no";
                        cin>>keep;
                        
                    }while(keep != 2);
                    break;
                }
                
                break;
                }while (input2!=0);
            case 2:
                do {
                
                cout<<"cola:\n"<<endl;
                cout<<"1:ingresar valor: "<<endl;
                cout<<"2:regresar"<<endl;
                cin>>input2;
                switch(input2){
                    case 1:
                    do{
                        cout<<"ingrese el valor:"<<endl;
                        cin>>valor;
                        
                         dato = valor;
                        insertar(arbol, dato);
                        
                        cout<<"ingrese la priridad del valor (siendo 1 la menor-3 la mayor)"<<endl;
                        cin>>prioridad;
                            cola.agregarelemento_cola(valor, prioridad);
                        
                        cout<<"desea ingresar otro valor?\n"<<endl;
                        cout<<"1:si 2:no";
                        cin>>keep;
                        
                    }while(keep != 2);
                    break;
                }
                
                break;
                }while (input2!=0);
               
                system("pause");
                break;
               
            case 3:
                
                pila.mostrarPila();
              
                system("pause");
                break;
                
            case 4:
                cola.mostrarCola();
                
                system("pause");
                break;
                
            case 5:
            display(arbol,contador);
            cout<<"\n";
            break;
            
            case 6:
            display_c(head);
           cout<<"\n";
            break;
        }
        system("cls");
    } while (input != 0);
}

    

int main() {
   
   menu();

    return 0;
}