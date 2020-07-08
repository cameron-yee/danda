from random import randrange
from sys import argv
from time import perf_counter

def merge(arr, left, middle, right):
    L = arr[left:middle+1]
    R = arr[middle+1:right+1]

    i = left
    li = 0
    ri = 0
    while li < len(L) and ri < len(R):
        if L[li] < R[ri]:
            arr[i] = L[li]
            li += 1
            i += 1
            continue
            
        arr[i] = R[ri]
        ri += 1
        i += 1

    while li < len(L):
        arr[i] = L[li]
        li += 1
        i += 1

    while ri < len(R):
        arr[i] = R[ri]
        ri += 1
        i += 1
 
        
def sort(arr, left, right):
    if left < right:
        middle = (right + left) // 2

        sort(arr, left, middle)
        sort(arr, middle + 1, right)

        merge(arr, left, middle, right)
       
    
def mergeSort(arr):
    sort(arr, 0, len(arr) - 1)


def getTestArray(number):
    arr = []
    for i in range(0, number):
        arr.append(randrange(0, 10))

    return arr
    

if __name__ == "__main__":
    number = argv[1]
    arr = getTestArray(int(number))

    #print(arr)

    start = perf_counter()
    mergeSort(arr)
    end = perf_counter()

    #print(arr)
    print(f'Time: {(end - start)}s')
