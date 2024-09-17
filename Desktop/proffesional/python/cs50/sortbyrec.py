from typing import List

def reverseArray(n: int, nums: List[int], lis=None) -> List[int]:
    if lis is None:
        lis = []

    
    if not nums:
        return lis
    
    
    lis.append(nums.pop(-1))
    
    return reverseArray(n, nums, lis)
