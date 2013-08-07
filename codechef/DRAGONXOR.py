def cbits(n):
    c = 0
    while n > 0:
        if n & 1 == 1:
            c += 1
        n >>= 1

    return c

t = int(raw_input())
while t > 0:
    t -= 1
    [n, a, b] = [int(x) for x in raw_input().split()]
    na = cbits(a)
    nb = cbits(b)
    
    x = 0
    if na + nb <= n:
        x = n - (na + nb)
    else:
        x = na + nb - n
    
    ans = 2 ** n - 2 ** x
    print ans
    