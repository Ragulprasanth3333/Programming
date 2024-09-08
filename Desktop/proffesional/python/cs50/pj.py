def sumOfAllDivisors(n: int) -> int:
    ls = []
    for i in range(1,n+1):
        if n%i == 0:
            ls.append(i)
    su = sum(ls)
    print(su)
sumOfAllDivisors(5)
print(6%6)