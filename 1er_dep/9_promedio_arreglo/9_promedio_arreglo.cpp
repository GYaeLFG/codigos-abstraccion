#include <iostream>
#include <iomanip>
using namespace std;

class EstadisticaArreglo {
private:
    double numeros[5];
public:
    void ingresarDatos() {
        for(int i = 0; i < 5; i++) {
            cout << "Ingrese el numero " << (i + 1) << ": ";
            cin >> numeros[i];
        }
    }

    void calcularYMostrar() {
        double suma = 0;
        double maximo = numeros[0];
        double minimo = numeros[0];

        for(int i = 0; i < 5; i++) {
            suma += numeros[i];
            if(numeros[i] > maximo) maximo = numeros[i];
            if(numeros[i] < minimo) minimo = numeros[i];
        }

        double promedio = suma / 5.0;

        cout << "\n--- Resultados con Arreglo ---" << endl;
        cout << fixed << setprecision(2);
        cout << "Suma: " << suma << endl;
        cout << "Promedio (Media): " << promedio << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
    }
};

int main() {
    EstadisticaArreglo stats;
    stats.ingresarDatos();
    stats.calcularYMostrar();
    return 0;
}
