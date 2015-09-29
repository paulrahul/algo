t = int(raw_input())
while t > 0:
    t -= 1
    s = raw_input()
    
    h = len(s) + 1
    
    ns = 0
    if h % 2 == 0:
        eh = h / 2 - 1
        nn = 2 * ((4 ** eh - 1) / 3)
        ns = 4 + (nn - 1) * 2
    else:
        oh = h / 2
        nn = ((4 ** oh - 1) / 3)
        ns = 3 + (nn - 1) * 2
        
    idx = 1
    for c in s:
        if c == 'l':
            idx = idx * 2
        else:
            idx = idx * 2 + 1
            
    x = (idx - (2 ** (h - 1))) + 1
    #print idx, x
    ans = ns + (x - 1) * 2
    ans = ans % (10 ** 9 + 7)
    print ans
    