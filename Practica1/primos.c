//Ejercicio 1: Numeros primos
//
//Este programa determina si un numero dado es primo o no.
//
//Carmona Beltran Luis Enrique
//Ramos Mesas Edgar Alain

#include<stdio.h>
#include<math.h>

int primo(int);
void printR(int);
int getNum();

int main(){
	int prueba = getNum();
	printR(prueba);
}

int getNum(){
	int number;
	printf("Escribe un numero:\n");
	scanf("%d", &number);
	return number;
}

int primo(int numero){
	int divisor = 1;
	int divisores = 1;
	for(divisor; divisor < numero  ; divisor++){
		if(numero % divisor == 0){
			divisores = divisores + 1;
		}
	}
	if (divisores == 2)
		return 1;
	else
	return 0;
}

void printR(int prueba){
	if(primo(prueba) == 1)
		printf("\nEs numero primo.\n");
	else
		printf("\nNO es primo\n");
}
