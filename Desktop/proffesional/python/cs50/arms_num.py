def Armstrong_number(n):
    s = str(n)
    po = len(s)
    ls = []
    for i in s:
        ls.append(int(i) ** po)
    if sum(ls) == n:
        print("true")
    else:
        print("false")


Armstrong_number(1634)
