from typing import List

def selectionSort(arr: List[int]) -> None: 
    n = len(arr)
    for i in range(n):
        minval = i
        for j in range(i+1,n):
            if arr[j] < arr[minval]:
                minval = j
        arr[i], arr[minval] = arr[minval], arr[i]
    return arr