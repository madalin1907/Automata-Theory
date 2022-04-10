#ifndef NFA_LIBRARY_H
#define NFA_LIBRARY_H
#include<bits/stdc++.h>
using namespace std;

vector <char> alf;
vector <pair<unsigned int, string>> states;
long long start_state = -1;
vector <unsigned int> final_states;
bool finish_section, ok_function;
vector <vector<string>> matrix;
int section[3];


void citire_alfabet(ifstream &fin);
void completare(const string &state);
void citire_states(ifstream &fin);
void citire_function(ifstream &fin);
bool Check_End(string rand);
bool verifica();


bool Check_exista_altelitere(string rand){
    bool ok1 = true;
    for (unsigned long long i = 0; i < rand.find('#') and rand[i] != '#'; ++i)
        if (rand[i] != ' ') {
            ok1 = false;
            break;
        }
    return ok1;
}


int verif_NFA(const string& nume){
    ifstream fin(nume);

    if (!fin)
        return 1;

    for (string line; getline(fin, line); ){

        if (line.find('#') != string::npos and Check_exista_altelitere(line))
            continue;
        else {
            transform(line.begin(), line.end(), line.begin(), ::toupper);
            if (line.find("SIGMA") != string::npos) {
                finish_section = false;
                section[0] = 1;
                citire_alfabet(fin);
                if(!finish_section)
                    return 10;
                continue;
            }
            else {
                if (line.find("STATES") != string::npos) {
                    finish_section = false;
                    section[1] = 1;
                    citire_states(fin);
                    if(!finish_section)
                        return 7;
                    continue;
                } else {
                    if (line.find("TRANSITIONS") != string::npos){
                        section[2] = 1;
                        if(!section[0] or !section[1])
                            return 8;
                        else {
                            finish_section = false;
                            unsigned long long n = states.size();
                            matrix.resize(n, vector<string>(n, ""));
                            citire_function(fin);
                            if(!finish_section)
                                return 6;
                            continue;
                        }
                    }
                    else
                        return 5;
                }
            }
        }
    }
    for(int i = 0; i <= 2; ++i)
        if(section[i] == 0)
            return i+2;
    if(!verifica())
        return 9;
    return 0;
}


// verifica daca suntem la final de sectiune
bool Check_End(string rand)
{
    transform(rand.begin(), rand.end(), rand.begin(), ::toupper);
    if(rand.find('#') != string::npos)
        rand = rand.substr(0,rand.find('#'));
    if(rand.find("END") != string::npos)
        return true;
    return false;
}
bool Check_other_section(string rand)
{
    transform(rand.begin(), rand.end(), rand.begin(), ::toupper);
    if(rand.find("STATES") != string::npos or rand.find("TRANSITIONS") != string::npos or rand.find("SIGMA") != string::npos)
        return true;
    return false;
}



// citeste alfabeul
void citire_alfabet(ifstream &fin)
{
    string cuvant;
    set <char> alfab;
    bool ok = false, ok_end = false;
    while(getline(fin,cuvant) and !Check_End(cuvant) and !Check_other_section(cuvant)) {
        if (cuvant.find('#') != string::npos or cuvant.empty()) {
            bool ok1 = true;
            for (unsigned long long i = 0; i < cuvant.find('#') and cuvant[i] != '#'; ++i)
                if (cuvant[i] != ' ') {
                    ok1 = false;
                    break;
                }
            if (ok1 or cuvant.empty())
                continue;
            else {
                if (cuvant.find('#') != string::npos)
                    cuvant = cuvant.substr(0, cuvant.find('#'));
                for (auto &x: alfab)
                    if (x == cuvant[0] and cuvant[0] != ' ')
                        ok = true;
                int count = 0;
                for(char i : cuvant)
                    if(i != ' ')
                        count ++;
                if (count == 1) {
                    for(char &i : cuvant)
                        if (i != ' ') {
                            alfab.insert(i);
                            break;
                        }
                }
                else {
                    cout << "Linie invalida in alfabet.\n";
                    exit(-1);
                }
            }
        }
        else {
            for (auto &x: alfab)
                if (x == cuvant[0] and cuvant[0] != ' ')
                    ok = true;
            int count = 0;
            for(char i : cuvant)
                if(i != ' ')
                    count ++;
            if (count == 1) {
                for(char &i : cuvant)
                    if (i != ' ') {
                        alfab.insert(i);
                        break;
                    }
            }
            else {
                cout << "Linie invalida in alfabet.\n";
                exit(-1);
            }
        }
    }
    if(Check_End(cuvant))
        ok_end = true;

    if(!alfab.empty() and ok_end)
    {
        for(auto &x: alfab)
            alf.emplace_back(x);
        finish_section = true;
        if(ok)
            cout << "Alfabetul nu este corect definit deoarece se repeta cuvintele. A fost corectat.\n";
    }
    else
    if(alfab.empty()) {
        cout << "Alfabetul este gol";
        exit(-1);
    }
}



