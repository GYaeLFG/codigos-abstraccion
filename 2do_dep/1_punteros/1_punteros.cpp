#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Nodo {
    T* siguiente = nullptr;
public:
    void setSiguiente(T* s) { siguiente = s; }
    T* getSiguiente() const { return siguiente; }
};

template <typename T>
class Lista {
    T* cabeza = nullptr;
    T* cola = nullptr;
public:
    Lista() = default;
    Lista(const Lista&) = delete;
    Lista& operator=(const Lista&) = delete;

    void agregar(T* nuevo) {
        if (!cabeza) cabeza = cola = nuevo;
        else { cola->setSiguiente(nuevo); cola = nuevo; }
    }
    void mostrar() const {
        for (T* p = cabeza; p; p = p->getSiguiente()) p->mostrar();
    }
    ~Lista() {
        while (cabeza) {
            T* temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
        }
    }
};

class Persona : public Nodo<Persona> {
    string nombre, ap, am;
    char genero;
    int edad;
public:
    Persona(string n, string p, string m, char g, int e)
        : nombre(n), ap(p), am(m), genero(g), edad(e) {}

    void mostrar() const {
        cout << nombre << " " << ap << " " << am
             << " | Genero: " << genero << " | Edad: " << edad << '\n';
    }
};

class Auto : public Nodo<Auto> {
    double precio;
    int anio;
public:
    Auto(double p, int a) : precio(p), anio(a) {}

    void mostrar() const {
        cout << "Anio: " << anio << " | Precio: $" << precio << '\n';
    }
};

int main() {
    Lista<Persona> personas;
    int nPersonas;
    cout << "Cuantas personas desea ingresar? ";
    cin >> nPersonas;

    for (int i = 0; i < nPersonas; i++) {
        string n, p, m;
        char g;
        int e;
        cout << "\nPersona " << i + 1 << "\nNombre: ";
        cin >> n;
        cout << "Apellido Paterno: ";
        cin >> p;
        cout << "Apellido Materno: ";
        cin >> m;
        cout << "Genero (M/F): ";
        cin >> g;
        cout << "Edad: ";
        cin >> e;
        personas.agregar(new Persona(n, p, m, g, e));
    }

    cout << "\n--- Lista de Personas ---\n";
    personas.mostrar();

    Lista<Auto> autos;
    int nAutos;
    cout << "\nCuantos autos desea ingresar? ";
    cin >> nAutos;

    for (int i = 0; i < nAutos; i++) {
        double precio;
        int anio;
        cout << "\nAuto " << i + 1 << "\nAnio: ";
        cin >> anio;
        cout << "Precio: ";
        cin >> precio;
        autos.agregar(new Auto(precio, anio));
    }

    cout << "\n--- Lista de Autos ---\n";
    autos.mostrar();
}
