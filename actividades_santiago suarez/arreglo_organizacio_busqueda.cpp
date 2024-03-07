
#include <iostream>
#include <algorithm>

using namespace std;

// organizacion por ingreso //
void Ingreso_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i+1 << ": ";
        cin >> arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}

// organizacion metodo burbuja //
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
        if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        }
    }
}
}

// busqueda binaria //
int binaria(int arr[], int l, int r, int x) {
    while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) {
    return mid;
    }
    if (arr[mid] < x) {
    l = mid + 1;
    }
    else {
    r = mid - 1;
    }
}
    return -1;
}

int main() {
    int tama�o;
    cout << "Ingrese el tama�o del arreglo: ";
    cin >> tama�o;

    int arr[tama�o];
    int copia_arr[tama�o];
    Ingreso_sort(arr, tama�o);
   
   

    for (int i = 0; i < tama�o; i++) {
    copia_arr[i] = arr[i];
    }
 
    cout << "Arreglo ordenado por metodo de ingreso:" << endl;
    for (int i = 0; i < tama�o; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;

   
    bubbleSort(copia_arr, tama�o);

    cout << "Arreglo ordenado por el metodo burbuja:" << endl;
    for (int i = 0; i < tama�o; i++) {
    cout << copia_arr[i] << " ";
    }
    cout << endl;

 
    int buscar;
    cout << "Ingrese el valor que desea buscar: ";
    cin >> buscar;
    int result = binaria(copia_arr, 0, tama�o - 1, buscar);

    if (result != -1) {
    cout << "El valor " << buscar << " se encuentra en la posici�n " << result << " del arreglo ordenado." << endl;
    } else {
    cout << "El valor " << buscar << " no se encuentra en el arreglo ordenado." << endl;
    }

    return 0;
}
