#include <iostream>
#include <cstring>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");
    char opcion;
    char cadenaPrincipal[100], cadenaIngresada1[30], cadenaIngresada2[30], cadenaAux[100], cadenaExamen[30];
    bool flag = false;

    strcpy(cadenaPrincipal, "palabra");

    cout << cadenaPrincipal << endl;

    cout << "Ingrese una cadena: " << endl;
    cin.getline(cadenaIngresada1, 30);

    strcat(cadenaPrincipal, " ");
    strcat(cadenaPrincipal, cadenaIngresada1);

    cout << cadenaPrincipal << endl;

    do {
    	cout << "Elija una opcion:" << endl;
        cout << "a. Determinar el largo de la cadena" << endl;
        cout << "b. Solicitar otra cadena" << endl;
        cout << "c. Solicitar otra letra y verificar si esta en la primera cadena" << endl;
        cout << "d. Cargar en una variable cadena la frase “Examen de EDA” y comparar" << endl;
        cout << "s. Salir" << endl;
        cin >> opcion;

        switch(opcion) {
            case 'a':
                cout << "El largo de la primera cadena mas la primera cadena ingresada es " << strlen(cadenaPrincipal) << endl;
                break;
            case 'b':
                cout << "Ingrese otra cadena: " << endl;
                cin.ignore();
                cin.getline(cadenaIngresada2, 30);
                flag = true;
                if (strstr(cadenaPrincipal, cadenaIngresada2) != nullptr) {
                    cout << "La cadena ingresada es una subcadena de la primera cadena" << endl;
                } else {
                    cout << "La cadena ingresada no es una subcadena de la primera cadena" << endl;
                }
                strcpy(cadenaAux, cadenaPrincipal);
                strcat(cadenaAux, "-");
                strcat(cadenaAux, cadenaIngresada2);

                cout << cadenaAux << endl;

                if (strlen(cadenaPrincipal) > strlen(cadenaIngresada2)) {
                    cout << "La primera cadena es la mas larga" << endl;
                } else if (strlen(cadenaPrincipal) < strlen(cadenaIngresada2)) {
                    cout << "La segunda cadena es la mas larga" << endl;
                } else {
                    cout << "Las dos cadenas son del mismo largo" << endl;
                }
                break;
            case 'c':
                char letra;
                cout << "Ingrese una letra: " << endl;
                cin >> letra;

                if (strchr(cadenaPrincipal, letra) != nullptr) {
                    cout << "La letra esta en la primera cadena" << endl;
                } else {
                    cout << "La letra no esta en la primera cadena" << endl;
                }
                break;
            case 'd':
                if (!flag) {
                    cout << "Primero debe elegir la opcion b" << endl;
                    break;
                }
                strcpy(cadenaExamen, "Examen de EDA");
                if (strcasecmp(cadenaIngresada2, cadenaExamen) == 0) {
                    cout << "La cadena ingresada es igual a la cadena “Examen de EDA”" << endl;
                } else {
                    cout << "La cadena ingresada no es igual a la cadena “Examen de EDA”" << endl;
                }
                break;
            case 's':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    } while (opcion != 's');

    return 0;
}

