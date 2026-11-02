#include <iostream>
using namespace std;

const int MAX = 100;

template <typename T>
class Pila {
    T arreglo[MAX];
    int tope = -1;   // -1 = vacia
public:
    bool estaVacia() { return tope == -1; }
    bool estaLlena() { return tope == MAX - 1; }

    void apilar(T valor) {
        if (estaLlena()) cout << "Pila llena.\n";
        else arreglo[++tope] = valor;
    }

    void desapilar() {
        if (estaVacia()) cout << "Pila vacia.\n";
        else cout << "Desapilado: " << arreglo[tope--] << "\n";
    }

    void mostrar() {
        if (estaVacia()) cout << "Pila vacia.\n";
        for (int i = tope; i >= 0; i--) cout << arreglo[i] << "\n";
    }
};

int main() {
    Pila<int> p;
    int opcion, valor;

    do {
        cout << "\n--- PILA ---\n1. Apilar\n2. Desapilar\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: cout << "Numero: "; cin >> valor; p.apilar(valor); break;
            case 2: p.desapilar(); break;
            case 3: p.mostrar(); break;
            case 4: break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);
}
