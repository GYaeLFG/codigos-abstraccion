#include <iostream>
using namespace std;

class CalculadoraBasica {
public:
    void sumar(double a, double b) { cout << "Suma: " << (a + b) << endl; }
    void restar(double a, double b) { cout << "Resta: " << (a - b) << endl; }
    void multiplicar(double a, double b) { cout << "Multiplicacion: " << (a * b) << endl; }
    void dividir(double a, double b) {
        if(b != 0) cout << "Division: " << (a / b) << endl;
        else cout << "Error: Division entre cero no permitida." << endl;
    }
};

int main() {
    CalculadoraBasica calc;
    double n1, n2;
    int opcion;

    cout << "--- Ejercicio 3: Calculadora Basica ---" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "Elige la operacion que deseas realizar (1-4): ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= 4) {
        cout << "Ingresa el primer numero: "; cin >> n1;
        cout << "Ingresa el segundo numero: "; cin >> n2;

        cout << "\n--- Resultado ---" << endl;
        switch(opcion) {
            case 1: calc.sumar(n1, n2); break;
            case 2: calc.restar(n1, n2); break;
            case 3: calc.multiplicar(n1, n2); break;
            case 4: calc.dividir(n1, n2); break;
        }
    } else {
        cout << "Opcion no valida. Intenta de nuevo." << endl;
    }

    return 0;
}
