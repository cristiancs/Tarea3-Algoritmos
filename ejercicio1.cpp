#include<iostream>
#include <algorithm>    // std::max

using namespace std;
bool dieta(int maxCal, int alimentos[], int n) {
	bool flag;
	int i, calorias;
	// Creamos matriz auxiliar
	int aux[n+1][maxCal+1];
	flag = false;
	for (i = 0; i <= n; i++) {
		for (calorias = 0; calorias <= maxCal; calorias++) {
			if( i==0 || calorias==0 )
				aux[i][calorias] = 0;
			else if ( alimentos[i-1] <= calorias )
				aux[i][calorias] = max(alimentos[i-1] + aux[i-1][calorias-alimentos[i-1]],  aux[i-1][calorias]);
			else
				aux[i][calorias] = aux[i-1][calorias];
			if ( aux[i][calorias] == maxCal ){
				flag = true;
				break;
			}
			
		}
		if(flag)
			break;
	}

	return flag;
}

int main() {
	int n, k, id, val, i;
	while(cin >> n >> k){

		int datos[n];

		for (i = 0; i < n; ++i) {
			cin >> id >> val;
			datos[i] = val;
		}

		cout << dieta(k, datos, n) << endl;
	}
	return 0;
}
