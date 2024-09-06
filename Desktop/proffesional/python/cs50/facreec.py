from typing import List

def factorialNumbers(n: int, i: int = 1) -> List[int]:
    def factorial(num: int) -> int:
        if num == 0 or num == 1:
            return 1
        else:
            return num * factorial(num - 1)

    if factorial(i) <= n:
        return [factorial(i)] + factorialNumbers(n, i + 1)
    else:
        return []