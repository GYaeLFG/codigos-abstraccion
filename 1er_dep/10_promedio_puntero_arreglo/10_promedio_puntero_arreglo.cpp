#include <iostream>
#include <iomanip>
using namespace std;

class EstadisticaPuntero {
private:
    double numeros[5];
    double* ptr;
public:
    EstadisticaPuntero() {
        ptr = numeros;
    }

    void ingresarDatos() {
        for(int i = 0; i < 5; i++) {
            cout << "Ingrese el numero " << (i + 1) << " : ";
            cin >> *(ptr + i);
        }
    }

    void calcularYMostrar() {
        double suma = 0;
        double maximo = *ptr;
        double minimo = *ptr;

        for(int i = 0; i < 5; i++) {
            suma += *(ptr + i);
            if(*(ptr + i) > maximo) maximo = *(ptr + i);
            if(*(ptr + i) < minimo) minimo = *(ptr + i);
        }

        double promedio = suma / 5.0;

        cout << "\n--- Resultados con Puntero al Arreglo ---" << endl;
        cout << fixed << setprecision(2);
        cout << "Suma: " << suma << endl;
        cout << "Promedio (Media): " << promedio << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
    }
};

int main() {
    EstadisticaPuntero stats;
    stats.ingresarDatos();
    stats.calcularYMostrar();
    return 0;
}
