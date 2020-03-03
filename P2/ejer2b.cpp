//E. Alain Ramos Mesas
//Algorith to find medium element in an array with ascendent and descendent order

#include <iostream>

using namespace std;

int semiSort(int A[],int ini, int fin);

int main()
{
	int aux=0,i=0;
	int A[] = {3,5,6,11,45,63,91,93,85,79,65,54,24};  //we create a generic array
	
	aux = semiSort(A,0,sizeof(A));   //return index from medium element
	printf("%i",aux);
}

int semiSort(int A[],int ini, int fin)
{
	if(ini==fin) return A[0]; //base case
	int mid = (ini+fin)/2;  //it is necessary to create an medium indicator
	if(A[mid-1]<A[mid] && A[mid]>A[mid+1]) return mid + 1;  //it returns index of searched element
	else if(A[mid-1]<A[mid] && A[mid]<A[mid+1]) return semiSort(A,mid+1,fin); //recursive call(it gives O(log n) complexity) 
	else return semiSort(A,ini,mid);    //search left half
}