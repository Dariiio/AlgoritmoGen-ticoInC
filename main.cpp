#include <iostream>
#include <time.h>
#include "individuo.hpp"


using namespace std;

int main(int argc, char const *argv[])
{
	srand((time(NULL)));

	vector<int> argento;
	
	argento = {1,1,1,1,1};

	Individuo persona1;

	persona1.mostrar();
	
	persona1.calcular_fitness(argento);

	cout << endl;
	persona1.mostrar();

	int asd;
	cin >> asd;

	return 0;
}
