#Practica 4
#Ramos Mesas Edgar Alain

#quicksort by pivot at last element 

#By printing every iteraction with partition function we will be able to see
#how many iterations there are on the algorithm, in this case it takes only 6 iterations.

contador = 0
comparaciones = 0

def partition(arr,low,high):
    global contador
    global comparaciones
    comparaciones +=1
    print(arr) 
    i = ( low-1 )         # index of smaller element 
    pivot = arr[high]     # pivot 
  
    for j in range(low , high): 
  
        # If current element is smaller than the pivot 
        if   arr[j] < pivot: 
            # increment index of smaller element 
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i]
            contador +=1 
  
    arr[i+1],arr[high] = arr[high],arr[i+1]
    contador +=1 
    return ( i+1 ) 
  
  
# Function to do Quick sort 
def quickSort(arr,low,high): 
    if low < high: 
        # part is partitioning index, arr[p] is now 
        # at right place 
        part = partition(arr,low,high) 
        # Separately sort elements before 
        # partition and after partition 
        quickSort(arr, low, part-1) 
        quickSort(arr, part+1, high) 
  
  
#Test code
arr = [10,7,8,9,1,5,5] 
n = len(arr) 
quickSort(arr,0,n-1) 
print("Sorted array is:")
print(arr)
print(" Swaps: ", contador)
print(" Comparaciones: ", comparaciones)