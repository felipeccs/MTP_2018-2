/*P3.c*/
/*felipe_cesar_cardoso_silva*/
/*11811eel044*/

#include<stdio.h>
int main() {

  char numero [256];
   int i = 0, cum = 0;
   printf ("Digite o numero desejado:");
  scanf ("%s", numero);
  getchar ();
  while(numero[i] != '\0'){
if (numero[i] >= 48  && numero[i] <= 57){
cum = cum*10 + numero[i] - '0';
}
 i++;

}
  printf("Caracter digitado: %d", cum);
  return 0;
  }
