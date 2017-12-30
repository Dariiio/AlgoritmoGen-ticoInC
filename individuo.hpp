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

	void mostrar();
	
	void calcular_fitness(vector<int> argento);

private:
	vector<int> cuerpo;
	int fitness ;
};

Individuo::Individuo()
{
	for(int i = 0; i < 5; i++){
		cuerpo.push_back(rand()%(10-1));
	}
	fitness = 0;
}

void Individuo::mostrar()
{
	cout << "[";
	for(int i = 0; i < 5; i++){
		if( i == 4){
			cout << cuerpo[i];
		}else{
		cout << cuerpo[i] << ",";
		}
	}
	cout << "] - fitness: " << fitness;
}

void Individuo::calcular_fitness(vector<int> argento)
{
	for(int i = 0; i < 5; i++){
		if( cuerpo[i] == argento[i]){
			fitness++;
		}
	}
}
#endif
