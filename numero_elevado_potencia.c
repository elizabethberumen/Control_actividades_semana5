#include <stdio.h>


long int x_to_the_n (int x,int n);


int main(int argc, char *argv[]) {
	
	int x;
	int n;
	
	printf("Ingresa un numero:\n");
	scanf("%d",&x);
	
	printf("Ingresa la potencia:\n");
	scanf("%d",&n);
	
	x_to_the_n ( x, n);
	
	return 0;
}

long int x_to_the_n (int x,int n)
{
	int i; /* Variable used in loop counter */
	int number = 1;
	
	for (i = 0; i < n; ++i)
		number= number * x;
	
	printf("\n\nEl numero %d elevado a la potencia %d es: %d",x,n,number);
	
	return(number);
}
