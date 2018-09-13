/*P0.c*/
/*felipe_cesar_cardoso_silva*/
/*11811eel044*/

#include<stdio.h>

int main(){
	
	int estado=0, i=0;
	char bits[256];
	
	scanf("%s", bits);
	
	while(bits[i] != '\0') {
		
		if(bits[i]=='0'&&estado==0||bits[i]=='1'&&estado==1)
			estado=0;
		else if(bits[i]=='1'&&estado==0||bits[i]=='0'&&estado==2)
			estado=1;
		else if(bits[i]=='0'&&estado==1||bits[i]=='1'&&estado==2)
			estado=2;
		
		i++;
	}

	if(estado==0)
		printf("%s eh multiplo de 3\n", bits);
	else
		printf("%s nao eh multiplo de 3\n", bits);
	
	return 0;
}