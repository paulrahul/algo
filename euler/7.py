'''
Created on 26-Jul-2013

@author: rahul
'''

from math import sqrt

lim = 10000000
isPrime = [True] * (lim + 1)
cnt = 0
for i in range (2, lim + 1):
    if isPrime[i] == False:
        continue
    
    cnt += 1
    if cnt == 10001:
        print i
        break
    
    for j in xrange(i * 2, lim + 1, i):
        isPrime[j] = False
        
print cnt
    