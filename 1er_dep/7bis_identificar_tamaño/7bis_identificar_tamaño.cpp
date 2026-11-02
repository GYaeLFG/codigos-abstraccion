#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    double precio;
    int anio;
};

class Persona {
private:
    string nombre, ap, am, genero;
    int edad;
};

int main() {
    cout << "--- Tamanos de tipos de datos basicos ---" << endl;
    cout << "Tamano de char: " << sizeof(char) << " bytes" << endl;
    cout << "Tamano de int: " << sizeof(int) << " bytes" << endl;
    cout << "Tamano de float: " << sizeof(float) << " bytes" << endl;
    cout << "Tamano de double: " << sizeof(double) << " bytes" << endl;
    cout << "Tamano de bool: " << sizeof(bool) << " bytes" << endl;

    cout << "\n--- Tamanos de tipos de datos creados (POO) ---" << endl;
    cout << "Tamano de la clase Auto: " << sizeof(Auto) << " bytes" << endl;
    cout << "Tamano de la clase Persona: " << sizeof(Persona) << " bytes" << endl;

    return 0;
}
