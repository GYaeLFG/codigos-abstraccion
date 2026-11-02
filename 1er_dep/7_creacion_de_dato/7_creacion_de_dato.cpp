#include <iostream>
#include <string>
using namespace std;

template <typename T>
void pedir(const string& msg, T& dato) {
    cout << msg;
    cin >> dato;
}

class Auto {
    double precio;
    int anio;
public:
    void ingresarDatos() {
        cout << "--- Datos del Auto ---\n";
        pedir("Ingresa el precio del auto: ", precio);
        pedir("Ingresa el anio del auto: ", anio);
    }
    void mostrar() const {
        cout << "Auto registrado -> Precio: $" << precio << ", Anio: " << anio << '\n';
    }
};

class Persona {
    string nombre, ap, am, genero;
    int edad;
public:
    void ingresarDatos() {
        cout << "\n--- Datos de la Persona ---\n";
        pedir("Ingresa el nombre: ", nombre);
        pedir("Ingresa el apellido paterno: ", ap);
        pedir("Ingresa el apellido materno: ", am);
        pedir("Ingresa el genero: ", genero);
        pedir("Ingresa la edad: ", edad);
    }
    void mostrar() const {
        cout << "Persona registrada -> Nombre: " << nombre << " " << ap << " " << am
             << ", Genero: " << genero << ", Edad: " << edad << '\n';
    }
};

int main() {
    Auto miAuto;
    Persona miPersona;

    miAuto.ingresarDatos();
    miPersona.ingresarDatos();

    cout << "\n--- Mostrando Datos Ingresados ---\n";
    miAuto.mostrar();
    miPersona.mostrar();
}
