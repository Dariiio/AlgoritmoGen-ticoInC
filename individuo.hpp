#include <iostream>
#include <stdlib.h>
#include "vector"

using namespace std;

class Individuo
{
public:
	Individuo();

	void mostrar();

private:
	vector<int> cuerpo;

};

Individuo::Individuo()
{
	for(int i = 0; i < 5; i++){
		cuerpo.push_back(rand()%(10-1));
	}
}

void Individuo::mostrar()
{
	for(int i = 0; i < 5; i++){
		cout << cuerpo[i] << ",";
	}
}