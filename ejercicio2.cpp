#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
 

typedef unordered_map<int, int> mapa;

void allSubsetSum(vector<int> pesos, int n_alimentos, int calorias)
{
    // The value of subset[i][j] will be true if there is a 
    // subset of set[0..j-1] with sum equal to i
    bool dp[n_alimentos][calorias+1];
  
    // If sum is 0, then answer is true
    for (int i = 0; i <= n_alimentos; i++) dp[i][0] = true;
  
    // If sum is not 0 and set is empty, then answer is false
    //for (int i = 1; i <= calorias; i++) dp[0][i] = false;
  
     // Fill the dp table in botton up manner
     for (int i = 0; i < n_alimentos; i++) {
       for (int j = 1; j <= calorias; j++) {
		   	if (i == 0) {
				if (j - pesos[i] == 0) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = false;

				}
		   	}
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
  
        // uncomment this code to print table
     for (int i = 0; i < n_alimentos; i++){
       	for (int j = 0; j <= calorias; j++) {
        	printf ("%4d", dp[i][j]);
	   	}
       printf("\n");
     }
  
     //return dp;

	 // Buscar posibles soluciones

	 // No era posible
	 if (dp[n_alimentos-1][calorias] == 0){
		 cout << "0" << endl;
	 }

	// Es posible
	else {
		stack <int> incluidos;
		int sum_actual = calorias;
		int i = n_alimentos-1;
		while (i >= 0) {
			if (dp[i][sum_actual] == 1) {
				incluidos.push(pesos[i]);
				//i = sum_actual-pesos[i];
				i = distance(pesos.begin(), find(pesos.begin(), pesos.end(), pesos[i]));

			}
			else {
				i--;
			}
			if (i==0) {
				// Se llegó al final de la matriz

				// Copiar


				// Seguir con otras soluciones
				if (incluidos.size() == 0) break;
				int peso_actual = incluidos.top();
				sum_actual += peso_actual;
				incluidos.pop();
				i = distance(pesos.begin(), find(pesos.begin(), pesos.end(), peso_actual))-1;
				if (i<0) break;
				continue;
			}
			if (sum_actual == 0) {
				// Se llegó a una solución

				// Copiar

				// Seguir
				int peso_actual = incluidos.top();
				sum_actual += peso_actual;
				incluidos.pop();
				i = distance(pesos.begin(), find(pesos.begin(), pesos.end(), peso_actual))-1;

			}
		}
	}
}

// Driver code
int main()
{	
	int n_alimentos, k_cal_esperadas, id_alim, w_alim, i;
	while(cin >> n_alimentos >> k_cal_esperadas){
		mapa cod_peso;
		vector<int> array_w(n_alimentos);

		for (i = 0; i < n_alimentos; i++) {
			cin >> id_alim >> w_alim;
			array_w[i] = w_alim;
			int w = w_alim;
			int id = id_alim;
			//cod_peso[w].insert(id);
			cod_peso.insert(pair<int, int>(w, id));
		}

		cout << "n_alimentos: " << n_alimentos << "  calorias a sum: "<< k_cal_esperadas<<endl;
		/*for (auto it = cod_peso.begin(); it != cod_peso.end(); ++it) {
			cout << "peso: " << it->first << " || cod: " << it->second<<endl;
		}*/
		sort(array_w.begin(), array_w.end());
		allSubsetSum(array_w, n_alimentos, k_cal_esperadas);
		cout << endl;
	}
    return 0;
}