#include <iostream>
using namespace std;

int delta(int, char);

int main(int argc, char** argv){
    string w;
    if (argc > 1){
        w = argv[1];
    } else {
        return -1;
    }
    int q0 = 0;
    int F[] = {3};
    int state = q0;
    for (int i = 0; i < w.size(); i++){
        char c = w[i];
        state = delta(state, c);
        if (state == -1){
            cout << "Rejeitado: Função Indefinida" << endl;
            return 0;
        }
    }
    for (int i = 0; i<sizeof(F)/sizeof(int); i++){
        if (F[i] == state){
            cout << "Aceito" << endl;
            return 0;
        }
    }
    cout << "Rejeitado" << endl;
    return 0;
}

int delta(int q, char c){
    switch (q){
        case 0:{
            if (c == 'a') return 1;
            if (c == 'b') return 2;
        }
        case 1:{
            if (c == 'a') return 3;
            if (c == 'b') return 2;
        }
        case 2:{
            if (c == 'a') return 1;
            if (c == 'b') return 3;
        }
        case 3:{
            if (c == 'a') return 3;
            if (c == 'b') return 3;
        }
    }
    return -1;
}
