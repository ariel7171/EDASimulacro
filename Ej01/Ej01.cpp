/*
EJERCICIO 1: Una fila de hormigas africanas, esta recolectando hojas para la supervivencia de la colonia. Las 
mismas se mueven en un sendero marcado por rastros químicos olorosos que marcan un camino y que todas 
ellas siguen para llegar, por ejemplo, a una fuente de alimento. Por tanto, una hormiga no puede adelantar a 
otra que se ha formado mas adelante.
Realice la struct Hormiga que puede ser de uno de 3 tipos: 
Guarda tipo, tamaño, y si recolectó o no una hoja (V/F)
Vamos a crear el senderoA, la FILA de todas las hormigas que tienen rumbo a sus tareas. 
Todas las hormigas recolectoras, y que ademas tengan hojas, se insertan al senderoB(FILA), de lo contrario si no llevan hoja van a 
la FILA senderoC. Luego de que depositan la hoja salen del senderoB(suprimir), y regresan al senderoA principal, seteando 
previamente la hoja en false. 
Hacer un menu de opciones, usando do-while y switch para: 
1. Crear hormigas 
2. Cargar Hormiga a sendero A
3. Derivar a sendero B o C
4. Quitar hoja, Regresar de sendero B a A
5. Mostrar y Vaciar sendero C.
*/

#include <iostream>
using namespace std;

const int MAX=5;

struct Hormiga{
	string tipo;
	string tamanio;
	bool recolecto;
};

struct Fila{
  private: 
	Hormiga fila[MAX];  // struct de enteros
    int p=0;
    int u=-1;
    int cant=0;
    
  public:
	bool filaVacia (){  //EMPTY
		return cant==0;
	}
	bool filaLlena (){   //FULL
		return cant==MAX;
	}
	void Enfilar(Hormiga elem){  //ENQUEUE
		if (!filaLlena()){
		  u = (u+1)%MAX;
		  fila[u]=elem;
		  cant++;
		}else 
			cout<<"No se puede enfilar"<<endl;
	}
	void Desenfilar(){   //DEQUEUE
		if (!filaVacia()){
	     	p=(p+1)%MAX;
		    cant--;
		}else	
			cout<<"No se puede eliminar";
	}
	Hormiga verPrimero (){   // FRONT
		return fila[p];
	}
	Hormiga verUltimo (){    // BACK
		return fila[u];
	}  
	int getCantidad(){ 
	    return cant;
	}
	
	void mostrarFila(){
		for(int i=0;i<MAX;i++){
			cout<<fila[i].tipo<<fila[i].recolecto<<endl;
		}
	}
};

void cargarHormigas(Fila &fila){
	
	Hormiga hormiga;
	hormiga.tipo = "null";
	int opc;
	do{
		
	cout<<"Ingrese el tipo de hormiga"<<endl;
	cout<<"1. Recolectora"<<endl;
	cout<<"2. Excavadora"<<endl;
	cout<<"3. Criadora"<<endl;
	cin>>opc;
	switch(opc){
		case 1:
			hormiga.tipo="recolectora";
			break;
		case 2:
			hormiga.tipo="excavadora";
			hormiga.recolecto=0;
			break;	
		case 3:
			hormiga.tipo="criadora";
			hormiga.recolecto=0;
			break;
		default:
			cout<<"Opcion incorrecta"<<endl;
			return;	
		}
	}while(hormiga.tipo=="null");
	cout<<"Ingrese el tamaño"<<endl;
	cin>>hormiga.tamanio;
	cin.ignore();
	
	if (hormiga.tipo=="recolectora"){
		cout<<"Ha recolectado una hoja? (Si:1, No:0)"<<endl;
		cin>>hormiga.recolecto;	
	}

	cout<<hormiga.tipo<<" "<<hormiga.tamanio<<" "<<hormiga.recolecto<<endl;
		
	fila.Enfilar(hormiga);
	cout<<"Hormiga agregada a fila general"<<endl;	
}

void vaciarSendero(Fila &sendero){
	//cout<<sendero<<endl;

	while(!sendero.filaVacia()){
		
		cout<<"Tipo: "<<sendero.verPrimero().tipo<<", Tiene hoja: " << (sendero.verPrimero().recolecto == 1 ? "Si" : "No")	<<endl;		
		sendero.Desenfilar();
	}
}

int main(){
	
	Fila senderoA, senderoB, senderoC, filaGeneral;
	
	int opcion;
	
	do{
		cout<<"Elija una opcion:"<<endl;
		cout<<"1. Crear hormigas."<<endl;
		cout<<"2. Cargar Hormiga a sendero A."<<endl;
		cout<<"3. Derivar a sendero B o C"<<endl;
		cout<<"4. Quitar hoja, Regresar de sendero B a A."<<endl;
		cout<<"5. Mostrar y Vaciar sendero C ."<<endl;
		cout<<"6. Salir."<<endl;
		cout<<"7. Mostrar filas."<<endl;
		
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cargarHormigas(filaGeneral);
				break;
			case 2:
				if (!filaGeneral.filaVacia()){
					senderoA.Enfilar(filaGeneral.verPrimero());
					filaGeneral.Desenfilar();
					cout<<"Hormiga agregada a sendero A"<<endl;
				}else{
					cout<<"No hay hormigas para cargar en el sendero A"<<endl;
				}
				break;
			case 3:
				if (!senderoA.filaVacia()){
					if(senderoA.verPrimero().recolecto && senderoA.verPrimero().tipo=="recolectora"){
						senderoB.Enfilar(senderoA.verPrimero());
						senderoA.Desenfilar();
						cout<<"Hormiga agregada a sendero B"<<endl;
					}else{
						cout<<"Hormiga agregada a sendero C"<<endl;
						senderoC.Enfilar(senderoA.verPrimero());
						senderoA.Desenfilar();
					}
				}else{
					cout<<"No hay hormigas para cargar en el sendero B o C"<<endl;
				}
				break;	
			case 4:
				if (!senderoB.filaVacia()){
					Hormiga hormiga = senderoB.verPrimero();
					senderoB.Desenfilar();
					hormiga.recolecto=false;
					//senderoB.verPrimero().recolecto=0;
					senderoA.Enfilar(hormiga);
					cout<<"La hormiga del sendero B se enfilo al sendero A sin la hoja"<<endl;
					
				}else{
					cout<<"No hay hormigas en el sendero B"<<endl;
				}
				break;
			case 5:
				vaciarSendero(senderoC);
				break;
			case 6:
				return 0;
				break;
			case 7:
				cout<<"Sendero A"<<endl;
				senderoA.mostrarFila();
				cout<<"\nSendero B"<<endl;
				senderoB.mostrarFila();
				cout<<"\nSendero C"<<endl;
				senderoC.mostrarFila();
				break;		
			default:
				cout<<"Opcion incorrecto"<<endl;
		}
				
	}while(true);

	return 0;	
}
