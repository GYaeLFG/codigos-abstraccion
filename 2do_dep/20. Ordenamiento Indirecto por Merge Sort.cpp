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
void mezclarIndirecto(const vector<T>& arr, vector<int>& indices, int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = indices[izq + i];
    for (int j = 0; j < n2; j++) R[j] = indices[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (arr[L[i]] < arr[R[j]] || !(arr[R[j]] < arr[L[i]])) indices[k++] = L[i++];
        else indices[k++] = R[j++];
    }
    while (i < n1) indices[k++] = L[i++];
    while (j < n2) indices[k++] = R[j++];
}

template <typename T>
void mergeSortIndirectoRec(const vector<T>& arr, vector<int>& indices, int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSortIndirectoRec(arr, indices, izq, medio);
        mergeSortIndirectoRec(arr, indices, medio + 1, der);
        mezclarIndirecto(arr, indices, izq, medio, der);
    }
}

template <typename T>
vector<int> mergeSortIndirecto(const vector<T>& arr) {
    int n = arr.size();
    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    mergeSortIndirectoRec(arr, indices, 0, n - 1);
    return indices;
}

int main() {
    printf("=== 20. ORDENAMIENTO INDIRECTO MERGE SORT ===\n\n");

    vector<EstudiantePOO> alumnos = {
        EstudiantePOO(40, "Monica", 9.3),
        EstudiantePOO(41, "Hector", 6.8),
        EstudiantePOO(42, "Diana", 8.9)
    };

    printf("Datos originales en memoria:\n");
    for(size_t i = 0; i < alumnos.size(); i++) {
        printf("[%zu] -> ", i); alumnos[i].mostrar();
    }

    vector<int> indices = mergeSortIndirecto(alumnos);

    printf("\nAccediendo a los datos ordenados mediante Merge Sort Indirecto:\n");
    for(int idx : indices) {
        printf("Indice [%d] -> ", idx);
        alumnos[idx].mostrar();
    }

    return 0;
}
