#include<iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>


using namespace std;

// Estructura para guardar el nodo del grafo, con sus adyacencias o dependencias (del grafo dirigido)
typedef unordered_map<int, unordered_set<int> > mapa;

int main() {
    int n_instrucciones = 0;
    int n_dependencias = 0;
    // Leer instrucciones
    while (cin >> n_instrucciones >> n_dependencias) {
        // Estructura para guardar duracion del sarcofago
        map<int, int> pesos;

        int aux_ins = 0;
        int aux_pes = 0;
        
        mapa ady;
        mapa dep;
        // Estructura para guardar a cuales se tiene acceso actualmente
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
        
        // Iterar mientras haya sarcofagos en la lista de adyacencia o bien mientras
        // queden por recorrer todavia en los disponibles
        while ( !(ady.empty() && disponibles.empty())) {
            int max = 0;
            int actual = 0;

            // Elegir el de mayor duracion disponible
            for ( unordered_set<int>::iterator it = disponibles.begin(); it != disponibles.end(); ++it ) {
                if (pesos[*it] > max) {
                    actual = *it;
                    max = pesos[*it];
                }
            }
            
            // Actualizar
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
                // Si al nodo actual no le queda nada por abrir, eliminar
                ady.erase(actual);
            }
            
            // Imprimir
            cout << actual << " ";
        }
        cout << endl << endl;
    }
}