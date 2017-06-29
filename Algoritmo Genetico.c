#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POBLACION_MAX 10
#define GENES 5
#define PRESION 3	//esto debe ser el 30% de la poblacion actual,son los individuos que prevaleceran hasta la siguiente generacion
#define MUTACION 0.2
#define MARCA_DE_DIOS 8008135


/*creamos el modelo de nuestro individuo, tiene como "cuerpo" un vector de 5 elementos 
en donde se guardara su informacion "genetica".	Esto sera impsortante para determinar 
en un comienzo la individualidad de cada ser y asegurarnos una poblacion diversa hasta que esta
"evolucione" a una poblacion homogenea con las carcteristicas individuales deseada.
*/
typedef struct individuo_str
{
	int vector[GENES];
	int fitnes;
	long int id;
}individuo_str;

//Guardamos en un arreglo global el modelo de vector al que queremos evolucionar
int vectorModelo[] = {1, 1, 1, 1, 1};

void inicializarPoblacion(individuo_str * poblacion, int caso){
	int i, e;
	switch(caso){
		case 0:
			//INICIALIZA EN NULL A TODO LOS ELEMENTOS DEL VECTOR Y A SU FITNES
			for(i = 0; i < POBLACION_MAX;i++){
				poblacion[i].fitnes = 0;
				poblacion[i].id = i;
				for(e = 0; e < GENES; e++){
					poblacion[i].vector[e] = 0;

				}
			}
			break;
		case 1:
			//inicializa con numeros aleatorios a los vectores, calcula su fitnes y le otroga un id unico en su poblacion
			for(i = 0; i < POBLACION_MAX;i++){
				poblacion[i].fitnes = 0;
				poblacion[i].id = i;
				for(e = 0; e < GENES; e++){
					poblacion[i].vector[e] = rand()%(10-1);
					if(poblacion[i].vector[e] == vectorModelo[e]){
						poblacion[i].fitnes++;
					}	
				}
			}
			break;
		default:
			printf("NO SE ESTA INICIALIZANDO NADA \n");
	}

}

//muestra cualquier arreglo invididuo_str de N elementos
void mostrarPoblacion(individuo_str * poblacion){
	int i, e;
	if(sizeof(*poblacion)==32){
		for(i=0;i<POBLACION_MAX;i++){
			printf("%d )", i);
			for(e=0;e<GENES;e++){
				printf(" %d,", poblacion[i].vector[e]);
			}
			printf(" | fitnes = %d", poblacion[i].fitnes);
			printf(" | id = %ld |", poblacion[i].id);
			printf("\n");
		}
	}
}

void saltoGeneracional(int * vectorNuevo, int * vectorViejo){
	int i;
	for(i = 0;i < GENES; i++){
		*(vectorNuevo + i) = *(vectorViejo + i);
	}
}

//selecciona los mejores fitnes
void seleccion(individuo_str * nextGeneration ,individuo_str * poblacion){
	int e;
	for(e = 0; e < PRESION; e++){
		int i, mejorFitnes = 0, selected;
		for(i = 0; i < POBLACION_MAX; i++){
			if(poblacion[i].fitnes >= mejorFitnes && poblacion[i].id != MARCA_DE_DIOS){
				//printf("id = %ld\n", poblacion[i].id);
				mejorFitnes = poblacion[i].fitnes;
				selected = poblacion[i].id;
			}
		}
		//printf("selected = %d \n", selected);
		for (i = 0; i < POBLACION_MAX; i++){
			if(poblacion[i].id == selected){
				poblacion[i].id = MARCA_DE_DIOS;
				saltoGeneracional(nextGeneration[i].vector, poblacion[i].vector);
				nextGeneration[i].fitnes = poblacion[i].fitnes;
				nextGeneration[i].id = poblacion[i].id;
			}
		}
	}
}

//Separa a los padres
void searchPadres(individuo_str * padres, individuo_str * poblacion){
	int i, e;
	for(i = 0; i < PRESION; i++){
		for(e = 0; e < POBLACION_MAX; e++){
			if(poblacion[e].id == MARCA_DE_DIOS){
				saltoGeneracional(padres[i].vector, poblacion[e].vector);
				printf("\n %ld \n", poblacion[e].id);
				poblacion[e].id = e;
			}
		}
	}
}

int main(){
	//inicializamos la seed de eso en lo que devuelve time()
	srand((time(NULL)));
	
	//creamos un arreglo de individuos llamado firstGeneration
	individuo_str firstGeneration[POBLACION_MAX];
	//creamos un arreglo para nextGeneration
	individuo_str nextGeneration[POBLACION_MAX];
	//Ponemos a los padres en un arreglo de PRESION elementos
	individuo_str padres[PRESION];
	
	inicializarPoblacion(firstGeneration, 1);
	inicializarPoblacion(nextGeneration, 0);
	printf("PRIMERA GENERACION: \n");
	mostrarPoblacion(firstGeneration);
	seleccion(nextGeneration, firstGeneration);
	printf("\nSelecionados:\n");
	mostrarPoblacion(firstGeneration);
	printf("\nNextGeneration:\n");
	mostrarPoblacion(nextGeneration);

	printf("\n");
	searchPadres(padres, firstGeneration);
	mostrarPoblacion(padres);
	return 0;
}