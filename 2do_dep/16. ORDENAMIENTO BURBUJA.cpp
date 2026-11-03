
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
    EstudiantePOO(int c = 0, string n = "", float p = 0.0f)
        : codigo(c), nombre(n), promedio(p) {}

    bool operator<(const EstudiantePOO& otro) const {
        return promedio < otro.promedio;
    }

    void mostrar() const {
        printf("Codigo: %d | Nombre: %s | Promedio: %.2f\n",
               codigo, nombre.c_str(), promedio);
    }
};

template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    printf("=== 16. ORDENAMIENTO BURBUJA ===\n\n");

    vector<int> enteros = {45, 12, 89, 3, 22};

    printf("Enteros antes: ");
    for (int x : enteros) {
        printf("%d ", x);
    }

    bubbleSort(enteros);

    printf("\nEnteros despues: ");
    for (int x : enteros) {
        printf("%d ", x);
    }

    printf("\n\n");

    vector<char> caracteres = {'z', 'b', 'a', 'm', 'c'};

    printf("Caracteres antes: ");
    for (char c : caracteres) {
        printf("%c ", c);
    }

    bubbleSort(caracteres);

    printf("\nCaracteres despues: ");
    for (char c : caracteres) {
        printf("%c ", c);
    }

    printf("\n\n");

    vector<EstudiantePOO> alumnos = {
        EstudiantePOO(1, "Carlos", 8.0f),
        EstudiantePOO(2, "Ana", 9.5f),
        EstudiantePOO(3, "Luis", 7.0f)
    };

    printf("Alumnos antes de ordenar:\n");
    for (const auto& alumno : alumnos) {
        alumno.mostrar();
    }

    bubbleSort(alumnos);

    printf("\nAlumnos ordenados por promedio:\n");
    for (const auto& alumno : alumnos) {
        alumno.mostrar();
    }

    return 0;
}
