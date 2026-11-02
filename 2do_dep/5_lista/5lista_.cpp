#include <iostream>
using namespace std;

const int MAX = 100;

template <typename T>
class ListaEstatica {
    T arreglo[MAX];
    int cantidad = 0;   // Elementos actuales
public:
    bool estaVacia() { return cantidad == 0; }
    bool estaLlena() { return cantidad == MAX; }

    void insertar(T valor) {
        if (estaLlena()) cout << "Lista llena.\n";
        else arreglo[cantidad++] = valor;
    }

    void eliminar(int pos) {
        if (pos < 0 || pos >= cantidad) { cout << "Posicion no valida.\n"; return; }
        cout << "Eliminado: " << arreglo[pos] << "\n";
        for (int i = pos; i < cantidad - 1; i++) arreglo[i] = arreglo[i + 1];
        cantidad--;
    }

    void mostrar() {
        if (estaVacia()) cout << "Lista vacia.\n";
        for (int i = 0; i < cantidad; i++) cout << "[" << i << "] -> " << arreglo[i] << "\n";
    }
};

int main() {
    ListaEstatica<int> l;
    int opcion, valor, pos;

    do {
        cout << "\n--- LISTA ---\n1. Insertar\n2. Eliminar por posicion\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: cout << "Numero: "; cin >> valor; l.insertar(valor); break;
            case 2: cout << "Posicion: "; cin >> pos; l.eliminar(pos); break;
            case 3: l.mostrar(); break;
            case 4: break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);
}
