#include <iostream>

int main() {
    int totnum;
    double num, sum = 0, min, max;

    std::cout << "Ingrese el numero de valores deseados: ";
    std::cin >> totnum;

    if (totnum <= 0) {
        std::cout << "Porfavor ingrese numeros validos.\n";
        return 1; 
    }
   
    std::cout << "Ingrese numero:1: ";
    std::cin >> num;

    sum = min = max = num; 

  
    for (int i = 2; i <= totnum; ++i) {
        std::cout << "Ingrese numero:" << i << ": ";
        std::cin >> num;
        sum += num;
       
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }


    double promedio = sum / totnum;

  
    std::cout << "\nResults:\n";
    std::cout << "Numero menor: " << min << "\n";
    std::cout << "Numero mayor : " << max << "\n";
    std::cout << "Promedio        : " << promedio << "\n";

    return 0;
}