/*P7.c*/
/*felipe_cesar_cardoso_silva*/
/*11811eel044*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef
    struct ponto{double x,y;}
ponto;

ponto * gerar_pontos(int N) {
    ponto * coordenadas = (ponto *) calloc(N,sizeof(ponto));
    int i;
    for(i = 0; i < N; i++){
        coordenadas[i].x = cos(i*2.0*M_PI/(N-1));
        coordenadas[i].y = sin(i*2.0*M_PI/(N-1));
    }
    return coordenadas;
}


void gravar_pontos(Ponto * p_inicial, int N) {
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "wb");
    fwrite(p_inicial, N,sizeof(Ponto),arquivo);
    fclose(arquivo);
}

void mostrar_pontos(ponto * p_inicial, ponto * p_final){
	if(p_inicial < p_final){
		printf("(%.3lf, %.3lf)", p_inicial -> x, p_inicial -> y);
		mostrar_pontos(p_inicial + 1, p_final);
	}
}

ponto * ler_pontos(char * nome_arquivo, unsigned int * pN) {
    ponto * coordenadas = (ponto *) malloc(sizeof(ponto));
    unsigned int N = 0;
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "rb");
    while(1) {
        fread(coordenadas, 1,sizeof(ponto),arquivo);
        if(feof(arquivo)) break;
        N++;
    }
    rewind(arquivo);
    coordenadas = (ponto *) realloc(coordenadas,N*sizeof(ponto));
    fread(coordenadas, N, sizeof(ponto),arquivo);
    fclose(arquivo);
    *pN = N;
    return coordenadas;
}


int main()
{
    unsigned int N;
    int option;
    ponto *coordenadas;
	printf("1 - Gravar arquivo\n2 - Ler arquivo\n");
    scanf("%u", &option); 
	getchar();	
	if(option == 1){
        printf("Digite o numero de pontos: ");
		scanf("%u", &N); getchar();
        coordenadas = gerar_pontos(N);
        grava_pontos(coordenadas, N);
        printf("Arquivo gravado");
    }
    else if(option == 2){
        coordenadas = ler_pontos("pontos.dat", &N);
        mostrar_pontos(coordenadas, coordenadas + N);
    } 
	else
		printf(" ERRO ");
    free(coordenadas);
    return 0;
}