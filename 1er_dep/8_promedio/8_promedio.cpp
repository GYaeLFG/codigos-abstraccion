#include <iostream>
#include <iomanip>
using namespace std;

class EstadisticaBasica {
private:
    double n1, n2, n3, n4, n5;
public:
    void ingresarDatos() {
        cout << "Ingrese el numero 1: "; cin >> n1;
        cout << "Ingrese el numero 2: "; cin >> n2;
        cout << "Ingrese el numero 3: "; cin >> n3;
        cout << "Ingrese el numero 4: "; cin >> n4;
        cout << "Ingrese el numero 5: "; cin >> n5;
    }

    void calcularYMostrar() {
        double suma = n1 + n2 + n3 + n4 + n5;
        double promedio = suma / 5.0;

        double maximo = n1, minimo = n1;
        if(n2 > maximo) maximo = n2; if(n2 < minimo) minimo = n2;
        if(n3 > maximo) maximo = n3; if(n3 < minimo) minimo = n3;
        if(n4 > maximo) maximo = n4; if(n4 < minimo) minimo = n4;
        if(n5 > maximo) maximo = n5; if(n5 < minimo) minimo = n5;

        cout << "\n--- Resultados ---" << endl;
        cout << fixed << setprecision(2);
        cout << "Suma: " << suma << endl;
        cout << "Promedio (Media): " << promedio << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
    }
};

int main() {
    EstadisticaBasica stats;
    stats.ingresarDatos();
    stats.calcularYMostrar();
    return 0;
}
