#include<iostream>
#include <queue>
#include <sstream>
#include <string.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>    // std::min

using namespace std;

int main() {
	int flag = 1;
	while(flag){
		int integrantes = 0;
		int libros = 0;
		cin >> integrantes;
		cin >> libros;
		if(integrantes == 0) {
			break;
		}
		int paginas[libros];
		int toRead[integrantes];
		int i = 0;
		int suma = 0;
		int paginas_minimas = 9999999;
		while(i < libros){
			cin >> paginas[i];
			suma+=paginas[i];
			paginas_minimas = min(paginas_minimas, paginas[i]);
			i++;
			
		}

		// int promedio_por_estudiante = suma/integrantes;
		// int promedio_por_libro = suma/libros;

		int limiter = paginas_minimas;
		int min_max = 9999999;
		while(limiter < suma/2) {
			int libro = 0;
			int persona_leyendo = 0;
			int maximo = 0;
			while(libro < libros){
				toRead[persona_leyendo] = 0;
				while((toRead[persona_leyendo]+paginas[libro] <= limiter || persona_leyendo == integrantes-1) && libro < libros) {
					toRead[persona_leyendo]+= paginas[libro];
					libro++;
				}
				if(toRead[persona_leyendo] > maximo) {
					maximo = toRead[persona_leyendo];
				}
				if(maximo > min_max) {
					break;
				}
				persona_leyendo++;
			}
			limiter+=paginas_minimas/integrantes;
			min_max = min(maximo, min_max);
			
		}
		cout << min_max << endl;
		
	}


	

}