from math import ceil, floor;

def dist(x1, y1, x2, y2):
    if x1 == x2 and y1 == y2:
        return 0
    
    if x1 != x2 and y1 != y2:
        x = abs(x1 - x2)
        y = abs(y1 - y2)
        
        s = min(x, y)
        return 2 * s + dist(s, s, x, y)
    
    if x1 == x2 and y1 != y2:
        s = abs(y1 - y2)
        return s + int(floor(float(s) / 2)) * 2

    if x1 != x2 and y1 == y2:
        s = abs(x1 - x2)
        return s + int(ceil(float(s) / 2)) * 2

t = int(raw_input())
while t > 0:
    t -= 1
    (x, y) = [int(f) for f in raw_input().split()]
    
    #print x, y
    print dist(0, 0, x, y)