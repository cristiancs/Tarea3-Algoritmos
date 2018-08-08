#include<iostream>
#include <queue>
#include <sstream>
#include <string.h>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	while(true){
		int integrantes = 0;
		int libros = 0;
		cin >> integrantes;
		cin >> libros;

		int paginas[libros];
		int toRead[integrantes];
		int i = 0;
		int suma = 0;
		while(i < libros){
			cin >> paginas[i];
			suma+=paginas[i];
			i++;
			
		}
		int promedio = suma / integrantes;


		i = 0;
		int persona_leyendo = 0;
		while(i < libros){
			toRead[persona_leyendo] = 0;
			while((toRead[persona_leyendo]+paginas[i] <= promedio || persona_leyendo == integrantes-1) && i < libros) {
				
				toRead[persona_leyendo]+= paginas[i];
				i++;
			}

			persona_leyendo++;
		}

		
		
		i = 0;
		int maximo = 0;
		while(i < integrantes){
			if(toRead[i] > maximo) {
				maximo = toRead[i];
			}
			i++;
		}


		i = libros-1;
		persona_leyendo = 0;
		while(i >= 0){
			toRead[persona_leyendo] = 0;
			while((toRead[persona_leyendo]+paginas[i] <= promedio || persona_leyendo == integrantes-1) && i >= 0) {
				
				toRead[persona_leyendo]+= paginas[i];
				
				i--;
			}


			persona_leyendo++;
		}
		i = 0;
		int maximo2 = 0;
		while(i < integrantes){
			if(toRead[i] > maximo2) {
				maximo2 = toRead[i];
			}
			i++;
		}
		int minimo = 0;

		if(maximo2 > maximo) {
			minimo = maximo;
		} else {
			minimo = maximo2;
		}

		cout << minimo << endl;
	}


	

}