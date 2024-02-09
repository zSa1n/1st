
#include <iostream>

int main() {

    double num1, num2, num3, num4, num5, num6;


    std::cout << "Ingrese el Primer numero :";
    std::cin >> num1;

    std::cout << "Ingrese el Segundo numero :";
    std::cin >> num2;
    
    std::cout <<"Ingrese el Tercer numero :";
    std::cin >>num3;
    
    std::cout <<"Ingrese el Cuarto numero :";
    std::cin >>num4;

    std::cout <<"Ingrese el Quinto numero :";
    std::cin >>num5;
    
    std::cout <<"Ingrese el Sexto numero :";
    std::cin >>num6;


double sum1r = num1 + num2;
double sum2r = num3 + num4;
double sum3r = num5 + num6;


double mult1r = num1 * num2;
double mult2r = num3 * num4;
double mult3r = num5 * num6;


    std::cout << "------------------------\n";
    std::cout << "|   "<<num1<<"   |  "<<num2<<"  | "<<" + "<< sum1r <<"  | "<<" * "<<mult1r << "\ |\n";
    std::cout << "------------------------\n";
    std::cout << "|   "<<num3<<"   |  "<<num4<<"  | "<<" + "<< sum2r <<"  | "<<" * "<<mult2r << "\ |\n";
    std::cout << "------------------------\n";
    std::cout << "|   "<<num5<<"   |  "<<num6<<"  | "<<" + "<< sum3r <<"  | "<<" * "<<mult3r << "\ |\n";
    std::cout << "------------------------\n";
    
    getch();
    
    return 0;

}
