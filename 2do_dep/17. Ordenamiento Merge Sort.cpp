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
void mezclar(vector<T>& arr, int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L[i] < R[j] || !(R[j] < L[i])) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

template <typename T>
void mergeSort(vector<T>& arr, int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSort(arr, izq, medio);
        mergeSort(arr, medio + 1, der);
        mezclar(arr, izq, medio, der);
    }
}

int main() {
    printf("=== 17. ORDENAMIENTO MERGE SORT ===\n\n");

    // Enteros
    vector<int> enteros = {38, 27, 43, 3, 9, 82, 10};
    printf("Enteros antes: ");
    for(int x : enteros) printf("%d ", x);
    mergeSort(enteros, 0, enteros.size() - 1);
    printf("\nEnteros despues: ");
    for(int x : enteros) printf("%d ", x);
    printf("\n\n");

    // Caracteres
    vector<char> chars = {'x', 'a', 'p', 'c', 'e'};
    printf("Caracteres antes: ");
    for(char c : chars) printf("%c ", c);
    mergeSort(chars, 0, chars.size() - 1);
    printf("\nCaracteres despues: ");
    for(char c : chars) printf("%c ", c);
    printf("\n\n");

    // Nuevo tipo de dato (POO)
    vector<EstudiantePOO> alumnos = {
        EstudiantePOO(10, "Sofia", 9.1),
        EstudiantePOO(11, "Pedro", 6.5),
        EstudiantePOO(12, "Maria", 9.9)
    };
    printf("Alumnos ordenados por promedio (Merge Sort):\n");
    mergeSort(alumnos, 0, alumnos.size() - 1);
    for(const auto& a : alumnos) a.mostrar();

    return 0;
}
