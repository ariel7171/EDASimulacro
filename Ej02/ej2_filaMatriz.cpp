#include <iostream>
#include<locale.h>
using namespace std;

const int MAX=5;


struct Auto {
    string modelo;
    string patente;
};

struct TDApeaje{
  private: 
	Auto fila[2][MAX]; //2filas (vias) maximo de autos por cada una
    int p[2]={0,0};// posicion inicio
      int u[2]={-1,-1};//posicion fin
       int cant[2]={0,0};//vehiculos por via
    
  public:
	bool filaVacia (int via){  //EMPTY //pasamos por parametro la via que queremos verificar
		return cant[via]==0;
	}
	bool filaLlena (int via){   //FULL
		return cant[via]==MAX;
	}
	
	void Enfilar(int via,Auto elem){  //ENQUEUE
	
		    if (!filaLlena(via)) {//verificamos  la fila(via) que quiero agregar  el aut
            u[via] = (u[via] + 1) % MAX;//ciclica
            fila[via][u[via]] = elem;
            cant[via]++;
		}else 
			cout<<"No se puede enfilar"<<endl;
	}
	
	
	
	void Desenfilar(int via){   //DEQUEUE
		if (!filaVacia(via)){
	     	p[via] = (p[via] + 1) % MAX;
		    cant[via]--;
		}else	
			cout<<"No se puede eliminar";
	}
	
	
	Auto verPrimero (int via){   // FRONT
	     return fila[via][p[via]];
	}
	
	Auto verUltimo (int via){    // BACK
	  return fila[via][u[via]];
	} 
	 
	int getCantidad(int via){ 
	    return cant[via];
	}
	
	void mostrarFila(int via){
	  cout << "\n En la vía " << via << ":\n";
        for (int i = 0; i < cant[via]; i++) {
            int idx = (p[via] + i) % MAX;
            cout << "Modelo: " << fila[via][idx].modelo
                 << ", Patente: " << fila[via][idx].patente << endl;
			
		}
	}
};


int main(){
	setlocale(LC_ALL,"Spanish");
	Auto auto1 = {"Toyota Corolla", "ABC123"};
	Auto auto2 = {"VENTO", "ABC456"};
	 Auto auto3= {"FOX", "AS 459 GT"};
	 
	Auto auto4={"C4", "AB 123 CD"};
	Auto auto5={"CRONOS", "FG 567 HI"};
	
	TDApeaje via;
	
	via.Enfilar(0,auto1);//via comun via 0
	via.Enfilar(0,auto2);
	via.Enfilar(0,auto3);
	via.Enfilar(0,auto4);
	
	via.Enfilar(1,auto5);//via rapida via1
		via.Enfilar(1,auto3);
	
	
	cout<<" Vehiculos actuales en la via"<<endl;

	via.mostrarFila(0);
	via.mostrarFila(1);
	
	
	via.Desenfilar(0);
	via.Desenfilar(1);
	
	
	cout<<" \n Vehiculos actuales en la via luego de desencolar"<<endl;

	via.mostrarFila(0);
	via.mostrarFila(1);
	
	
	
	return 0;
}
