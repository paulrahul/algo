t = int(raw_input())
while t > 0:
    t -= 1
    n = int(raw_input())
    p = (n - 1) / 2 + 2
    ans = 2 ** p - 1
    if n % 2 == 1:
        ans -= 1 
    
    print ans