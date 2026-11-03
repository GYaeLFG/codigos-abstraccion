#include <iostream>
using namespace std;

class Cola {
private:
    struct Nodo { int dato; Nodo *sig; };
    Nodo *frente, *final;
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola() { int x; while (desencolar(x)); }
    Cola(const Cola &) = delete;
    Cola &operator=(const Cola &) = delete;

    void encolar(int x) {
        Nodo *n = new Nodo{x, NULL};
        if (final) final->sig = n;
        else frente = n;
        final = n;
    }

    bool desencolar(int &x) {
        if (!frente) return false;
        Nodo *aux = frente;
        x = aux->dato;
        frente = aux->sig;
        if (!frente) final = NULL;
        delete aux;
        return true;
    }

    void mostrar() const {
        if (!frente) { cout << "Cola vacia\n"; return; }
        for (Nodo *p = frente; p; p = p->sig) cout << p->dato << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    Cola cola;
    int op, x;

    do {
        cout << "\n--- COLA ---\n1. Encolar\n2. Desencolar\n3. Mostrar\n0. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Valor: ";
            cin >> x;
            cola.encolar(x);
        } else if (op == 2) {
            if (cola.desencolar(x)) cout << "Atendido: " << x << "\n";
            else cout << "Cola vacia\n";
        } else if (op == 3) cola.mostrar();
    } while (op != 0);
    return 0;
}
