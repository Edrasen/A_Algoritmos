//E. Alain Ramos Mesas
//Found medium element from a sorted array with increment and decrement order

#include <stdio.h>

int searchp(int A[]){	//function to search value for 1<p<n
	int aux=0,i=0;
	do
	{
		if(A[i] < A[i+1])   //it's note necessary to advance trougth all array
			i++;
		else aux = i + 1;
	}while(aux == 0);   //aux let to know if number at A[i+1] position is greater than A[i]
	return aux;
}
int main()
{
	int A[] = {3,5,6,11,45,63,91,93,85,79,65,54,24};
	printf("%i", searchp(A));   //call to searchp function
}