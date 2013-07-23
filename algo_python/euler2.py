s = 2
n = 3
p = 2
lim = 4 * (10 ** 6)

while n < lim:
    if n % 2 == 0:
        s += n
        
    n += p
    p = n - p
    
print s