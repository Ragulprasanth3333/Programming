import random
def quicksort(arr):
    if len(arr)<=1:
        return arr
    piv = random.choice(arr)
    mid = [i for i in arr if i == piv]
    lef = [i for i in arr if i < piv]
    rig = [i for i in arr if i > piv]
    return quicksort(lef) + mid + quicksort(rig)
arr = [2 ,6 ,8 ,5 ,4 ,3]
quicksort(arr)
print(quicksort(arr))