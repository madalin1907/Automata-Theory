#include "NFA.h"
#include <bits/stdc++.h>
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
            cout<<"Automat Validat\n\n";
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
        default:
            cout<<"Eroare";
            break;
    }
    if(x==0) {
        vector<char> alf_dfa;
        alf_dfa = alf;

        long long start_state_dfa = start_state;
        vector<pair<unsigned int, string>> states_dfa;
        queue<vector<long long>> clase_echiv;
        vector<vector<long long>>viz;
        int adaugat = 1;
        clase_echiv.push({start_state});
        viz.push_back({start_state});
        while(!clase_echiv.empty() and adaugat > 0){
                //  el vedem unde putem ajunge luand literele pe rand
                vector<long long> st_plec;
                st_plec = clase_echiv.front();
                for (auto &lit: alf) {
                    vector<long long> nou_cls;
                    vector<vector<long long>> directii;
                    directii.resize(st_plec.size());
                    int k = 0;
                     for (auto &g: st_plec){
                        for(int j=0;j<states.size();++j)
                            if (matrix[g][j].find(lit) != string::npos)
                                directii[k].push_back(j);
                        k++;
                    }
                     nou_cls = directii[0];
                     for(int j=1;j<k;++j) {
                         vector<long long> v3;
                         std::set_union(nou_cls.begin(), nou_cls.end(),
                                        directii[j].begin(), directii[j].end(),
                                        back_inserter(v3));
                         nou_cls=v3;
                     }
                    if (!nou_cls.empty()) {
                        bool ok = true;
                        for (auto &clas: viz)
                            if (clas == nou_cls)
                                ok = false;
                        if (ok) {
                            clase_echiv.push(nou_cls);
                            viz.push_back(nou_cls);
                            adaugat += 1;
                        }
                    }
                }
                clase_echiv.pop();
                adaugat-=1;
        }
        for(auto&st:viz){
            int index = -1;
            if(st.size() == 1) {
                for (int i = 0; i < states.size(); ++i)
                    if (states[i].first == st[0])
                        index = i;
                if (index != -1)
                    states_dfa.emplace_back(states[index].first, states[index].second);
            }
        }
        unsigned long long index = states.size()+1;
        for(auto&st:viz) {
            if(st.size() > 1){
                string denumire;
                for(auto &f:st) {
                    denumire += states[f].second;
                    denumire += "-";
                }
                denumire = denumire.substr(0,denumire.size()-1);
                states_dfa.emplace_back(index,denumire);
                index++;
            }
        }
        vector<unsigned int> final_states_dfa;
        for(auto &st:states_dfa){
            for(auto &vst:final_states)
                if(st.second.find(states[vst].second) != string::npos)
                    final_states_dfa.push_back(st.first);
        }
        vector<vector<string>> matrix_dfa;
        cout<<"Sigma: \n";
        for (auto &i : alf_dfa){
            cout<<i<<"\n";
        }
        cout<<"END\n";

        cout<<"States: \n";
        for (auto &i : states_dfa)
            if(i.first == start_state_dfa)
                cout<< i.second << ",S\n";
            else {
                bool ok = true;
                for (auto &st:final_states_dfa)
                        if(i.first == st) {
                            ok = false;
                            break;
                        }
                if(ok)
                    cout << i.second << "\n";
                else
                    cout<<i.second <<",F\n";
            }
        cout<<"END\n";

        cout<<"Transitions: \n";

    }
    return 0;
}
