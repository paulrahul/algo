'''
Created on 29-Jul-2013

@author: rahul
'''

def GetNumFactors(n):
    i = 2
    ret = 1
    curr_count = 0
    
    while i <= n:
        if n % i == 0:
            curr_count += 1
            n /= i
            i -= 1
        elif curr_count > 0:
            ret *= (curr_count + 1)
            curr_count = 0
            
        i += 1
    
    if curr_count > 0:
        ret *= (curr_count + 1)   
    
    return ret

m = 0
n = 1
while True:
    s = (n * (n + 1)) / 2
    f = GetNumFactors(s)
    m = max(m, f)
    if f > 500:
        print n, f, s
        break
    n += 1