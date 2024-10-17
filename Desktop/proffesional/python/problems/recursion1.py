from typing import List
import array

from typing import List
import array

def printNos(x: int, count=0, arr=None) -> List[int]:
    if arr is None:
        arr = array.array("I", [])
        
    if x == count:
        return sorted(arr, reverse=True)
    else:
        arr.append(count + 1)
        return printNos(x, count + 1, arr)


    

printNos(5)
