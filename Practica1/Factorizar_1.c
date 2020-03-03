//Factorizar un numero Avanze

//Carmona Beltran Luis Enrique
//Ramos Mesas Edgar Alain 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
	{
		int num,aux1,aux2,i=0;
		double a,b;
		printf("Introduce numero a factorzar: ");
		scanf("%i",&num);
		
		aux1=sqrt(num);
		printf("Raiz %i: ",aux1);
		num=pow(num,2);
		aux1++;

		do
		{
			a=pow(aux1,2);
			//aux1++;
			b = a-num;
			aux2=b;
			b =sqrt(aux2);
			aux2 =sqrt(aux2);

			if(aux2-b == 0) printf("Heuston lo tenemos %i \n", aux2);
			else printf("Heuston NONONO lo tenemos\n");
			printf("Heuston lo tenemos %f\n , b:%f ,aux2: %",aux2-b,b,aux2);
			i++;
			
					
		}while(i!=10);
		
				
			
		
		
		
			
				
		return 0;
	}