// completeaza cu valori corespunzatoate vectorul de states
void completare(const string &state)
{
    if(state.find(',') != string::npos)
    {
        unsigned long long pos = state.find(',');
        string name, is_S_or_F;
        name = state.substr(0,pos);
        is_S_or_F = state.substr(pos+1);

        if(is_S_or_F.find('#') != string::npos)
            is_S_or_F = is_S_or_F.substr(0,is_S_or_F.find('#'));
        states.emplace_back(states.size(),name);
        transform(is_S_or_F.begin(), is_S_or_F.end(),is_S_or_F.begin(), ::toupper);
        if(is_S_or_F.find('S') != string::npos and start_state == -1)
            start_state = (long long)(states.size() - 1);

        else {
            if (!Check_exista_altelitere(is_S_or_F))
                if (is_S_or_F.find('S') != string::npos and start_state != -1) {
                    cout << "Eroare! Automatul are mai multe stari initiale.\n";
                    exit(-1);
                }
        }
        if(is_S_or_F.find('F') != string::npos)
            final_states.emplace_back(states.size() - 1);
    }

    else {
        if(state.find('#') != string::npos){
            unsigned long long poz1, poz2;
            poz1 = state.find(' ');
            poz2 = state.find('#');
            string stare = state.substr(0,min(poz1, poz2));
            states.emplace_back(states.size(),stare);
        }
        else{
            states.emplace_back(states.size(),state);
        }
    }
}



//citeste starile date
void citire_states(ifstream &fin)
{
    string state;
    bool ok_end = false;
    while(getline(fin,state) and !Check_End(state) and !Check_other_section(state) ) {
        if (state.find('#') != string::npos or state.empty()) {
            bool ok = true;
            for (unsigned long long i = 0; i < state.find('#') and state[i] != '#'; ++i)
                if (state[i] != ' ') {
                    ok = false;
                    break;
                }
            if (ok or state.empty())
                continue;
            else
                completare(state);
        }
        else
            completare(state);
    }
    if(Check_End(state))
        ok_end = true;
    if(!states.empty() and ok_end)
        finish_section = true;
    if(start_state == -1){
        cout << "Nu s-a introdus nicio stare initiala.\n";
        exit(-1);
    }
    if(final_states.empty()){
        cout << "Nu s-a introdus nicio stare finala.\n";
        exit(-1);
    }
}



void comp_function(const string &row)
{
    if(row.find(',') != string::npos)
    {
        unsigned long long pos = row.find(',');
        string state1, value,v_state2, state2;
        state1 = row.substr(0,pos);
        string intermediar = row.substr(pos+1);
        if(intermediar.find(',') != string::npos){

            unsigned long long pos2 = intermediar.find(',');
            value = intermediar.substr(0, pos2);
            v_state2 = intermediar.substr(pos2 + 1);
            unsigned long long pos3 = v_state2.find(' ');
            unsigned long long pos4 = v_state2.find('#');
            if(pos3 != string::npos and pos4 != string::npos)
                state2 = v_state2.substr(0,min(pos3,pos4));
            else {
                if(pos3 != string::npos)
                    state2 = v_state2.substr(0,pos3);
                else
                    state2 = v_state2.substr(0,pos4);
            }
            for(unsigned long long i = pos3; i < v_state2.size() and v_state2[i] != '#'; ++i)
                if(v_state2[i] != ' '){
                    cout<<"Linie invalida in Transition\n";
                    exit(-1);
                }
            bool ok_val = false;
            unsigned int i = -1, j = -1;
            for(auto &it : states)
            {
                if(it.second == state1)
                {
                    i = it.first;
                    break;
                }
            }
            for(auto &it : states)
            {
                if(it.second == state2)
                {
                    j = it.first;
                    break;
                }
            }
            char valoare = value[0];
            for(auto &x : alf)
                if(x == valoare)
                {
                    ok_val = true;
                    break;
                }
            if((i != -1) and (j != -1) and ok_val)
            {
                matrix[i][j] += value;
                ok_function = true;
            }
            else
            {
                cout<<"Eroare! Functie gresita (Stare / valoare inexistenta).\n";
                exit(-1);
            }
        }
        else
        {
            cout<<"Eroare! Functie incorecta.\n";
            exit(-1);
        }
    }
    else
    {
        cout<<"Eroare! Functie incorecta.\n";
        exit(-1);
    }
}



void citire_function(ifstream &fin)
{
    string function;
    ok_function = false;
    bool ok_end = false;
    while(getline(fin,function) and !Check_End(function)){
        if (function.find('#') != string::npos or function.empty()){
            bool ok = true;
            for(unsigned long long i = 0; i < function.find('#') and function[i] != '#'; ++i)
                if(function[i] != ' '){
                    ok = false;
                    break;
                }
            if(ok or function.empty())
                continue;
            else
                comp_function(function);
        }
        else
            comp_function(function);
    }
    if(Check_End(function))
        ok_end = true;
    if(ok_function and ok_end)
        finish_section = true;
}



//verifica daca functia e ok
bool verifica()
{
    for(auto &x:final_states)
    {
        bool ok = false;
        for(int i = 0; i < states.size(); ++i)
            if(((i != x) and (!matrix[i][x].empty())) or i == start_state){
                ok = true;
                break;
            }
        if(!ok)
            return false;
    }
    return true;
}


#endif //NFA_LIBRARY_H