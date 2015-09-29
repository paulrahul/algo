t = int(raw_input())
while t > 0:
    t -= 1
    (b, ls) = [int(x) for x in raw_input().split()]
    
    rs1 = (ls ** 2 - b ** 2) ** 0.5
    rs2 = (ls ** 2 + b ** 2) ** 0.5

    print "%.2f %.2f" % (rs1, rs2)
    
    