#include <iostream>
#include <iomanip>
#include<locale.h>
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

	
	
	void pedirDatosPersona(Persona &p) {
	    cout << "Ingrese el nombre: ";
	    
	    cin.getline(p.nombre, 20);
	    cout << "Ingrese la edad: ";
	    cin >> p.edad;
	    cout << "Ingrese el peso: ";
	    cin >> p.peso;
	    cout << "Ingrese la fecha de nacimiento (dia mes anio): ";
	    cin >> p.fechaNacimiento.dia >> p.fechaNacimiento.mes >> p.fechaNacimiento.anio;
	}

	void pedirDatosEmpleado(Empleado &e) {
	    pedirDatosPersona(e.persona);
	    cout << "Ingrese el salario: ";
	    cin >> e.salario;
	    cout << "Ingrese la fecha de contratación (dia mes anio): ";
	    cin >> e.fechaContratacion.dia >> e.fechaContratacion.mes >> e.fechaContratacion.anio;
	}

	void mostrarPersona(Persona& p){
		cout<<"\nNombre: "<<p.nombre<<endl;
		cout<<"Edad:  "<<p.edad<<endl;
		cout<<"Peso: "<<p.peso<<endl;
		cout<<"Fecha de Nacimiento:"<<p.fechaNacimiento.dia<<"-"<<p.fechaNacimiento.mes<<"-"<<p.fechaNacimiento.anio<<endl;	
		
	}

	void mostrarEmpleado(Empleado& e) {
	    mostrarPersona(e.persona);
	    cout << "Salario: $" << fixed << setprecision(2) << e.salario << endl;
	    cout << "Fecha de contratación: " << e.fechaContratacion.dia << "/"
	         << e.fechaContratacion.mes << "/" << e.fechaContratacion.anio << endl;
	}
		

int main(int argc, char** argv) {
	setlocale(LC_ALL,"Spanish");
	//Pedir en el main, los datos de la persona y precargar a Verónica
	Persona p1={"Veronica",20,45,{2,12,1997}};
	Persona p2,p4;
	pedirDatosPersona(p2);
	
	//Desde el main creamos a Esteban,nos ocuparemos de mostrar tanto a Esteban como a Verónica
	Persona p3={"Esteban",19,60,{22,06,1998}};
	cout<<"Mostrar personas cargadas"<<endl;
	mostrarPersona(p1);
	mostrarPersona(p2);//persona cargada por teclado
	mostrarPersona(p3);
	
	
	//Declarar un arreglo de trabajadores,
	// y cargar a Esteban y dos trabajadores adicionales, luego mostrar todos sus campos

	Empleado esteban={p3, 351667.19,{12,12,2022}};
	Empleado veronica={p1, 651007.19,{10,10,2020}};	
	Empleado persona3={p2, 391307.19,{01,12,2021}};//persona cargada por teclado
	
	int cantidadTrabajadores=3;
	Empleado trabajadores[cantidadTrabajadores]={esteban,veronica,persona3};
	
		cout<<"\nMostrar empleados cargados en el arreglo"<<endl;
		
		for(int i=0; i<cantidadTrabajadores;i++){
		cout << "Trabajador " << i + 1 << ":" << endl;	
		mostrarEmpleado(trabajadores[i]);
			cout << endl;
		}
		
	

	return 0;
}
