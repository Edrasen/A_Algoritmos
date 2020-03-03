//Factorizar un numero Avanze

//Carmona Beltran Luis Enrique
//Ramos Mesas Edgar Alain 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
	{ 
		int i=2,num=123456, aux;
		aux=num;
		
		do
			{
				if((num%i)==0)
					{
						printf("Primo: %i\n",i);
						num=num/i;
					}
				else{  i++; /*printf(": %i",i);*/}
			}while(i<aux);
		
		return 0;
	}

