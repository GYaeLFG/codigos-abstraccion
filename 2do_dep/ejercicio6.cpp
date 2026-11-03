#include <iostream>
using namespace std;

class Pila {
private:
    struct Nodo { int dato; Nodo *sig; };
    Nodo *tope;
public:
    Pila() : tope(NULL) {}
    ~Pila() { int x; while (pop(x)); }
    Pila(const Pila &) = delete;
    Pila &operator=(const Pila &) = delete;

    void push(int x) {
        tope = new Nodo{x, tope};
    }

    bool pop(int &x) {
        if (!tope) return false;
        Nodo *aux = tope;
        x = aux->dato;
        tope = aux->sig;
        delete aux;
        return true;
    }

    void mostrar() const {
        if (!tope) { cout << "Pila vacia\n"; return; }
        for (Nodo *p = tope; p; p = p->sig) cout << "| " << p->dato << " |\n";
    }
};

int main() {
    Pila pila;
    int op, x;

    do {
        cout << "\n--- PILA ---\n1. Push\n2. Pop\n3. Mostrar\n0. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Valor: ";
            cin >> x;
            pila.push(x);
        } else if (op == 2) {
            if (pila.pop(x)) cout << "Sacado: " << x << "\n";
            else cout << "Pila vacia\n";
        } else if (op == 3) pila.mostrar();
    } while (op != 0);
    return 0;
}
