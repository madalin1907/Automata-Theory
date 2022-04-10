#include "NFA.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[]){

    if (argc != 2) {
        cout << "Comanda gresita\n";
        return -1;
    }

    string nume = argv[argc-1];
    int x = verif_NFA(nume);
    switch(x){
        case 0:
            cout << "Automat Validat\n";
            break;
        case 1:
            cout << "Numele fisierului de intrare este gresit - '" << argv[argc-1] << "'\n";
            break;
        case 2:
            cout << "Nu s-a gasit/introdus corect linia Sigma.\n";
            break;
        case 3:
            cout << "Nu s-a gasit/introdus corect linia States.\n";
            break;
        case 4:
            cout << "Nu s-a gasit/introdus corect linia Transitions.\n";
            break;
        case 5:
            cout << "Linie invalida in fisier.\n";
            break;
        case 6:
            cout << "Sectiunea transition nu contine end.\n";
            break;
        case 7:
            cout << "Sectiunea States nu contine end.\n";
            break;
        case 8:
            cout << "Introduceti States si Sigma inainte de Transitions.\n";
            break;
        case 9:
            cout << "Date incorecte/automat definit gresit.\n";
            break;
        case 10:
            cout << "Sectiunea Sigma nu contine end.\n";
            break;
        default:
            cout << "Eroare.\n";
            break;
    }

    return 0;
}