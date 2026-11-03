#include <iostream>
#include <queue>
using namespace std;

class Cola {
private:
    queue<int> datos;
public:
    void encolar(int x) { datos.push(x); }
    bool desencolar(int &x) {
        if (datos.empty()) return false;
        x = datos.front();
        datos.pop();
        return true;
    }
    bool extremos(int &frente, int &final) const {
        if (datos.empty()) return false;
        frente = datos.front();
        final = datos.back();
        return true;
    }
    size_t tamano() const { return datos.size(); }
};

int main() {
    Cola cola;
    int op, x, f, u;

    do {
        cout << "\n--- COLA (queue) ---\n1. Encolar\n2. Desencolar\n3. Frente y final\n4. Tamano\n0. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Valor: ";
            cin >> x;
            cola.encolar(x);
        } else if (op == 2) {
            if (cola.desencolar(x)) cout << "Atendido: " << x << "\n";
            else cout << "Cola vacia\n";
        } else if (op == 3) {
            if (cola.extremos(f, u)) cout << "Frente: " << f << " | Final: " << u << "\n";
            else cout << "Cola vacia\n";
        } else if (op == 4) cout << "Elementos: " << cola.tamano() << "\n";
    } while (op != 0);
    return 0;
}
