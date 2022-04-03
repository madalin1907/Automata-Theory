#include "NFA.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[]){

    if (argc != 3) {
        cout << "Comanda gresita\n";
        return -1;
    }

    string nume = argv[argc-2];
    int x = verif_NFA(nume);
    switch(x){
        case 0:
            cout << "Automat Validat\n";
            break;
        case 1:
            cout << "Numele fisierului de intrare este gresit - '" << argv[argc-2] << "'\n";
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
            cout << "Sectiunea states nu contine end.\n";
            break;
        case 8:
            cout << "Introduceti States si Sigma inainte de Transitions.\n";
            break;
        case 9:
            cout << "Date incorecte/automat definit gresit.\n";
            break;
        case 10:
            cout << "Sectiunea sigma nu contine end.\n";
            break;
        default:
            cout << "Eroare.\n";
            break;
    }
    if(x==0) {
        string c = argv[argc - 1];
        unsigned long long int stare = start_state;
        queue <vector <unsigned long long> > drumuri;
        unsigned long long k = c.size();
        drumuri.push({stare});
        while(!drumuri.empty() and !c.empty()){
            vector <unsigned long long> drum;
            char j = c[0];
            c = c.substr(1,c.size());
            while(drumuri.front().size() ==  k - c.size()) {
                drum = drumuri.front();
                unsigned long long n = drum[drum.size()-1];
                for (unsigned long long i = 0; i < states.size(); ++i)
                    if (matrix[n][i].find(j) != string::npos) {
                        drum.push_back(i);
                        drumuri.push(drum);
                        drum.pop_back();
                    }
                drumuri.pop();
            }
        }
        if(drumuri.empty()){
            cout << "Cuvant invalid\n";
            return 0;
        }
        while(!drumuri.empty()){
            vector <unsigned long long> drum;
            drum = drumuri.front();
            drumuri.pop();
            for(auto &ti: final_states)
                if(drum[drum.size() - 1] == ti) {
                    cout << "Cuvant valid";
                    return 0;
                }
        }
        cout << "Cuvant invalid";
    }
    return 0;
}