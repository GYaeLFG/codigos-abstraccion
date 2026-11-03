#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class EstudiantePOO {
private:
    int codigo;
    string nombre;
    float promedio;
public:
    EstudiantePOO(int c = 0, string n = "", float p = 0.0) : codigo(c), nombre(n), promedio(p) {}
    bool operator<(const EstudiantePOO& otro) const { return this->promedio < otro.promedio; }
    void mostrar() const { printf("Codigo: %d | Nombre: %-10s | Promedio: %.2f\n", codigo, nombre.c_str(), promedio); }
};

template <typename T>
int particionar(vector<T>& arr, int bajo, int alto) {
    T pivote = arr[alto];
    int i = (bajo - 1);
    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            T temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    T temp = arr[i + 1]; arr[i + 1] = arr[alto]; arr[alto] = temp;
    return (i + 1);
}

template <typename T>
void quickSort(vector<T>& arr, int bajo, int alto) {
    if (bajo < alto) {
        int pi = particionar(arr, bajo, alto);
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int main() {
    printf("=== 18. ORDENAMIENTO QUICK SORT ===\n\n");

    // Enteros
    vector<int> enteros = {10, 7, 8, 9, 1, 5};
    printf("Enteros antes: ");
    for(int x : enteros) printf("%d ", x);
    quickSort(enteros, 0, enteros.size() - 1);
    printf("\nEnteros despues: ");
    for(int x : enteros) printf("%d ", x);
    printf("\n\n");

    // Caracteres
    vector<char> chars = {'h', 'e', 'l', 'l', 'o'};
    printf("Caracteres antes: ");
    for(char c : chars) printf("%c ", c);
    quickSort(chars, 0, chars.size() - 1);
    printf("\nCaracteres despues: ");
    for(char c : chars) printf("%c ", c);
    printf("\n\n");

    // Nuevo tipo de dato (POO)
    vector<EstudiantePOO> alumnos = {
        EstudiantePOO(20, "Jorge", 7.5),
        EstudiantePOO(21, "Lucia", 8.8),
        EstudiantePOO(22, "Raul", 6.2)
    };
    printf("Alumnos ordenados por promedio (Quick Sort):\n");
    quickSort(alumnos, 0, alumnos.size() - 1);
    for(const auto& a : alumnos) a.mostrar();

    return 0;
}
