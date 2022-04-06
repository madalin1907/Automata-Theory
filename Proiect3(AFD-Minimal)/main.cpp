#include "AFD.h"
#include <iostream>
using namespace std;

int main(){/*int argc, char * argv[]){

    if (argc != 3) {
        cout << "Comanda gresita\n";
        return -1;
    }*/

    string nume = "cu.in";//argv[argc-2];
    int x = verif_AFD(nume);
    switch(x){
        case 0:
            cout<<"AFD valid\n";
            break;
        case 1:
            cout << "Bad filename '";/* << argv[argc-2] << "'\n";*/
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
            cout<<"Eroare\n";
            break;
    }
    if(x==0) {
        vector<vector<int>>mat_afd_min;
        mat_afd_min.resize(states.size());
        for(int i=0;i<mat_afd_min.size();++i){
            mat_afd_min[i].resize(states.size());
            for(int j = 0;j < mat_afd_min[i].size();++j){
                if(((count(final_states.begin(), final_states.end(), i) != 0 and count(final_states.begin(), final_states.end(), j) == 0)or(count(final_states.begin(), final_states.end(), i) == 0 and count(final_states.begin(), final_states.end(), j) != 0))and i > j)
                    mat_afd_min[i][j] = 1;
                else {
                    if (((find(final_states.begin(), final_states.end(), i) != final_states.end() and find(final_states.begin(), final_states.end(), j) != final_states.end())or(find(final_states.begin(), final_states.end(), i) == final_states.end() and find(final_states.begin(), final_states.end(), j) == final_states.end()))and i > j)
                        mat_afd_min[i][j] = 0;
                    else
                        mat_afd_min[i][j] = -1;
                }
            }
        }
        vector<vector<unsigned int>>li_adiacenta;
        li_adiacenta.resize(states.size());
        for(int i=0;i< li_adiacenta.size();++i) {
            li_adiacenta[i].resize(alf.size());
            for (int j = 0; j < li_adiacenta[i].size(); ++j) {
                string litera;
                litera += alf[j];
                for (int k = 0; k < matrix[i].size(); ++k)
                    if (matrix[i][k].find(litera)!=string::npos)
                        li_adiacenta[i][j] = k;
            }
        }
        bool ok = true;
        while(ok){
            ok = false;
            for(int i=0;i<mat_afd_min.size();++i) {
                for (int j = 0; j < i; ++j) {
                        if(mat_afd_min[i][j] == 0 and i > j)
                            for(int k = 0; k < alf.size(); ++k)
                                if(mat_afd_min[li_adiacenta[i][k]][li_adiacenta[j][k]] == 1)
                                    mat_afd_min[i][j] = 1;
                }
            }
        }
        /*
        for(auto & i : mat_afd_min){
            for(auto & j : i)
                if(j == -1)
                    cout<<"x ";
                else
                    cout<<j << " ";
            cout<<"\n";
        }
       */
        vector <char> alf_afd_min;
        alf_afd_min = alf;

        vector<set<unsigned long long>> clase;
        for(int i=0;i<mat_afd_min.size();++i) {
            set<unsigned long long> s;
            s.insert(i);
            for (int j = 0; j < i; ++j)
                if (mat_afd_min[i][j] == 0) {
                    s.insert(j);
                }
            bool okset = false;
            for(auto & k : clase) {
                for (auto &c: s)
                    if (k.find(c) != k.end()) {
                        okset = true;
                        break;
                    }
                if(okset)
                    for(auto &c: s)
                        k.insert(c);
            }
            if(!okset)
                clase.push_back(s);
        }
        /*
        for(auto &xi:clase) {
            for (auto &i: xi)
                cout << i << " ";
            cout<<"\n";
        }*/


        unsigned long long start_state_afd_min = -1;
        vector <unsigned int> final_states_afd;
        vector <pair<unsigned int, string>> states_afd_min;
        vector<pair<pair<string, char>,string>> transition_dfa;
        unsigned long long index = states.size();
        for(auto &k:clase){
            string denumire;
            bool ok_fin = false;
            for(auto &f:k) {
                if(start_state == f and start_state_afd_min == -1)
                    start_state_afd_min = index;
                if(!ok_fin and find(final_states.begin(), final_states.end(), f) != final_states.end()){
                    ok_fin = true;
                    final_states_afd.push_back(index);
                }
                denumire += "q" + to_string(f);
                denumire += "-";
            }
            denumire = denumire.substr(0,denumire.size()-1);
            states_afd_min.emplace_back(index++,denumire);
        }
        for(auto &st:clase){
            for(int g = 0;g < alf.size(); ++g){
                set<unsigned long long> nextst;
                for(auto &i:st)
                    nextst.insert(li_adiacenta[i][g]);

                    for (auto &s: clase)
                        for(auto &k:s) {
                            for (auto &h: nextst)
                                if (k == h) {
                                    nextst = s;
                                    break;
                                }
                        }

                string denumire;
                bool ok_fin = false;
                for(auto &f:st) {
                    if(start_state == f and start_state_afd_min == -1)
                        start_state_afd_min = index;
                    if(!ok_fin and find(final_states.begin(), final_states.end(), f) != final_states.end()){
                        ok_fin = true;
                        final_states_afd.push_back(index);
                    }
                    denumire += "q" + to_string(f);
                    denumire += "-";
                }
                denumire = denumire.substr(0,denumire.size()-1);
                string denumire1;
                for(auto &f:nextst) {
                    if(start_state == f and start_state_afd_min == -1)
                        start_state_afd_min = index;
                    if(!ok_fin and find(final_states.begin(), final_states.end(), f) != final_states.end()){
                        ok_fin = true;
                        final_states_afd.push_back(index);
                    }
                    denumire1 += "q" + to_string(f);
                    denumire1 += "-";
                }
                denumire1 = denumire1.substr(0,denumire1.size()-1);
               transition_dfa.push_back({{denumire,alf[g]},denumire1});
            }

        }


        cout<<"Sigma: \n";
        for (auto &i : alf_afd_min){
            cout<<i<<"\n";
        }
        cout<<"END\n";

        cout<<"States: \n";
        for (auto &i : states_afd_min)
            if(i.first == start_state_afd_min)
                cout<< i.second << ",S\n";
            else {
                bool okst = true;
                for (auto &st:final_states_afd)
                    if(i.first == st) {
                        okst = false;
                        break;
                    }
                if(okst)
                    cout << i.second << "\n";
                else
                    cout<<i.second <<",F\n";
            }
        cout<<"END\n";

        cout<<"Transitions: \n";
        for (auto &i : transition_dfa){
            cout<<i.first.first << "," << i.first.second <<","<<i.second<<"\n";
        }
        cout<<"END\n";
    }
    return 0;
}