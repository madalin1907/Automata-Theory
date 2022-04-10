#include "NFA.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char * argv[]){

    if (argc != 2) {
        cout << "Comanda gresita\n";
        return -1;
    }

    string nume = argv[argc-1];
    int x = verif_NFA(nume);
    switch(x){
        case 0:
            cout << "Automat Validat\n\n";
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
            cout << "Sectiunea Transition nu contine end.\n";
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
            cout << "Eroare.";
            break;
    }
    if(x==0) {
        vector <char> alf_dfa;
        alf_dfa = alf;

        long long start_state_dfa = start_state;
        vector <pair <unsigned int, string>> states_dfa;
        vector <pair <pair <string, char>, string>> transition_dfa;
        queue <vector<long long>> clase_echiv;
        vector <vector <long long>> viz;
        int adaugat = 1;
        clase_echiv.push({start_state});
        viz.push_back({start_state});
        while(!clase_echiv.empty() and adaugat > 0){
                vector <long long> st_plec;
                st_plec = clase_echiv.front();
                for (auto &lit: alf) {
                    vector <long long> nou_cls;
                    vector <vector<long long>> directii;
                    directii.resize(st_plec.size());
                    int k = 0;
                    for (auto &g: st_plec){
                        for(int j = 0; j < states.size(); ++j)
                            if (matrix[g][j].find(lit) != string::npos)
                                directii[k].push_back(j);
                        k++;
                    }
                    nou_cls = directii[0];
                    for(int j = 1; j < k; ++j) {
                         vector <long long> v3;
                         std::set_union(nou_cls.begin(), nou_cls.end(),
                                        directii[j].begin(), directii[j].end(),
                                        back_inserter(v3));
                         nou_cls=v3;
                    }
                    string denumire;
                    for(auto &f : st_plec) {
                        denumire += "q" + to_string(f);
                        denumire += "-";
                    }
                    denumire = denumire.substr(0,denumire.size()-1);
                    string denumire1;
                    for(auto &f : nou_cls) {
                        denumire1 += "q" + to_string(f);
                        denumire1 += "-";
                    }
                    denumire1 = denumire1.substr(0,denumire1.size()-1);
                    if(!denumire.empty() and !denumire1.empty())
                    transition_dfa.push_back({{denumire,lit},denumire1});
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
                adaugat -= 1;
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
        vector <unsigned int> final_states_dfa;
        for(auto &st : states_dfa){
            for(auto &vst : final_states)
                if(st.second.find(states[vst].second) != string::npos)
                    final_states_dfa.push_back(st.first);
        }



        cout << "Sigma: \n";
        for (auto &i : alf_dfa){
            cout << i <<"\n";
        }
        cout << "END\n";

        cout << "States: \n";
        for (auto &i : states_dfa) {
            cout << i.second;
            if (i.first == start_state_dfa)
                cout << ",S";
            if (find(final_states_dfa.begin(), final_states_dfa.end(), i.first) != final_states_dfa.end())
                cout << ",F";

            cout << "\n";
        }
        cout << "END\n";

        cout<<"Transitions: \n";
        for (auto &i : transition_dfa){
            cout << i.first.first << "," << i.first.second << "," <<i.second << "\n";
        }

        cout << "END\n";
    }
    return 0;
}


