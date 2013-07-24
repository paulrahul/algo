'''
Created on 24-Jul-2013

@author: rahul
'''

n = 100
sq_sum = (n * (n + 1) * (2 * n + 1)) / 6
sum_sq = ((n * (n + 1)) / 2) ** 2

print abs(sq_sum - sum_sq)