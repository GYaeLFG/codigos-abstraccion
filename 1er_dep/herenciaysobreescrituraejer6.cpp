#include <iostream>
#include <cmath>
using namespace std;

class CalculadoraOriginal {
public:
    virtual int multiplicar(int a, int b) { return a * b; }
    virtual int dividir(int a, int b) { return a / b; }
    virtual int potencia(int base, int exp) { return pow(base, exp); }
};

class CalculadoraSucesiva : public CalculadoraOriginal {
public:
    int multiplicar(int a, int b) override {
        int resultado = 0;
        for(int i = 0; i < abs(b); i++) {
            resultado += abs(a);
        }
        if((a < 0 && b > 0) || (a > 0 && b < 0)) return -resultado;
        return resultado;
    }

    int dividir(int a, int b) override {
        if (b == 0) return 0;
        int cociente = 0;
        int dividendo = abs(a);
        int divisor = abs(b);
        while (dividendo >= divisor) {
            dividendo -= divisor;
            cociente++;
        }
        if((a < 0 && b > 0) || (a > 0 && b < 0)) return -cociente;
        return cociente;
    }

    int potencia(int base, int exp) override {
        if (exp == 0) return 1;
        int resultado = 1;
        for(int i = 0; i < exp; i++) {
            resultado = multiplicar(resultado, base);
        }
        return resultado;
    }
};

int main() {
    CalculadoraSucesiva calc;
    int a, b;
    int opcion;

    cout << "--- Ejercicio 6: Operaciones Sucesivas ---" << endl;
    cout << "1. Multiplicacion (por sumas sucesivas)" << endl;
    cout << "2. Division (por restas sucesivas)" << endl;
    cout << "3. Potencia (por multiplicaciones sucesivas)" << endl;
    cout << "Elige la operacion (1-3): ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= 3) {
        if(opcion == 3) {
            cout << "Ingresa la base: "; cin >> a;
            cout << "Ingresa el exponente: "; cin >> b;
            cout << "\n--- Resultado ---" << endl;
            cout << "Potencia: " << calc.potencia(a, b) << endl;
        } else {
            cout << "Ingresa el primer numero (dividendo/factor): "; cin >> a;
            cout << "Ingresa el segundo numero (divisor/factor): "; cin >> b;
            cout << "\n--- Resultado ---" << endl;
            if (opcion == 1) {
                cout << "Multiplicacion: " << calc.multiplicar(a, b) << endl;
            } else if (opcion == 2) {
                if(b != 0) cout << "Division: " << calc.dividir(a, b) << endl;
                else cout << "Error: Division entre cero." << endl;
            }
        }
    } else {
        cout << "Opcion no valida." << endl;
    }

    return 0;
}
