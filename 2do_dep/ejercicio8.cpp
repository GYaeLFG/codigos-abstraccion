#include <iostream>
#include <stack>
using namespace std;

class Pila {
private:
    stack<int> datos;
public:
    void push(int x) { datos.push(x); }
    bool pop(int &x) {
        if (datos.empty()) return false;
        x = datos.top();
        datos.pop();
        return true;
    }
    bool tope(int &x) const {
        if (datos.empty()) return false;
        x = datos.top();
        return true;
    }
    size_t tamano() const { return datos.size(); }
};

int main() {
    Pila pila;
    int op, x;

    do {
        cout << "\n--- PILA (stack) ---\n1. Push\n2. Pop\n3. Tope\n4. Tamano\n0. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Valor: ";
            cin >> x;
            pila.push(x);
        } else if (op == 2) {
            if (pila.pop(x)) cout << "Sacado: " << x << "\n";
            else cout << "Pila vacia\n";
        } else if (op == 3) {
            if (pila.tope(x)) cout << "Tope: " << x << "\n";
            else cout << "Pila vacia\n";
        } else if (op == 4) cout << "Elementos: " << pila.tamano() << "\n";
    } while (op != 0);
    return 0;
}
