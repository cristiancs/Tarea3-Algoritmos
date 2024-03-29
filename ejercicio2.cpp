#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
 

typedef unordered_map<int, int> mapa;

// Funcion para el sort para ordenar las soluciones
bool wayToSort(vector<int> i, vector<int> j) { 
	// Priorizar mas cortos
	if (i.size() < j.size()) {
		return true;
	}
	else if (i.size() > j.size()) {
		return false;
	}

	// Comparar por elemento
	vector<int>::iterator it2 = j.begin();
	for (vector<int>::iterator it = i.begin(); it != i.end(); it++) {
		if ((*it) < (*it2)) {
			return true;
		}
		else if ((*it) > (*it2)) {
			return false;
		}
		it2++;
	}
	return false;
}

void allSubsetSum(mapa cod_peso, vector<int> pesos, int n_alimentos, int calorias) {
	//
     // Llenado de tabla de programacion dinámica
	//

    bool dp[n_alimentos][calorias+1];
  
    // Primera columna todos 1
    for (int i = 0; i <= n_alimentos; i++) dp[i][0] = true;

	// Llenar de forma acumulada
	// si el j-esimo se podia hacer en la columna anterior o
	// si la diferencia se podia
    for (int i = 0; i < n_alimentos; i++) {
       	for (int j = 1; j <= calorias; j++) {
			// Primera fila
		   	if (i == 0) {
				if (j - pesos[i] == 0) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = false;

				}
		   	}
			// Resto
			else {
				if (j<pesos[i]) {
					dp[i][j] = dp[i-1][j];
				}
				else {
        			dp[i][j] = dp[i-1][j] || dp[i - 1][j-pesos[i]];
				}
			}
       	}
     }

	//
	 // Buscar posibles soluciones
	//
	 // No era posible
	vector<vector<int> > soluciones;
	if (dp[n_alimentos-1][calorias] == 0) {
		cout << "0" << endl;
	}

	// Es posible
	else {
		stack <int> incluidos;
		int sum_actual = calorias;
		int i = n_alimentos-1;
		while (true) {
			// Se llegó a una solución
			if (sum_actual == 0) {
				// Guardar solución
				stack<int> pila_aux;
				vector<int> sol_actual;
				while (!incluidos.empty()) {
					int act = incluidos.top();
					incluidos.pop();
					pila_aux.push(act);
					// Guardar codigo
					sol_actual.insert(sol_actual.begin(), cod_peso[pesos[act]]);
				}
				// Ordenar codigos
				sort(sol_actual.begin(), sol_actual.end());
				// Guardar solucion
				soluciones.insert(soluciones.begin(), sol_actual);
				
				// Volver a estado anterior
				while (!pila_aux.empty()) {
					int act = pila_aux.top();
					pila_aux.pop();
					incluidos.push(act);
				}

				// Seguir
				i = incluidos.top();
				sum_actual += pesos[i];
				incluidos.pop();
				i--;
			}

			// Se acabó la profundidad
			if (i < 0) {
				// Se terminó la búsqueda
				if (incluidos.empty()) {
					break;
				}
				// Continuar en nivel anterior
				i = incluidos.top();
				sum_actual+= pesos[i];
				incluidos.pop();
				i--;
			}

			// Saltar peso que no sirve
			if ((sum_actual-pesos[i]<0) || (dp[i][sum_actual] == 0)) {
				i--;
				continue;
			}
			// Si me sirve, guardar posicion y probar
			incluidos.push(i);
			sum_actual-=pesos[i];
			i--;
		}
	}

	// Ordenar
	sort(soluciones.begin(), soluciones.end(), wayToSort);

	// imprimir
	for (vector<vector<int> >::iterator it = soluciones.begin(); it != soluciones.end(); it++ ) {
		for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++ ) {
			cout << *it2 << " ";
		}
		cout << endl;
	}	
}

int main() {	
	int n_alimentos, k_cal_esperadas, id_alim, w_alim, i;
	// Leer n, k
	while(cin >> n_alimentos >> k_cal_esperadas){
		mapa cod_peso;
		// Arreglo con pesos
		vector<int> array_w(n_alimentos);

		// Leer cada alimento
		for (i = 0; i < n_alimentos; i++) {
			cin >> id_alim >> w_alim;
			array_w[i] = w_alim;
			int w = w_alim;
			int id = id_alim;
			cod_peso.insert(pair<int, int>(w, id));
		}
		// Entregar arreglo ordenado
		sort(array_w.begin(), array_w.end());
		// Buscar subarreglos
		allSubsetSum(cod_peso, array_w, n_alimentos, k_cal_esperadas);
		cout << endl;
	}
    return 0;
}