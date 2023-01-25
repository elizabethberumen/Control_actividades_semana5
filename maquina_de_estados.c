#include <stdio.h>
#include<string.h>
#include<stdint.h>


//Macro para el ESTADO_1
#define MAX_SIZE 100

//Macro para el ESTADO_3
#define PRINT(x)  (x < 2 ? printf("ok"): printf("false"))



//fUNCION ESTADO_INICIAL
void swap(int *num1, int *num2);
void swap_sinpuntero(int num1, int num2);


//Funcion del ESTADO_4 (Encriptado)
int encrypt(int ch, int base);


//Funciones del ESTADO_5 (bitwise mask)
void more_stuff(uint32_t value);
void mask(uint32_t valor);


//Funcion del ESTADO_6 (concatenar)
void concatenar(uint32_t temp);


//Funcion del ESTADO_7 (XOR)
void xor_(uint32_t a, uint32_t b);
unsigned int xor_2(unsigned int v);



//variables globales para ESTADO_6
unsigned char byte1 = 0x0F;   // 00001111
unsigned char byte2 = 0xCC;   // 11001100
unsigned char byte3 = 0x55;   // 01010101
unsigned char byte4 = 0x04;   // 00000100



enum estados {
	INICIAL, ESTADO_1, ESTADO_2, ESTADO_3, ESTADO_4, ESTADO_5, ESTADO_6, ESTADO_7, ESTADO_FINAL
};

int main(int argc, char *argv[]) {
	
	enum estados estado_actual=INICIAL;
	int entrada;
	
	while(estado_actual!=ESTADO_FINAL){
		switch(estado_actual){
		case INICIAL:
			printf("Estas en el estado inicial: \n");
			
			//desarrollo del scope del main
			printf("En esta parte se hace el intercambio de los numeros ingresados por medio de punteros: \n\n");
			
			int num1;
			int num2;
			
			printf("Ingresa dos numeros: ");
			scanf("%d %d", &num1, &num2);
			
			printf("Antes de intercambiar: \n");
			printf("Numero 1: %d\n", num1);
			printf("Numero 2: %d\n",num2);
			
			swap(&num1,&num2);
			
			printf("Despues de intercambiar en el main: \n");
			printf("Numero 1 en el main: %d\n", num1);
			printf("Numero 2 en el main: %d\n",num2);
			
			//sin puntero 
			int num3 =5;
			int num4=6;
			swap_sinpuntero(num3,num4);
			printf("Despues de intercambiar sin punteroen el main: \n");
			printf("Numero 1 en el main: %d\n", num3);
			printf("Numero 2 en el main: %d\n\n\n\n",num4);
			
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_1;
			}
			else if (entrada==2){
				estado_actual=ESTADO_2;
			}
			break;
			
		case ESTADO_1:
			printf("Estamos en el ESTADO_1\n\n");
			
			//desarrollo del scope del main
			char text1[MAX_SIZE]; // 1 byte, array
			char text2[MAX_SIZE]; // 1 byte, array
			int i;
			
			printf("Ingresa cualquier string: \n");
			scanf("%s",&text1);
			
			//copia text1 en text2 caracter por caracter
			i=0;
			while(text1[i] != '\0'){
				text2[i]=text1[i];
				i++;
			}
			
			//buffer
			//se asegura de que el string es NULL o ha terminado
			text2[i]='\0';
			
			printf("First string = %s\n", text1);
			printf("second string = %s\n", text2);
			printf("Total characters copied = %d\n\n\n\n", i);
			
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_2;
			}
			else if (entrada==2){
				estado_actual=ESTADO_3;
			}
			break;
		
		case ESTADO_2:
			printf("Estamos en el ESTADO_2\n\n");
			
			//desarrollo
			char str[50];
			
			strcpy(str, "This is string.h library function");
			puts(str); //asignar
			
			memset(str,'$',7);
			puts(str);
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_3;
			}
			else if (entrada==2){
				estado_actual=ESTADO_4;
			}
			
			break;
			
		case ESTADO_3:
			printf("Estamos en el ESTADO_3\n\n");
			
			
			//desarrollo utilizando la macro #define PRINT(i) (i < 2 ? printf("ok"): printf("false"))
			int x = 1 ;
			PRINT(x);
			
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_4;
			}
			else if (entrada==2){
				estado_actual=ESTADO_5;
			}
			
			break;
		
		case ESTADO_4:
			printf("Estamos en el ESTADO_4");
			
			
			//desarrollo del scope del main
			int ch;
			while((ch >= getchar())!= EOF){
				ch= encrypt (ch,'A');
				
				if (ch >= 'A' && ch <='z' ){
					ch= encrypt(ch, 'A');
				}
				putchar(ch);
			}
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_5;
			}
			else if (entrada==2){
				estado_actual=ESTADO_6;
			}
				
			break;
			
		case ESTADO_5:
			printf("Estamos en el ESTADO_5\n\n");
			
			//desarrollo del scope main
			uint32_t value=1;
			more_stuff(value);
			
			uint32_t valor=1;
			mask(valor);
			
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_6;
			}
			else if (entrada==2){
				estado_actual=ESTADO_7;
			}
			break;
			
		case ESTADO_6:
			printf("Estamos en el ESTADO_6\n\n");
			
			//desarrollo del scope main
			uint32_t temp=0;
			concatenar(temp);
			
			
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_7;
			}
			else if (entrada==2){
				estado_actual=ESTADO_FINAL;
			}
			
			break;
			
		case ESTADO_7:
			printf("Estamos en el ESTADO_7\n\n");
			
			// desarrollo del scope main 
			int a=0x3; //0011
			int b=0xA; //1010
			xor_(a,b);
			
			a=0x9;//1001
			b=0xA;//1010
			xor_(a,b);
			
			a=0x9;//1001
			b=0x3;//0011
			xor_(a,b);
			//printf("Estos son los valores de la operacion XOR: %u",(void)xor(a,b));
			
			a=0xA;//1010
			b=0x3;//0011
			xor_(a,b);
			
			
			unsigned int v;  // word value to compute the parity of
			xor_2(v);
			
			
			printf("Ingresa 1 o 2: \n");
			scanf("%d",&entrada);
			
			if(entrada==1){
				estado_actual=ESTADO_FINAL;
			}
			else if (entrada==2){
				estado_actual=INICIAL;
			
			}
			break;
		case ESTADO_FINAL:
			printf("Estamos en el ESTADO_FINAL\n\n");
			break;
			
		default:
			printf("Entrada invalida\n\n");
			estado_actual=INICIAL;
			break;
		}
	}
	return 0;
}

