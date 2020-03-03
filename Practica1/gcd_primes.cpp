//Ejercicio 3
//Maximo Comun Divisor con factores primos.
//El programa calcula los factores primos de cada uno de los numero long long introducidos.

//Carmona Beltran Luis Enrique
//Ramos Mesas Edgar Alain

#include <bits/stdc++.h> 
#define MAXFACTORS 1024 
using namespace std; 
  
// struct to store factorization of m and n 
typedef struct{ 
    long long int size; 
    long long int factor[MAXFACTORS + 1]; 
    long long int exponent[MAXFACTORS + 1]; 
} FACTORIZATION; 
  
// Function to find the factorization of M and N 
void FindFactorization(long long int x, FACTORIZATION* factorization){ 
    long long int i, j = 1; 
    long long int n = x, c = 0; 
    long long int k = 1; 
    factorization->factor[0] = 1; 
    factorization->exponent[0] = 1; 
    for (i = 2; i <= n; i++) { 
        c = 0; 
        while (n % i == 0) { 
            c++; 
            n = n / i; 
        } 
        if (c > 0) { 
            factorization->exponent[k] = c; 
            factorization->factor[k] = i; 
            k++; 
        } 
    } 
    factorization->size = k - 1; 
} 
  
// Function to prlong long int the factors 
void DisplayFactorization(long long int x, FACTORIZATION factorization){ 
    long long int i; 
    cout << "Prime factor of " << x <<" = "; 
    for (i = 0; i <= factorization.size; i++) { 
        cout << factorization.factor[i]; 
        if (factorization.exponent[i] > 1) 
            cout << "^" << factorization.exponent[i]; 
        if (i < factorization.size) 
            cout << "*"; 
        else
            cout << "\n"; 
    } 
} 
  
// function to find the gcd using Middle School procedure 
long long int gcdMiddleSchoolProcedure(long long int m, long long int n){ 
    FACTORIZATION mFactorization, nFactorization; 
  
    long long int r, mi, ni, i, k, x = 1, j; 
    // Step 1. 
    FindFactorization(m, &mFactorization); 
    DisplayFactorization(m, mFactorization); 
    // Step 2. 
    FindFactorization(n, &nFactorization); 
    DisplayFactorization(n, nFactorization); 
    // Steps 3 and 4. 
    // Procedure algorithm for computing the 
    // greatest common divisor. 
    long long int min; 
    i = 1; 
    j = 1; 
    while (i <= mFactorization.size && j <= nFactorization.size) { 
        if (mFactorization.factor[i] < nFactorization.factor[j]) 
            i++; 
        else if (nFactorization.factor[j] < mFactorization.factor[i]) 
            j++; 
        else /* if arr1[i] == arr2[j] */
        { 
            min = mFactorization.exponent[i] > nFactorization.exponent[j] 
                      ? nFactorization.exponent[j] 
                      : mFactorization.exponent[i]; 
            x = x * mFactorization.factor[i] * min; 
            i++; 
            j++; 
        } 
    } 
    cout << "GCD(" << m << "," << n << ") = ";
    return x; 
} 
  
int main(){ 
    long long int n, m;
    cout << "First number: \n";
    cin >> m;
    cout << "Second number: \n";
    cin >> n;
    cout << gcdMiddleSchoolProcedure(m, n);
    return (0);
}
