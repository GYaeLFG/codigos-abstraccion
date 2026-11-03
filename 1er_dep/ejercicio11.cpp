#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int f, c, c2, i, j, k;
    double A[10][10], B[10][10], K, r;

    cout << "Filas y columnas de A (max 10): ";
    cin >> f >> c;
    if (f < 1 || f > 10 || c < 1 || c > 10) return 1;
    cout << "Matriz A:\n";
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++) cin >> A[i][j];

    cout << "Constante: ";
    cin >> K;
    cout << fixed << setprecision(2) << "\nA * constante:\n";
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) cout << setw(8) << A[i][j] * K;
        cout << "\n";
    }

    cout << "\nColumnas de B (tendra " << c << " filas): ";
    cin >> c2;
    if (c2 < 1 || c2 > 10) return 1;
    cout << "Matriz B:\n";
    for (i = 0; i < c; i++)
        for (j = 0; j < c2; j++) cin >> B[i][j];

    cout << "\nA * B:\n";
    for (i = 0; i < f; i++) {
        for (j = 0; j < c2; j++) {
            for (r = 0, k = 0; k < c; k++) r += A[i][k] * B[k][j];
            cout << setw(8) << r;
        }
        cout << "\n";
    }
    return 0;
}
