//Ramos Mesas Edgar Alain
//Calculando el Maximo Comun divisor con casos base

#include<iostream>
#include<math.h>

using namespace std;

void intercambia(int &a, int &b){
        int aux;
        aux = b;
        b = a;
        a = aux;
}

int mcd(int a, int b){
    if (a == b)
        return a;
    else if (a % 2 == 0 && b % 2 == 0)      //Ambos pares
        return 2 * mcd(a/2, b/2);
    else if (a % 2 == 1 && b % 2 == 0)      //a impar, b par
        return mcd(a, b/2);
    else if (a %  2 == 0 && b %2 == 1)      //a par, b impar
        return mcd(a/2, b);
    else if (a % 2 == 1 && b % 2 == 1)      //Ambos impares
        if(a>b)
            return mcd((a-b)/2, b);     //subcaso a > b
        else                                            //Estos bloques contribuyen a obtenr la solucion mas simple....        
            return mcd((b-a)/2, a);     //subcaso a < b
}

int main(){
    int a, b, aux;
    cout<<"\nIngrese el primer numero: ";
    cin>>a;
    cout<<"\nIngrese el segundo numero: ";
    cin>>b;
    if(a>b)
        intercambia(a,b);
    cout<<"\nEl Maximo Comun Divisor es: "<<mcd(a,b)<<"\n";
    return 0;
}
