#include <iostream>

using namespace std;

struct Nodo {
    int num;
    Nodo* next;
};

class lista_base {
private:
    Nodo* head;
    int primer_num;

public:
    lista_base() : head(nullptr), primer_num(-1) {}


void agregar(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->num = valor;
        nuevoNodo->next = nullptr;
        if (head == nullptr) {
            head = nuevoNodo;
            primer_num = valor;
        } else {
            Nodo* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nuevoNodo;
        }
}




void eliminar(int valor) {
        Nodo* act = head;
        Nodo* ant = nullptr;
        bool eliminado = false;
       
       
       
while (act != nullptr) {
        if (act->num == valor) {
            if (ant == nullptr) {
                   head = act->next;
            } else {
                ant->next = act->next;
                   
       
                }
                Nodo* temp = act;
                act = act->next;
                delete temp;
                eliminado = true;
            } else {
                ant = act;
                act = act->next;
       
       
            }
        }

        if (!eliminado) {
            cout << "Valor no encontrado en la lista" << endl;
            return;
        }

        cout << valor << "   ha sido eliminado de la lista" << endl;

if (valor == primer_num) {
            cout << "eliminando toda la lista..." << endl;
while (head != nullptr) {
    Nodo* temp = head;
    head = head->next;
    delete temp;
        }
    }
   }
   
   
 Nodo* buscar(int valor) {
        Nodo* act = head;
        while (act != nullptr) {
            if (act->num == valor) {
                cout << "Valor " << valor << " contenido en la direccion: " << act << endl;
            }
            act = act->next;
        }
        return nullptr;
    }




void mostrar_lista() {
        Nodo* act = head;
        cout << "Lista:" << endl;
        while (act != nullptr) {
            cout<< " ";
            cout << "   "<<   act->num << endl;
            act = act->next;
        }
    }
};



int main() {
    lista_base lista;
    int eleccion;
    int valor;

do {
        cout << "elija una opcion:" << endl;
        cout << "1. agregar un nuevo valor" << endl;
        cout << "2. buscar un valor" << endl;
        cout << "3. eliminar un valor" << endl;
        cout << "4. mostrar lista" << endl;
        cout << "5. salir" << endl;
        cout << "ingrese su eleccion: ";
        cin >> eleccion;

switch (eleccion) {
        case 1:
            cout << "Ingrese el valor que desea agregar: ";
            cin >> valor;
            lista.agregar(valor);
            cout << "Valor agregado con exito." << endl;
            break;
        case 2:
            cout << "Ingrese el valor que desea buscar: ";
            cin >> valor;
            lista.buscar(valor);
            break;
        case 3:
            cout << "Ingrese el valor que desea eliminar: ";
            cin >> valor;
            lista.eliminar(valor);
            break;
        case 4:
            lista.mostrar_lista();
            break;
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "opcion invalida, intentelo nuevamente" << endl;
      }
        
}
while (eleccion != 5);

return 0;
}



manejo de listas

60% 

40% 

manejo de arreglos

arrays

arreglo de 20 posiciones, ingresar datos del usuario nums
ordenarlos de mayor a mayor


listas 

crear lista con nodos y ordenarlos a medida del ingreso de los valores

