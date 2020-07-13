//Ramos Mesas Edgar Alain
//Evaluacion de un polinomio mediante el metodo de Horner

#include<iostream>

using namespace std;

int horner(int *coef, int x){
    int i;
    int resultado = 0;
    for(i=0; i < sizeof(coef); i++)
        resultado = resultado * x + coef[i];
    return resultado;
}

int main()
{
    int valx;
    int coeficientes[] = {4,3,2,1};
    int res;
    cout<<"\nIntroduzca el valor de X a evaluar: ";
    cin>>valx;
    res = horner(coeficientes, valx);
    cout<<"\nEl resultado de la evaluacion es: "<<res<<endl;
    return 0;
}
