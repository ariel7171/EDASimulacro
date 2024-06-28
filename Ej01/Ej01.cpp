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
5. Mostrar y Vaciar sendero C
*/

#include <iostream>
#include <locale.h>
#include <cctype>

using namespace std;

const int MAX = 5;

struct Hormiga {
    string tipo;
    string tamanio;
    bool hoja; // Cambio de nombre: recolecto -> hoja
};

struct Sendero {
private:
    Hormiga fila[MAX];
    int p = 0;
    int u = -1;
    int cant = 0;

public:
    bool filaVacia() {
        return cant == 0;
    }

    bool filaLlena() {
        return cant == MAX;
    }

    void Enfilar(Hormiga elem) {
        if (!filaLlena()) {
            u = (u + 1) % MAX;
            fila[u] = elem;
            cant++;
        } else {
            cout << "No se puede enfilar" << endl;
        }
    }

    void Desenfilar() {
        if (!filaVacia()) {
            p = (p + 1) % MAX;
            cant--;
        } else {
            cout << "No se puede eliminar" << endl;
        }
    }

    Hormiga verPrimero() {
        return fila[p];
    }

    Hormiga verUltimo() {
        return fila[u];
    }

    int getCantidad() {
        return cant;
    }

    /*void mostrarFila() {
        for (int i = 0; i < MAX; i++) {
            cout << fila[i].tipo << " " << (fila[i].hoja ? "Si" : "No") << endl;
        }
    }*/
};

void mostrarHormiga(Hormiga hormiga){
	cout << "\nHormiga Tipo: " << hormiga.tipo << ", Tiene hoja: " << (hormiga.hoja ? "Si" : "No") << endl;
}

void cargarHormigas(Sendero& sendero) {
    Hormiga hormiga;
    hormiga.hoja = false;
    char opc;
    
    do {
        cout << "\nIngrese el tipo de hormiga:" << endl;
        cout << "\na. Recolectora" << endl;
        cout << "b. Excavadora" << endl;
        cout << "c. Criadora" << endl;
        cin >> opc;
        opc = tolower(opc);
        
        switch (opc) {
        case 'a':
            hormiga.tipo = "recolectora";
            
            do{
            cout << "\n¿Ha recolectado una hoja? (s/n)" << endl;      
        	cin >> opc;
        	opc = tolower(opc);
            switch(opc){
            	case 's':
            		hormiga.hoja = true;
            		cout << "\nLa hormiga tiene una hoja" << endl; 
            		break;
            	case 'n':
					cout << "\nLa hormiga no tiene una hoja" << endl;
					break;
				default:
					cout << "\nOpcion incorrecta" << endl;
			}
			}while(opc!='s' && opc!='n');
            break;
        case 'b':
            hormiga.tipo = "excavadora";
            //hormiga.hoja = false;
            break;
        case 'c':
            hormiga.tipo = "criadora";
            //hormiga.hoja = false;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
        }
    } while (hormiga.tipo.empty());

	cout << "\nHa seleccionado una hormiga de tipo " << hormiga.tipo << endl;

	do{
    cout << "\nSeleccione el tamaño de la hormiga:" << endl;
    cout << "\na. Chica" << endl;
    cout << "b. Mediana" << endl;
    cout << "c. Grande" << endl;

    cin >> opc;
    opc = tolower(opc);

    switch (opc) {
        case 'a':
            hormiga.tamanio = "chica";
            break;
        case 'b':
            hormiga.tamanio = "mediana";
            break;
        case 'c':
            hormiga.tamanio = "grande";
            break;
        default:
            cout << "\nOpción no válida." << endl;
            break;
    }
	} while (hormiga.tamanio.empty());
	
	cout << "\nHa seleccionado una hormiga " << hormiga.tamanio << endl;
	
    mostrarHormiga(hormiga);
    
    sendero.Enfilar(hormiga);
    cout << "\nHormiga agregada al sendero general" << endl;
}

void vaciarSendero(Sendero sendero) {
    while (!sendero.filaVacia()) {
        mostrarHormiga(sendero.verPrimero());
        sendero.Desenfilar();
    }
}

int main() {

    setlocale(LC_ALL, "Spanish");

    Sendero senderoA, senderoB, senderoC, senderoGeneral;
    char opcion;

    do {
        cout << "\nElija una opción:" << endl;
        cout << "a. Crear hormigas." << endl;
        cout << "b. Cargar Hormiga a sendero A." << endl;
        cout << "c. Derivar a sendero B o C." << endl;
        cout << "d. Quitar hoja, Regresar de sendero B a A." << endl;
        cout << "e. Mostrar y Vaciar sendero C." << endl;
        cout << "f. Salir." << endl;
        //cout << "g. Mostrar senderos." << endl;

        cin >> opcion;

        switch (opcion) {
        case 'a':
            cargarHormigas(senderoGeneral);
            break;
        case 'b':
            if (!senderoGeneral.filaVacia()) {
                senderoA.Enfilar(senderoGeneral.verPrimero());
                mostrarHormiga(senderoGeneral.verPrimero());
                senderoGeneral.Desenfilar();
                
                cout << "\nHormiga agregada a sendero A" << endl;
            } else {
                cout << "\nNo hay hormigas para cargar en el sendero A" << endl;
            }
            break;
        case 'c':
            if (!senderoA.filaVacia()) {
                if (senderoA.verPrimero().hoja && senderoA.verPrimero().tipo == "recolectora") {
                    senderoB.Enfilar(senderoA.verPrimero());
                    mostrarHormiga(senderoA.verPrimero());
                    senderoA.Desenfilar();
                    cout << "\nHormiga agregada a sendero B" << endl;
                } else {
                	mostrarHormiga(senderoA.verPrimero());
                    senderoC.Enfilar(senderoA.verPrimero());         
                    cout << "\nHormiga agregada a sendero C" << endl;
                    senderoA.Desenfilar();
                }
            } else {
                cout << "\nNo hay hormigas para cargar en el sendero B o C" << endl;
            }
            break;
        case 'd':
            if (!senderoB.filaVacia()) {
                Hormiga hormiga = senderoB.verPrimero();
                senderoB.Desenfilar();
                hormiga.hoja = false;
                senderoA.Enfilar(hormiga);
                mostrarHormiga(hormiga);
                cout << "\nLa hormiga del sendero B se enfila al sendero A sin la hoja" << endl;
            } else {
                cout << "\nNo hay hormigas en el sendero B" << endl;
            }
            break;
        case 'e':	
        	if(senderoC.filaVacia()){
        		cout << "\nEl sendero C ya esta vacio." << endl;
        		break;
			}
            vaciarSendero(senderoC);
            cout << "\nEl sendero C ha sido vaciado" << endl;
            break;
        case 'f':
            cout << "\nSaliendo del programa..." << endl;
            return 0;
        /*case 'g':
            cout << "\nSendero A:" << endl;
            senderoA.mostrarFila();
            cout << "\nSendero B:" << endl;
            senderoB.mostrarFila();
            cout << "\nSendero C:" << endl;
            senderoC.mostrarFila();
            break;*/
        default:
            cout << "\nOpción incorrecta" << endl;
            break;
        }

    } while (true);

    return 0;
}


