/*P5.c*/
/*felipe_cesar_cardoso_silva*/
/*11811eel044*/

#include <stdio.h>

typedef

	unsigned long long int

Bytes8;

typedef

	struct LCG { Bytes8 a, c, m, rand_max, atual; }

LCG;

void semente(LCG * r, Bytes8 seed) 
{
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) 
{
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r) 
{
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_num(float * vetor, int tam, float min, float max, LCG * r)
{
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float somatorio(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor + somatorio(inicio_vetor + 1, fim_vetor));
	return 0;
}

float produtorio(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor * produtorio(inicio_vetor + 1, fim_vetor));
	return 1;	
}

int main()
{
	LCG random;
	semente(&random, 123456);
	int opcao;
	float num[50];
	
	gera_num(num, 50, 0.5, 1.5, &random);
	
	do
	{
		scanf("%d", &opcao);
		getchar();
		switch(opcao)
		{
			case 1:
				printf ("\n %.6f \n\n", somatorio(&num[0], &num[49]));
				break;
		
			case 2:
				printf ("\n %g \n\n", produtorio(&num[0], &num[49]));
				break;
		}
	}while(opcao!=3);
	
	return 0;
}
