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
vector<int> bubbleSortIndirecto(const vector<T>& arr) {
    int n = arr.size();
    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[indices[j + 1]] < arr[indices[j]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    return indices;
}

int main() {
    printf("=== 19. ORDENAMIENTO INDIRECTO BURBUJA ===\n\n");

    vector<EstudiantePOO> alumnos = {
        EstudiantePOO(30, "Fernando", 8.2),
        EstudiantePOO(31, "Carla", 9.4),
        EstudiantePOO(32, "Mario", 7.6)
    };

    printf("Datos originales en memoria:\n");
    for(size_t i = 0; i < alumnos.size(); i++) {
        printf("[%zu] -> ", i); alumnos[i].mostrar();
    }

    vector<int> indices = bubbleSortIndirecto(alumnos);

    printf("\nAccediendo a los datos ordenados mediante el arreglo de indices:\n");
    for(int idx : indices) {
        printf("Indice [%d] -> ", idx);
        alumnos[idx].mostrar();
    }

    return 0;
}
