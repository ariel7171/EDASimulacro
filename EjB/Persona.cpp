#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[20];
    int edad;
    float peso;
    Fecha fechaNacimiento;
};

struct Empleado {
    Persona persona;
    double salario;
    Fecha fechaContratacion;
};

void mostrarPersona(const Persona& p) {
    cout << "Nombre: " << p.nombre << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Peso: " << p.peso << " kg" << endl;
    cout << "Fecha de nacimiento: " << p.fechaNacimiento.dia << "/" 
         << p.fechaNacimiento.mes << "/" << p.fechaNacimiento.anio << endl;
}

void mostrarEmpleado(const Empleado& e) {
    mostrarPersona(e.persona);
    cout << "Salario: $" << fixed << setprecision(2) << e.salario << endl;
    cout << "Fecha de contratación: " << e.fechaContratacion.dia << "/"
         << e.fechaContratacion.mes << "/" << e.fechaContratacion.anio << endl;
}


void pedirDatosPersona(Persona &p) {
    cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline(p.nombre, 20);
    cout << "Ingrese la edad: ";
    cin >> p.edad;
    cout << "Ingrese el peso: ";
    cin >> p.peso;
    cout << "Ingrese la fecha de nacimiento (dia mes anio): ";
    cin >> p.fechaNacimiento.dia >> p.fechaNacimiento.mes >> p.fechaNacimiento.anio;
    cin.clear();
}

void pedirDatosEmpleado(Empleado &e) {
    pedirDatosPersona(e.persona);
    cout << "Ingrese el salario: ";
    cin >> e.salario;
    cout << "Ingrese la fecha de contratación (dia mes anio): ";
    cin >> e.fechaContratacion.dia >> e.fechaContratacion.mes >> e.fechaContratacion.anio;
}

void mostrarMenu() {
    cout << "Seleccione una opción:" << endl;
    cout << "1. Cargar persona" << endl;
    cout << "2. Cargar empleado" << endl;
    cout << "3. Salir" << endl;
    cout << "Opción: ";
}
int main(int argc, char** argv) {
	Persona persona1;
	Empleado empleado1;
	int opcion;
	
	do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "\nCargar persona:" << endl;
                pedirDatosPersona(persona1);
                cout << "\nDatos de la persona cargada:" << endl;
                mostrarPersona(persona1);
                break;
            case 2:
                cout << "\nCargar empleado:" << endl;
                pedirDatosEmpleado(empleado1);
                cout << "\nDatos del empleado cargado:" << endl;
                mostrarEmpleado(empleado1);
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 3);


	return 0;
}
