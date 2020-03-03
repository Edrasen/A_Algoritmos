//E. Alain Ramos Mesas
//Algorithm to order 2 alredy ordered arrays in a third one

#include<iostream>

using namespace std;

//create vector data thah contains an array and its size
typedef struct vector{
    int tamVec;
    int* vec;
}vector;

//vector creation fuction
vector create(int n){                       
    vector v;
    v.vec = (int*)malloc(n*(sizeof(int)));
    v.tamVec = n;
    return v;
}

//it fill the given array and return it with input user data
vector llenar(vector vec){
    for(int j = 0; j < vec.tamVec; j++){
        printf("Introduzca el valor que quiere guardar en la posicion %d.\n", j);
        scanf("%d", &vec.vec[j]);
    }
    return vec;
}

//this functions create a third array with two given arrays
vector createV3(vector v1, vector v2){
    int i, j;
    vector v3 = create(v1.tamVec + v2.tamVec);
    for (i = 0; i < v1.tamVec; i++)
    v3.vec[i] = v1.vec[i];
    for (j = 0; j < (v1.tamVec + v2.tamVec); j++)
    {    
        v3.vec[i] = v2.vec[j];
        i++;
    }
    return v3;
}

//it just let see any array
void showVector(vector v){
    printf("|");
    for(int k = 0; k < v.tamVec; k++){
        printf(" %d |", v.vec[k]);
    }
}
//this function combines all subarrays
void merge(int *arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    // create temp arrays
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray it beggins at l = 0  
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of L[], if there are any
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
//l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int *arr, int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int main(){
    vector v1, v2, v3;
    int tamV1, tamV2, tamV3;
    printf("Introduzca el tamaño del primer vector: ");
    scanf("%d", &tamV1);
    v1 = create(tamV1);
    v1 = llenar(v1);
    printf("Introduzca el tamaño del segundo vector: ");
    scanf("%d", &tamV2);
    v2 = create(tamV2);
    v2 = llenar(v2);
    v3 = createV3(v1, v2);
    tamV3 = v3.tamVec;
    mergeSort(v3.vec, 0, v3.tamVec - 1);
    showVector(v3);
    return 0;
} 
