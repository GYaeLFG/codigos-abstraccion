#include <iostream>
using namespace std;

const int MAX = 100;

template <typename T>
class Cola {
    T arreglo[MAX];
    int frente = 0, final = -1;   // Vacia cuando frente > final
public:
    bool estaVacia() { return frente > final; }
    bool estaLlena() { return final == MAX - 1; }

    void encolar(T valor) {
        if (estaLlena()) cout << "Cola llena.\n";
        else arreglo[++final] = valor;
    }

    void desencolar() {
        if (estaVacia()) { cout << "Cola vacia.\n"; return; }
        cout << "Desencolado: " << arreglo[frente++] << "\n";
        if (estaVacia()) { frente = 0; final = -1; }   // Reinicia al vaciarse
    }

    void mostrar() {
        if (estaVacia()) cout << "Cola vacia.";
        for (int i = frente; i <= final; i++) cout << arreglo[i] << " ";
        cout << "\n";
    }
};

int main() {
    Cola<int> c;
    int opcion, valor;

    do {
        cout << "\n--- COLA ---\n1. Encolar\n2. Desencolar\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: cout << "Numero: "; cin >> valor; c.encolar(valor); break;
            case 2: c.desencolar(); break;
            case 3: c.mostrar(); break;
            case 4: break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);
}
