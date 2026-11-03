#include <iostream>
#include <cstring>
using namespace std;

char S[16][33], C[5][82];

void sierpinski(int x, int y, int t) {
    if (t == 1) { S[y][x] = '*'; return; }
    sierpinski(x, y, t / 2);
    sierpinski(x - t / 2, y + t / 2, t / 2);
    sierpinski(x + t / 2, y + t / 2, t / 2);
}

void cantor(int x, int largo, int nivel) {
    if (nivel == 5) return;
    memset(&C[nivel][x], '#', largo);
    cantor(x, largo / 3, nivel + 1);
    cantor(x + 2 * largo / 3, largo / 3, nivel + 1);
}

int main() {
    int i;

    memset(S, ' ', sizeof S);
    for (i = 0; i < 16; i++) S[i][32] = '\0';
    sierpinski(15, 0, 16);
    cout << "Triangulo de Sierpinski:\n";
    for (i = 0; i < 16; i++) cout << S[i] << "\n";

    memset(C, ' ', sizeof C);
    for (i = 0; i < 5; i++) C[i][81] = '\0';
    cantor(0, 81, 0);
    cout << "\nPolvo de Cantor:\n";
    for (i = 0; i < 5; i++) cout << C[i] << "\n";
    return 0;
}
