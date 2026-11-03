#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Lista {
private:
    list<int> datos;
public:
    void insertarInicio(int x) { datos.push_front(x); }
    void insertarFinal(int x) { datos.push_back(x); }
    bool eliminar(int x) {
        list<int>::iterator it = find(datos.begin(), datos.end(), x);
        if (it == datos.end()) return false;
        datos.erase(it);
        return true;
    }
    bool buscar(int x) const {
        return find(datos.begin(), datos.end(), x) != datos.end();
    }
    void mostrar() const {
        if (datos.empty()) { cout << "Lista vacia\n"; return; }
        for (list<int>::const_iterator it = datos.begin(); it != datos.end(); ++it)
            cout << *it << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    Lista lista;
    int op, x;

    do {
        cout << "\n--- LISTA (list) ---\n1. Insertar al inicio\n2. Insertar al final\n3. Eliminar\n4. Buscar\n5. Mostrar\n0. Salir\nOpcion: ";
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
