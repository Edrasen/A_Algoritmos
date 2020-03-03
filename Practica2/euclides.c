//Ejercicio 4: mcd con EUCLIDES
//
//Este programa calcula el máximo comun divisor de dos numeros haciendo uso de la regla de euclides,
//se trata de un algoritmo recursivo.
//
//Carmona Beltran Luis Enrique
//Ramos Mesas Edgar Alain


#include<stdio.h>
#include<math.h>

int r_gcd(int, int);
int getNumbers(int*, int*);

int main(){
	int n1, n2;
	getNumbers(&n1, &n2);
	printf("El mcd de %d y %d es: %d\n", n1,n2, r_gcd(n1,n2));
}

int r_gcd(int x, int y){
	if(x == 0)
		return y;
	return r_gcd(y%x, x);
}

int getNumbers(int* n1, int* n2){
	printf("\nIngrese el primer numero: ");
	scanf("%d", n1);
	printf("\nIngrese el segundo numero: ");
	scanf("%d", n2);
}
