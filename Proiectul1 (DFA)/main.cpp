#include "DFA.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

    if (argc != 3) {
        cout << "Comanda gresita\n";
        return -1;
    }

    string nume = argv[argc-2];
    int x = verif_DFA(nume);

    switch(x){
        case 0:
            cout << "Automat Validat\n";
            break;
        case 1:
            cout << "Bad filename '"<< argv[argc-2] << "'\n";
            break;
        case 2:
            cout << "Nu s-a gasit / introdus corect linia Sigma.\n";
            break;
        case 3:
            cout << "Nu s-a gasit / introdus corect linia States.\n";
            break;
        case 4:
            cout << "Nu s-a gasit / introdus corect linia Transitions.\n";
            break;
        case 5:
            cout << "Linie invalida in fisier.\n";
            break;
        case 6:
            cout << "Sectiunea Transitions nu contine END\n";
            break;
        case 7:
            cout << "Sectiunea States nu contine END.\n";
            break;
        case 8:
            cout << "Introduceti States si Sigma inainte de Transitions.\n";
            break;
        case 9:
            cout << "Date incorecte / automat definit gresit.\n";
            break;
        case 10:
            cout << "Sectiunea Sigma nu contine END.\n";
            break;
    }

    if(x==0) {
        string c = argv[argc-1];
        unsigned long long stare = start_state;

        for (char &j: c) {
            bool ok = false;
            string cuv;
            cuv = j;
            for (int i = 0; i < states.size(); ++i) {
                if (matrix[stare][i].find(j) != string::npos) {
                    stare = i;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "Cuvant invalid.\n";
                return 0;
            }
        }

        for (auto &ix: final_states) {
            if (stare == ix) {
                cout << "Cuvant valid.\n";
                return 0;
            }
        }
        cout << "Cuvant invalid.\n";
    }
    return 0;
}