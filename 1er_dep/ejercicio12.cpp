#include <iostream>
#include <string>
using namespace std;

struct Coche { string marca, modelo; int anio; };
struct Persona { string nombre; int edad; Coche coche; };

int main() {
    Persona lista[10];
    int n, i;

    cout << "Cuantas personas (1-10): ";
    cin >> n;
    if (n < 1 || n > 10) return 1;

    for (i = 0; i < n; i++) {
        cout << "Persona " << i + 1 << " (nombre edad marca modelo anio): ";
        cin >> lista[i].nombre >> lista[i].edad >> lista[i].coche.marca
            >> lista[i].coche.modelo >> lista[i].coche.anio;
    }

    cout << "\n--- LISTA ---\n";
    for (i = 0; i < n; i++)
        cout << i + 1 << ". " << lista[i].nombre << ", " << lista[i].edad
             << " anios | " << lista[i].coche.marca << " " << lista[i].coche.modelo
             << " (" << lista[i].coche.anio << ")\n";
    return 0;
}
