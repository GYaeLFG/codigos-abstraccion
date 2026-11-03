#include <iostream>
#include <string>
using namespace std;

struct Coche { string marca, modelo; int anio; };
struct Persona { string nombre; int edad; Coche coche; };

int main() {
    Persona lista[10], *p = lista;
    int n, i;

    cout << "Cuantas personas (1-10): ";
    cin >> n;
    if (n < 1 || n > 10) return 1;

    for (i = 0; i < n; i++, p++) {
        cout << "Persona " << i + 1 << " (nombre edad marca modelo anio): ";
        cin >> p->nombre >> p->edad >> p->coche.marca >> p->coche.modelo >> p->coche.anio;
    }

    cout << "\n--- LISTA (acceso con puntero) ---\n";
    for (p = lista, i = 1; p < lista + n; p++, i++)
        cout << i << ". " << p->nombre << ", " << p->edad << " anios | "
             << p->coche.marca << " " << p->coche.modelo
             << " (" << p->coche.anio << ")\n";
    return 0;
}
