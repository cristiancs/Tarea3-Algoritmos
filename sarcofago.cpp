#include<iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <map>


using namespace std;

struct nodo {
    int n_sarcofago;
    int tiempo;
};

struct arista {
    struct nodo *sig;
    struct nodo *ant;
};

void addDoubleEdge(vector<arista> ar, nodo * n1, nodo * n2) {

}

int main() {
    int n_instrucciones = 0;
    int n_dependencias = 0;
    
    while (cin >> n_instrucciones >> n_dependencias) {
        map<int, int> pesos;
        //cout << "Ins " << n_instrucciones << " Dep " << n_dependencias << endl;
        int aux_ins = 0;
        int aux_pes = 0;
        for (int i=0; i<n_instrucciones; i++) {
            cin >> aux_ins >> aux_pes;
            pesos[aux_ins] = aux_pes;
            //cout << "Ins: " << aux_ins << " Pes: "<<aux_pes<<endl;
        }

        int i1=0;
        int i2=0;
        for (int i =0; i<n_dependencias; i++) {
            cin >> i1 >> i2;
            //cout << "i1: "<<i1<<" i2: "<<i2<<endl;
        }
       // cout<<endl;
    }
        
}