#include <iostream>
using namespace std;

unsigned long long factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

int fibonacci(int n) { return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2); }

void calculadora(double a) {
    char op, seguir;
    double b;

    cout << "\nValor actual: " << a << "\nOperacion y numero (ej: + 5): ";
    cin >> op >> b;
    a = op == '+' ? a + b : op == '-' ? a - b : op == '*' ? a * b : b != 0 ? a / b : a;
    cout << "Resultado: " << a << "\nContinuar? (s/n): ";
    cin >> seguir;
    if (seguir == 's') calculadora(a);
}

int main() {
    int n, i;
    double x;

    cout << "Factorial de (0-20): ";
    cin >> n;
    cout << n << "! = " << factorial(n) << "\n";

    cout << "\nTerminos de Fibonacci: ";
    cin >> n;
    for (i = 0; i < n; i++) cout << fibonacci(i) << " ";

    cout << "\n\nCalculadora recursiva. Numero inicial: ";
    cin >> x;
    calculadora(x);
    return 0;
}
