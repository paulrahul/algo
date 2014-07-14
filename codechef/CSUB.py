t = int(raw_input())
while t > 0:
    t -= 1
    n = int(raw_input())
    s = raw_input()
    
    e = [int(x) for x in s]
    ones = sum(e)
    ans = (ones * (ones + 1)) / 2
    print ans