#include <stdio.h>



int rows, coef = 1, space;



void Pascal(int rows)
{

	for(int i=0; i<rows; i++)//determina cuantas lineas se van a imprimir
	{
		for(space=1; space <= rows-i; space++)//imprime dos espacios para dar forma al triangulo
			printf("**");
		
		for(int j=0; j <= i; j++)
		{
			if (j==0 || i==0)
				coef = 1;
			else
				coef = coef*(i-j+1)/j;
			
			printf("%4d", coef);
		}
		printf("\n");
	}
	
}
	

int main(int argc, char *argv[]) {
	
	
	printf("Enter number of rows: ");
	scanf("%d",&rows);
	
	Pascal(rows);	
	
	
	return 0;
}
