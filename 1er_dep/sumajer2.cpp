#include <iostream>
using namespace std;

class Aritmetica {
public:
    void sumar(double a, double b) {
        cout << "El resultado de la suma es: " << (a + b) << endl;
    }
};

int main() {
    Aritmetica operacion;
    double num1, num2;
    cout << "--- Ejercicio 2: Suma con Parametros ---" << endl;
    cout << "Ingresa el primer numero: "; cin >> num1;
    cout << "Ingresa el segundo numero: "; cin >> num2;
    operacion.sumar(num1, num2);
    return 0;
}
