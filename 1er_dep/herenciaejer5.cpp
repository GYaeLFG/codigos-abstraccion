#include <iostream>
using namespace std;

class CalculadoraBase {
public:
    double sumar(double a, double b) { return a + b; }
    double restar(double a, double b) { return a - b; }
};

class CalculadoraNueva : public CalculadoraBase {
public:
    double multiplicar(double a, double b) { return a * b; }
    double dividir(double a, double b) {
        if(b != 0) return a / b;
        cout << "Error: Division entre cero no permitida." << endl;
        return 0;
    }
};

int main() {
    CalculadoraNueva calc;
    double n1, n2;
    int opcion;

    cout << "--- Ejercicio 5: Calculadora con Herencia ---" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "Elige la operacion (1-4): ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= 4) {
        cout << "Ingresa el primer numero: "; cin >> n1;
        cout << "Ingresa el segundo numero: "; cin >> n2;

        cout << "\n--- Resultado ---" << endl;
        switch(opcion) {
            case 1: cout << "Suma: " << calc.sumar(n1, n2) << endl; break;
            case 2: cout << "Resta: " << calc.restar(n1, n2) << endl; break;
            case 3: cout << "Multiplicacion: " << calc.multiplicar(n1, n2) << endl; break;
            case 4:
                if(n2 != 0) cout << "Division: " << calc.dividir(n1, n2) << endl;
                else calc.dividir(n1, n2);
                break;
        }
    } else {
        cout << "Opcion no valida." << endl;
    }

    return 0;
}
