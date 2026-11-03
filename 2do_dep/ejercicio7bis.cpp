#include <iostream>
using namespace std;

class Lista {
private:
    struct Nodo { int dato; Nodo *sig; };
    Nodo *cab;
public:
    Lista() : cab(NULL) {}
    ~Lista() { while (cab) eliminar(cab->dato); }
    Lista(const Lista &) = delete;
    Lista &operator=(const Lista &) = delete;

    void insertarInicio(int x) {
        cab = new Nodo{x, cab};
    }

    void insertarFinal(int x) {
        Nodo *n = new Nodo{x, NULL};
        if (!cab) { cab = n; return; }
        Nodo *p = cab;
        while (p->sig) p = p->sig;
        p->sig = n;
    }

    bool eliminar(int x) {
        Nodo **p = &cab;
        while (*p && (*p)->dato != x) p = &(*p)->sig;
        if (!*p) return false;
        Nodo *aux = *p;
        *p = aux->sig;
        delete aux;
        return true;
    }

    bool buscar(int x) const {
        for (Nodo *p = cab; p; p = p->sig)
            if (p->dato == x) return true;
        return false;
    }

    void mostrar() const {
        if (!cab) { cout << "Lista vacia\n"; return; }
        for (Nodo *p = cab; p; p = p->sig) cout << p->dato << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    Lista lista;
    int op, x;

    do {
        cout << "\n--- LISTA ---\n1. Insertar al inicio\n2. Insertar al final\n3. Eliminar\n4. Buscar\n5. Mostrar\n0. Salir\nOpcion: ";
        cin >> op;
        if (op >= 1 && op <= 4) {
            cout << "Valor: ";
            cin >> x;
            if (op == 1) lista.insertarInicio(x);
            else if (op == 2) lista.insertarFinal(x);
            else if (op == 3) cout << (lista.eliminar(x) ? "Eliminado\n" : "No encontrado\n");
            else cout << (lista.buscar(x) ? "Si esta en la lista\n" : "No esta en la lista\n");
        } else if (op == 5) lista.mostrar();
    } while (op != 0);
    return 0;
}
