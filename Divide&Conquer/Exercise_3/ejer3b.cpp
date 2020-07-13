//Carmona Beltran Luis Enrique
//Analizis de Algoritmos Practica NO.3

//Ejercicio 3.2 
//Encontrar la inverciones con divide y venceras

#include <iostream>

using namespace std;

int mergeSort(int vec[], int s, int e);
int mergeInv(int vec[], int aux[], int s, int e);

int main()
	{
		int vec[]={3,10,11,4,12,9,8,7,6};
		printf("\nEl numero de inversiones es: %i\n",mergeSort(vec,0,8));
	}

int mergeSort(int vec[], int s, int e)
	{
		if(s>=e) return 0;								
		int mid=(s+e)/2, Inv1, Inv2, Inv3;
		int aux[100];
		Inv1=mergeSort(vec,s,mid);					
		Inv2=mergeSort(vec,mid+1,e);						
		Inv3=mergeInv(vec,aux,s,e);
		return Inv1+Inv2+Inv3;
	}

int mergeInv(int vec[], int aux[], int s, int e)
	{
		int mid=(s+e)/2, i=s, j=mid+1, k=s, Inv=0;																											
	    while(i<=mid && j<=e)
	    	{
	    		if(vec[i] < vec[j])
	    			{
	    				aux[k]=vec[i];
						k++;i++;
					}	
				else
					{
						aux[k]=vec[j];
						if(vec[i] > vec[j]*2) Inv=Inv+(mid-i+1);							
						k++;j++;
					}
	    	}
	    while(i<=mid) aux[k++]=vec[i++];							
		while(j<=e) aux[k++]=vec[j++];						
		for(i=s;i<=e;i++) vec[i]=aux[i];
		return Inv;																									
	}
	