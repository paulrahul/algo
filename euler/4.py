'''
Created on 24-Jul-2013

@author: rahul
'''

from math import log10
from math import ceil

def countDigits(n):
    return int(log10(n) + 1)

def isGoodPal(n):
    start = int(ceil(n ** 0.5))
    
    while start >= 100:
        if n % start == 0:
            if countDigits(n / start) == 3:
                print start, n / start
                return True
    
        start -= 1

    return False


def getNextPal(n):
    d = countDigits(n)
    h = int(ceil(d / 2))
    
    l = list(str(n / 10 ** (d / 2)))
    decreased = False
    i = h - 1
    while decreased == False:
        if l[i] == '0':
            l[i] = '9'
        else:
            l[i] = chr(ord(l[i]) - 1)
            decreased = True
        
        i -= 1
        
    l = l + l[::-1]
    return int(''.join(l))

start = 999999
while isGoodPal(start) == False:
    start = getNextPal(start)

print start
    
        