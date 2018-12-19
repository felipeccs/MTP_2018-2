/*P6.c*/
/*felipe_cesar_cardoso_silva*/
/*11811eel044*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef
	struct p {
		float x;
		float y;
	}ponto;

ponto * gerar(int n){
	ponto * p = (ponto *) calloc(n,sizeof(ponto));
	int i;
	for(i=0; i<n; i++){
		p[i].x = cos(i*2.0*M_PI/(n-1));
		p[i].y = sin(i*2.0*M_PI/(n-1));
	}
	return p;
}

void mostrar(ponto * pi, ponto * pf){
	if(pi < pf){
		printf("(%.3f, %.3f) ", pi->x, pi->y);
		mostrar(pi+1, pf);
	}
}

int main()
{
	unsigned int n;
	ponto * p;
	printf("Digite o numero de pontos: ");
	scanf("%d",&n);
	getchar();
	p = gerar(n);
	mostrar(p, p+n);
	free(p);
	return 0;
}