#include<iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>


using namespace std;

typedef unordered_map<int, unordered_set<int> > mapa;

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
        int aux_ins = 0;
        int aux_pes = 0;
        
        mapa ady;
        mapa dep;
        unordered_set<int> disponibles;
        // Leer los pesos de cada sarcofago
        for (int i=0; i<n_instrucciones; i++) {
            cin >> aux_ins >> aux_pes;
            pesos[aux_ins] = aux_pes;
            disponibles.insert(aux_ins);
        }

        int i1=0;
        int i2=0;
        
        // Leer las dependencias de cada sarcofago
        for (int i =0; i<n_dependencias; i++) {
            cin >> i1 >> i2;
            // Actualizar disponibles
            disponibles.erase(i2);
            // Meter en listas de adyacencia
            ady[i1].insert(i2);
            dep[i2].insert(i1);
        }
        unordered_set<int> vistos;
        while ( !(ady.empty() && disponibles.empty())) {
            int max = 0;
            int actual = 0;

            // Elergir el de mayor duracion disponible
            for ( unordered_set<int>::iterator it = disponibles.begin(); it != disponibles.end(); ++it ) {
                if (pesos[*it] > max) {
                    actual = *it;
                    max = pesos[*it];
                }
            }
            
            disponibles.erase(actual);
            if (!ady.empty()) {
                if (!ady[actual].empty()) {
                    // Eliminar dependencias del actual
                    for ( unordered_set<int>::iterator it = ady[actual].begin(); it != ady[actual].end(); ++it ) {
                        dep[*it].erase(actual);
                        if (dep[*it].empty()) {
                            disponibles.insert(*it);
                        }
                    }
                }
                // Eliminar de los que faltan por recorrer
                ady.erase(actual);
            }
            
            // Imprimir
            cout << actual << " ";
        }
        cout << endl;
    }
}