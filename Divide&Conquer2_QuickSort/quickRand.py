#Practica 4 QuickSort
#Ramos Mesas Edgar Alain

#By printing every iteraction with partition function we will be able to see
#how many iterations there are on the algorithm, in this case it takes 8 iterations.

#quicksort by random pivot

from random import randint

contador = 0
comparaciones = 0

def Partition(A,low,high):
    global contador
    global comparaciones
    comparaciones +=1
    print(A)
    pivot=randint(low,high)
    A[high], A[pivot] = A[pivot], A[high]
    newPivotIndex=low-1
    for index in range(low,high):
        if A[index]<A[high]:    #check if current val is less than pivot value
            newPivotIndex=newPivotIndex+1
            A[newPivotIndex], A[index] = A[index], A[newPivotIndex]
            contador+=1
    A[newPivotIndex+1],A[high] = A[high], A[newPivotIndex+1]
    contador+=1
    return newPivotIndex+1

def QuickSort(A,low,high):
    if low<high:
        p=Partition(A,low,high)
        QuickSort(A,low,p-1)
        QuickSort(A,p+1,high)

arr = [10,7,8,9,1,5,5] 
QuickSort(arr,0,len(arr)-1)
print("Sorted array: ")
print(arr)
print(" Swaps: ", contador)
print(" Comparaciones: ", comparaciones)