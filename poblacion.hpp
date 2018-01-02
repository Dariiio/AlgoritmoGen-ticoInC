# ifndef POBLACION_HPP
# define POBLACION_HPP

#include "individuo.hpp"

using namespace std;

class Poblacion
{
public:
	Poblacion();

	Poblacion(vector<int> argento);

	void mostrar();

	void seleccionar();

private:

	Individuo cuerpo[10];

	int mejor_fitness = 0;
	
};

Poblacion::Poblacion()
{
	
}

Poblacion::Poblacion(vector<int> argento)
{
	for(int i = 0; i < 10; i++){
		cuerpo[i].calcular_fitness(argento);
	}
}

void Poblacion::mostrar()
{
	cout << "--------Poblacion-------- " <<endl;
	for(int i = 0; i < 10; i++){
		cuerpo[i].mostrar();
		cout << endl;
	}
}

void Poblacion::seleccionar()
{

}

#endif