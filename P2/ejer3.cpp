#include<stdio.h>
#include<stdlib.h>

int multiply(int x,int y);

int main()
{
	long x,y,z;
	printf("Numero X: ");
	scanf("%i",&x);
	printf("Numero Y: ");
	scanf("%i",&y);

	if(y==0) printf("%i*%i=0",x,y);
	else z = multiply(x,y);
	printf("\n%i*%i= %i",x,y,z);
	return 0;
}

int multiply(int x,int y)
{
	long z;
	if(y==0) return 0;
	z= multiply(x,y/2);
	if((y%2)==0) return 2*z;
	else return x+(2*z);
}
