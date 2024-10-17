def mergesort(arr):
    if len(arr) > 1:
        middle = len(arr) // 2
        left = arr[:middle]
        right = arr[middle:]

        mergesort(left)
        mergesort(right)

        lp = 0
        rp = 0
        fp = 0

        # Merge the sorted halves back into arr
        while lp < len(left) and rp < len(right):
            if left[lp] < right[rp]:
                arr[fp] = left[lp]
                lp += 1
            else:
                arr[fp] = right[rp]
                rp += 1
            fp += 1

        # Copy the remaining elements of left and right back into arr
        while lp < len(left):
            arr[fp] = left[lp]
            fp += 1
            lp += 1

        while rp < len(right):
            arr[fp] = right[rp]
            fp += 1
            rp += 1

arr = [1, 7, 9, 2, 5]
mergesort(arr)
print(arr)  
