#include <iostream>
#include <vector>
using namespace std;

vector<int> delta(int, char);

int main(int argc, char** argv){
    string w;
    if (argc > 1){
        w = argv[1];
    } else {
        return -1;
    }
    int q0 = 0;
    int F[] = {3};
    vector<int> state;
    state.push_back(q0);
    for (int i = 0; i < w.size(); i++){
        char c = w[i];
        vector<int> nstate;
        for (int x = 0; x < state.size(); x++){
            int s = state[i];
            vector<int> v = delta(s, c);
            for (int y = 0; y < v.size(); y++)
                nstate.push_back(v[y]);
        }
        state = nstate;
        if (state.size() == 0){
            cout << "Rejeitado: Função Indefinida" << endl;
            return 0;
        }
    }
        cout << "Acabou" << endl;
    for (int x = 0; x < state.size(); x++){
                cout <<state[x]<<endl;
    }

    for (int i = 0; i<sizeof(F)/sizeof(int); i++){
        int f = F[i];
        for (int x = 0; x < state.size(); x++){
            if (f == state[x]){
                cout << "Aceito" << endl;
                return 0;
            }
        }
    }
    cout << "Rejeitado" << endl;
    return 0;
}

vector<int> delta(int q, char c){
    vector<int> s;
    switch (q){
        case 0:{
            if (c == 'a'){
                s.push_back(0);
                s.push_back(1);
                break;
            }
            if (c == 'b'){
                s.push_back(0);
                s.push_back(2);
                break;
            }
        }
        case 1:{
            if (c == 'a') {
                s.push_back(3);
                break;
            }
        }
        case 2:{
            if (c == 'b'){
                s.push_back(3);
                break;
            }
        }
        case 3:{
            if (c == 'a' || c == 'b'){
                s.push_back(3);
                break;
            }
        }
    }
    return s;
}
