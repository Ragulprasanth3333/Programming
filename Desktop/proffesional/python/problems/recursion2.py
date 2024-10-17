from  typing import *

def printNtimes(n: int,count = 0) -> List[str]:
    if count == n:
        return []
    else :
        print("coding Ninjas")
        printNtimes(n, count + 1)
printNtimes(5)