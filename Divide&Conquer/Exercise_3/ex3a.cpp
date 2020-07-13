//Ramos Mesas Edgar Alain
//Inversiones por fuerza bruta

#include<iostream>
#include <fstream>

using namespace std;

int* create(int);
int num(int*, int n);
void showArr(int *, int);
int* fill(int*, int);

int main()
{
    int n;
    int *a;
    cout<<"Numero de elementos en el arreglo: \n";
    cin>>n;
    a = create(n);
    fill(a,n);
    showArr(a, n);
    num(a, n);
    return 0;
}

int* create(int n){
    int* arr; 
    arr = (int* )calloc(n, (sizeof(int)));
    return arr;
}

void showArr(int *a, int n){
    for(int k = 0; k < n; k++){
        cout<<"|"<<a[k];
    }
    cout<<endl;
}

int* fill(int *a, int n){
    int i;
    ifstream inData; //filestream 
    inData.open("input.txt"); //open input file
    for (i=0; i<n; i++) { //it allows save x & y data from coordinates
        inData >> a[i];
    }
    inData.close(); //closing input file
    return a;
}

int num(int *a, int n){
    int i, j;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (a[i] > 2*a[j]){
                count++;
                cout<<"("<<a[i]<<" , "<<a[j]<<")"<<endl;
            }
        }
    }
    cout<<"\n\nEl numero de pares es: "<<count<<endl;
    return count;
}
