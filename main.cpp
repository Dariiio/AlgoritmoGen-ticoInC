#include <iostream>
#include <time.h>
#include "individuo.hpp"


using namespace std;

int main(int argc, char const *argv[])
{
	srand((time(NULL)));

	Individuo persona1;

	persona1.mostrar();

	int asd;
	cin >> asd;

	return 0;
}
