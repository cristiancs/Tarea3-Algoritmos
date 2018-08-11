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
		// Verificar si termino la entrada
		if(integrantes == 0) {
			break;
		}
		int paginas[libros];
		int toRead[integrantes];
		int i = 0;
		int suma = 0;
		int paginas_minimas = numeric_limits<int>::max();

		// Leemos todas las paginas y las metemos en un arreglo
		while(i < libros){
			cin >> paginas[i];
			suma+=paginas[i];
			paginas_minimas = min(paginas_minimas, paginas[i]);
			i++;
			
		}

		int limiter = paginas_minimas;
		int min_max = numeric_limits<int>::max();
		while(limiter < suma/2) {
			int libro = 0;
			int persona_leyendo = 0;
			int maximo = 0;
			int acumulado_leido = 0;
			// Este loop se encarga de asignar los libros que lee cada persona
			while(libro < libros){
				toRead[persona_leyendo] = 0;
				// Asignamos libros a cada uno hasta llegar al limite o si es la última persona, todos los que le quedan.
				while((toRead[persona_leyendo]+paginas[libro] <= limiter || persona_leyendo == integrantes-1) && libro < libros) {
					
					// Si es el último lector, usamos matematicas para asignarle los libros a leer
					int restante = suma-acumulado_leido;
					if(persona_leyendo == integrantes-1) {
						toRead[persona_leyendo] = restante;
						libro = libros;
						break;
					}
					// Si la persona ya ha leido más que el min_max que tenemos cortamos el ciclo
					if(toRead[persona_leyendo] > min_max) {
						libro = libros;
						break;
					}

					acumulado_leido+=paginas[libro];
					toRead[persona_leyendo]+= paginas[libro];
					libro++;
				}
				if(toRead[persona_leyendo] > maximo) {
					maximo = toRead[persona_leyendo];
				}
				if(maximo >= min_max) {
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