from typing import List

def selectionSort(arr: List[int]) -> List[int]: 
    n = len(arr)
    for i in range(n - 1):
        minval = i
        for j in range(i + 1, n):
            if arr[j] < arr[minval]:
                minval = j
        arr[i], arr[minval] = arr[minval], arr[i]
    return arr
