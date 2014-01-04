t = int(raw_input())
while t > 0:
    t -= 1
    [l, d, s, c] = [int(x) for x in raw_input().split()]
    
    live = False
    # Calculate Dth line
    p = 1
    cc = 1
    r = 0
    n = d - 1
    tm = 0
    while r < d:
        if r > 0:
            cc *= c
            p = (p * (n - r + 1)) / r
        tm += p * cc * s
        # print tm
        if tm >= l:
            live = True
            break
        r += 1  
    
    if live == True:
        print "ALIVE AND KICKING"
    else:
        print "DEAD AND ROTTING"