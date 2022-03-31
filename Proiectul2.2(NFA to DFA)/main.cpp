#include "NFA.h"
#include <iostream>
using namespace std;

int main(){/*int argc, char * argv[]){

    if (argc != 3) {
        cout << "Comanda gresita\n";
        return -1;
    }*/

    string nume = "cu.in";//argv[argc-2];
    int x = verif_NFA(nume);
    switch(x){
        case 0:
            cout<<"Automat Validat\n";
            break;
        case 1:
            cout << "Bad filename '" ;/*<< argv[argc-2] << "'\n";*/
            break;
        case 2:
            cout << "Nu s-a gasit/introdus corect linia Sigma.\n";
            break;
        case 3:
            cout<<"Nu s-a gasit/introdus corect linia States.\n";
            break;
        case 4:
            cout<<"Nu s-a gasit/introdus corect linia Transitions.\n";
            break;
        case 5:
            cout <<"Linie invalida in fisier.\n";
            break;
        case 6:
            cout<<"Sectiunea transition nu contine end\n";
            break;
        case 7:
            cout<<"Sectiunea states nu contine end\n";
            break;
        case 8:
            cout<<"Introduceti Sates si Sigma inainte de Transitions\n";
            break;
        case 9:
            cout<<"Date incorecte/automat definit gresit\n";
            break;
        case 10:
            cout<<"Sectiunea sigma nu contine end\n";
            break;
    }
    if(x==0) {
        vector<char> alf_dfa;
        vector<pair<unsigned int, string>> states_dfa;
        long long start_state_dfa = start_state;
        vector<unsigned int> final_states_dfa;
        vector<vector<string>> matrix_dfa;
        unsigned long long int stare = start_state;
        queue<vector<unsigned long long>> drumuri;
        vector<pair<vector<unsigned long long>, unsigned long long>> stari_noi;
        drumuri.push({stare});
        unsigned long long k = states.size();
        states_dfa.emplace_back(start_state,states[start_state].second);
        while (!drumuri.empty()) {
            vector<unsigned long long> drum;
            drum = drumuri.front();
            drumuri.pop();
            int n = drum[drum.size() - 1];
            for (long long i = 0; i < alf.size(); ++i) {
                for (long long j = 0; j < states.size(); ++j)
                    if (matrix[n][j].find(alf[0]) != string::npos and i!=j)
                        drum.push_back(j);
            }
            drumuri.push(drum);
            stari_noi.emplace_back(drum, k++);
        }
        vector<pair<unsigned long long, bool>> stari_nec;
        stari_nec.resize(states.size());
        for (auto &i: stari_nec)
            i.second = false;
        for (auto &d: stari_noi)
            for (auto &u: d.first)
                stari_nec[u].second = true;
        for (auto &i: stari_nec)
            if (!i.second)
                states_dfa.emplace_back(i.first,states[i.first].second);
        for (auto &d: stari_noi) {
            string sec;
            for (auto &u: d.first) {
                    sec += states[u].second;
            }
            states_dfa.emplace_back(d.second,sec);
        }
        cout<<"Sigma: \n";
        for (auto &i : alf_dfa){
            cout<<i<<"\n";
        }
        cout<<"END\n";

        cout<<"States: \n";
        for (auto &i : states_dfa){
            cout<<i.second<<"\n";
        }
        cout<<"END\n";

        cout<<"Transitions: \n";

    }
    return 0;
}