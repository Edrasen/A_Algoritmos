//Ramos Mesas Edgar Alain
//Calculando el mcd con el algoritmo de Euclides

#include<iostream>

using namespace std;

int gcd(int m, int n) {
   if(m == n)
      return m;
   else if (m > n)
      return gcd(m-n, n);
   else
      return gcd(m, n-m);
}
      
int main(){
    int a, b;
    cout<<"\nIngrese el primer numero: ";
    cin>>a;
    cout<<"\nIngrese el segundo numero: ";
    cin>>b;
    cout<<"\nEl Maximo Comun Divisor es: "<<gcd(a,b)<<"\n";
    return 0;
}
