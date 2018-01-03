# ifndef INDIVIDUO_HPP
# define INDIVIDUO_HPP

#include <iostream>
#include <stdlib.h>
#include "vector"

using namespace std;

class Individuo
{
public:
	Individuo();

	Individuo(vector<int> argento);

	void mostrar();
	
	void calcular_fitness(vector<int> argento);

	int fitness;

	bool seleccionado = false;

private:
	const int MAX_GENES = 5;

	vector<int> cuerpo;

};

Individuo::Individuo()
{	
	fitness = 0;
	for(int i = 0; i < MAX_GENES; i++){
		cuerpo.push_back(rand()%(10-1));
	}
}

Individuo::Individuo(vector<int> argento)
{
	fitness = 0;
	for(int i = 0; i < MAX_GENES; i++){
		cuerpo.push_back(rand()%(10-1));
		if( cuerpo[i] == argento[i]){
			fitness++;
		}
	}
}

void Individuo::mostrar()
{
	cout << "[";
	for(int i = 0; i < MAX_GENES; i++){
		if( i == MAX_GENES - 1){
			cout << cuerpo[i];
		}else{
		cout << cuerpo[i] << ",";
		}
	}
	cout << "] | fitness: " << fitness;
	cout << " | seleccionado: " << seleccionado;
}

void Individuo::calcular_fitness(vector<int> argento)
{
	for(int i = 0; i < MAX_GENES; i++){
		if( cuerpo[i] == argento[i]){
			fitness++;
		}
	}
}
#endif
