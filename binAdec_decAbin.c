#include <stdio.h>
#include<math.h>


int numbin;
int temp;
int c,a;
int i=0, dec=0;

int binario_decima(int temp, int numbin){
	
	
	while (numbin>0){
		c=pow(2,i);//variable que guarda el valor de 2 elevado a la potencia i
		a=temp%10;//variable necesaria para la solucion de la conversion
		dec=dec+c*a;//conversion del primer numero de binario a decimal [000'0']
		printf("Primer numero en decima: %d\n",dec);
		numbin=numbin/10;//para eliminar el primer digito del numero binario [000'0']
		temp=temp/10;
		i++;
	}
	
	printf("Numero en binario: %d\n", numbin);
	printf("Numero en decimal: %d\n", dec);
	
	return dec;
}


int main(int argc, char *argv[]) {
	
	
	printf("Escribe un numero en binario: ");
	scanf("%d",&numbin);
	temp=numbin;//aqui se guarda el numero binario en una variable temporal
	
	binario_decima(temp, numbin);
	
	return 0;
}
