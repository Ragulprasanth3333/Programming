arr = [1,10,11,5,7,12,10]
while True:
    a = True
    for j in range(0,len(arr)-1):
        if arr[j] > arr[j+1]:
            arr[j],arr[j+1] = arr[j+1],arr[j]
            a = False
    if a == True:
        break
print(arr)

