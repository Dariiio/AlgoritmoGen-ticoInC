#include <iostream>
#include <time.h>
#include "poblacion.hpp"


int main(int argc, char const *argv[])
{
	srand((time(NULL)));

	vector<int> argento;
	
	argento = {1,1,1,1,1};

	/*Individuo persona2(argento);

	cout << endl;

	persona2.mostrar();*/

	

	int on = 1;

	while(on){
		Poblacion arios(argento);

		arios.mostrar();

		arios.seleccionar();
		cin >> on;
	}

	return 0;
}
