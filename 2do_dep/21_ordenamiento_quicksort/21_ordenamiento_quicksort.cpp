#include <iostream>
#include <string>
using namespace std;

class Auto {
public:
    double precio;
    string modelo;

    Auto(double p = 0.0, string m = "") : precio(p), modelo(m) {}

    bool operator<(const Auto& a) const { return precio < a.precio; }
    friend ostream& operator<<(ostream& os, const Auto& a) {
        return os << a.modelo << "($" << a.precio << ")";
    }
};

template <typename T>
class Ordenador {
private:
    T** arr;

    void quicksort(int bajo, int alto) {
        if (bajo < alto) {
            T* pivote = arr[alto];
            int i = bajo - 1;
            for (int j = bajo; j < alto; j++) {
                if (*arr[j] < *pivote) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[alto]);

            quicksort(bajo, i);
            quicksort(i + 2, alto);
        }
    }
public:
    void ejecutarOrdenamiento(T* arregloPunteros[], int n) {
        arr = arregloPunteros;
        quicksort(0, n - 1);

        for(int i = 0; i < n; i++) {
            cout << *arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cout << "Ingrese la cantidad de datos a ordenar: ";
    cin >> n;

    int* vInt = new int[n];
    char* vChar = new char[n];
    Auto* vAuto = new Auto[n];

    int** pInt = new int*[n];
    char** pChar = new char*[n];
    Auto** pAuto = new Auto*[n];

    cout << "\n--- Ingreso de " << n << " Enteros ---\n";
    for(int i = 0; i < n; i++) {
        cout << "Valor " << i+1 << ": ";
        cin >> vInt[i];
        pInt[i] = &vInt[i];
    }

    cout << "\n--- Ingreso de " << n << " Caracteres ---\n";
    for(int i = 0; i < n; i++) {
        cout << "Caracter " << i+1 << ": ";
        cin >> vChar[i];
        pChar[i] = &vChar[i];
    }

    cout << "\n--- Ingreso de " << n << " Autos ---\n";
    for(int i = 0; i < n; i++) {
        cout << "Modelo " << i+1 << ": ";
        cin >> vAuto[i].modelo;
        cout << "Precio " << i+1 << ": ";
        cin >> vAuto[i].precio;
        pAuto[i] = &vAuto[i];
    }

    Ordenador<int> oInt;
    cout << "\nEnteros ordenados: ";
    oInt.ejecutarOrdenamiento(pInt, n);

    Ordenador<char> oChar;
    cout << "Caracteres ordenados: ";
    oChar.ejecutarOrdenamiento(pChar, n);

    Ordenador<Auto> oAuto;
    cout << "Autos ordenados por precio: ";
    oAuto.ejecutarOrdenamiento(pAuto, n);

    delete[] vInt;
    delete[] vChar;
    delete[] vAuto;
    delete[] pInt;
    delete[] pChar;
    delete[] pAuto;

    return 0;
}
