/*P5.c*/
/*felipe_cesar_cardoso_silva*/
/*11811eel044*/

#include <stdio.h>
#include <stdlib.h>
#define max 100

void gera_numeros(float * vetor, int tam)

{

	int i;
	float num;
	for(i=0; i<tam; i++)
		vetor[i] = (float) rand()/(float) RAND_MAX + 0.5f;
}

float soma(float *inicio_vetor, float *fim_vetor) 

{

	return (inicio_vetor == fim_vetor)? 0.0 : *inicio_vetor + soma(inicio_vetor+1, fim_vetor);

}

float produto(float *inicio_vetor, float *fim_vetor) 

{

	return (inicio_vetor == fim_vetor)? 1.0 : *inicio_vetor * produto(inicio_vetor+1, fim_vetor);

}

int main()

{

	srand(123456);
	float v[max];
	int op=0;
	gera_numeros(v, max);

		scanf("%d", &op);
		getchar();
		switch (op)

		{

			case 1:
				printf("\n%f\n", soma(v, v + max)); 
				break;
				
			case 2:

				printf("\n%f\n", produto(v, v + max)); 
				break;

		}



	return 0;

}
