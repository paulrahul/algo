from math import ceil

t = int(raw_input())
while t > 0:
    t -= 1
    (n, m) = (int(x) for x in raw_input().split())
    
    if n == 1 and m == 1:
        print "0/1"
    elif n % 2 == 0 or m % 2 == 0:
        print "1/2"
    else:
        # O.E
        n1 = int(ceil(float(n) / 2)) * (m / 2)
    
        # E.O
        n2 = (n / 2) * int(ceil(float(m) / 2))
    
        num = n1 + n2
        den = n * m
        print "%d/%d" % (num, den)