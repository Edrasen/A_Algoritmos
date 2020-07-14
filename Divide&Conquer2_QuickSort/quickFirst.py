#Practica 4 QuickSort
#Ramos Mesas Edgar Alain

#By printing every iteraction with partition function we will be able to see
#how many iterations there are on the algorithm, in this case it takes 8 iterations.

#quicksort by first element

contador = 0
comparaciones = 0 

def partition(arr,low,high):
    global contador
    global comparaciones
    comparaciones +=1
    print(arr)
    pivot = arr[low]    # pivot 
    i = low             # index of smaller element
    j = high            # index of greater element
    contador = contador + 1
    for i in range(low, high):    
        if arr[i] <= pivot:
            i += 1;
        if arr[j] >= pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
            contador +=1
    arr[low], arr[j] = arr[j], arr[low]
    contador +=1
    return j
    
# The main function that implements QuickSort 
# arr[] --> Array to be sorted, 
# low --> Starting index, 
# high --> Ending index 

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
#arr = [10,2,7,12,4,5,5] 
arr = [10,7,8,9,1,5,5] 
n = len(arr) 
quickSort(arr,0,n-1) 
print ("Sorted array is:") 
print (arr)
print(" Swaps: ", contador)
print(" Comparaciones: ", comparaciones)