//FUNCIONES
void swap(int *num1, int *num2){
	int temp;
	temp=*num1;
	*num1=*num2;
	*num2=temp;
	
	printf("Despues de intercambiar los numeros en la funcion: \n");
	printf("Numero 1 en la funciom: %d\n", *num1);
	printf("Numero 2 en la funcion: %d\n",*num2);
}
	
void swap_sinpuntero(int num1, int num2){
	int temp;
	temp=num1;
	num1=num2;
	num2=temp;
	
	printf("Despues de intercambiar los numeros en la funcion: \n");
	printf("Numero 1 en la funcion: %d\n", num1);
	printf("Numero 2 en la funcion: %d\n",num2);
	
}
	
//ESTADO_4: encriptar 
int encrypt(int ch, int base){
	ch -= base;
	ch += 13;
	ch %= 26; //modulo de ch

return ch + base; //cambia el valor de los bits
}

//ESTADO_5: bitwise_mask
void more_stuff(uint32_t value) {             // Example value: 0x01020304
	uint32_t byte1 = (value >> 24);           // 0x01020304 >> 24 is 0x01 so
	// no masking is necessary
	uint32_t byte2 = (value >> 16) & 0xff;    // 0x01020304 >> 16 is 0x0102 so
	// we must mask to get 0x02
	uint32_t byte3 = (value >> 8)  & 0xff;    // 0x01020304 >> 8 is 0x010203 so
	// we must mask to get 0x03
	uint32_t byte4 = value & 0xff;            // here we only mask, no shifting
	// is necessary
	
}

void mask(uint32_t valor) {             // Example value: 0x01020304
	uint32_t byte5 = (valor << 24);           // 0x01020304 >> 24 is 0x01 so
	// no masking is necessary
	uint32_t byte6 = (valor << 16) & 0x0f;    // 0x01020304 >> 16 is 0x0102 so
	// we must mask to get 0x02
	uint32_t byte7 = (valor<< 8)  & 0x0f;    // 0x01020304 >> 8 is 0x010203 so
	// we must mask to get 0x03
	uint32_t byte8 = valor & 0xff;            // here we only mask, no shifting
	// is necessary
	
}

//ESTADO_6: concatenar
void concatenar(uint32_t temp)
{
	temp = temp | byte1; //the result should be 00001111 for now
	
	temp = temp >> 8;
	byte2 = byte2 << 8;
	temp = temp | byte2; //the result should be 1100110000001111 for now
	
	temp = temp >> 8;
	byte3 = byte3 << 8;
	temp = temp | byte3; //the result should be 010101011100110000001111 for now
	
	temp = temp >> 8;
	byte4 = byte4 << 8;
	temp = temp | byte4; //the result should be 00000100010101011100110000001111
}

//ESTADO_7: XOR
void xor_(uint32_t a, uint32_t b){
	a = a^b;   
	b = a^b;
	a = a^b;
}
	
unsigned int xor_2(unsigned int v){

	v ^= v >> 16;
	v ^= v >> 8;
	v ^= v >> 4;
	v &= 0xf;
	return (0x6996 >> v) & 1;
}





