t = int(raw_input())
while t > 0:
    t -= 1
    (p, s) = [int(x) for x in raw_input().split()]
    
    x = p / 4
    y = s / 2

    a = 3
    b = -2 * x
    c = y
    
    d = ((b * b - 4 * a * c) ** 0.5)
    h1 = abs(float(-b + d) / (2 * a))
    h2 = abs(float(-b - d) / (2 * a))
    
    #print h1, h2
    
    v1 = h1 * (y - h1 * (x - h1))
    v2 = h2 * (y - h2 * (x - h2))
    
    v = max(v1, v2) 
    print "%.2f" % (v)
    