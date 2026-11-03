#include <iostream>
using namespace std;

class CalculadoraSobrecarga {
public:
    // Variante 0 parametros (pide los datos internamente)
    void sumar() {
        double a, b;
        cout << "[0 Params] Ingresa 2 numeros para sumar: "; cin >> a >> b;
        cout << "Resultado (0 params): " << (a + b) << endl;
    }
    // Variante 2 parametros
    void sumar(double a, double b) {
        cout << "[2 Params] Resultado: " << (a + b) << endl;
    }
    // Variante 3 parametros
    void sumar(double a, double b, double c) {
        cout << "[3 Params] Resultado: " << (a + b + c) << endl;
    }
};

int main() {
    CalculadoraSobrecarga calc;
    cout << "--- Ejercicio 4: Sobrecarga ---" << endl;
    calc.sumar(); // Llama a la funcion sin parametros

    double x, y, z;
    cout << "\nIngresa 2 numeros para la variante de 2 parametros: "; cin >> x >> y;
    calc.sumar(x, y);

    cout << "\nIngresa 3 numeros para la variante de 3 parametros: "; cin >> x >> y >> z;
    calc.sumar(x, y, z);

    return 0;
}
