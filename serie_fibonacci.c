#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, first = 0, second = 1, next, c;
	
	printf("Ingresa el numero de terminos: \n");
	scanf("%d",&n);
	
	printf("Primeros %d terminos de la serie de Fibonacci:\n",n);
	
	for ( c = 0 ; c < n ; c++ )
	{
		if ( c <= 1 )
			next = c;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
		printf("%d  ",next);
	}
	
	return 0;
}

