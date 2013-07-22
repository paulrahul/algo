import re
 
def fi(n): 
    result = n 
    i = 2
    while i * i <= n:
        if n % i == 0:
            result -= result / i 
        while n % i == 0:
            n /= i
 
        if n > 1:
            result -= result / n
       
        return result 
 
 
def isprime1(n):
        return re.match(r'^1?$|^(11+?)\1+$', '1' * n) == None
 
def isprime(n):
    if n < 2:
        return False;
 
    if n == 2 or n == 3:
        return True;
 
    if n % 2 == 0 or n %3 ==0:
        return False
 
 
    root = n ** 0.5 + 1
    i = 6
    while i <= root:
        if n % (i - 1) == 0 or n % (i + 1) == 0:
            return False
        i += 6
 
    return True
 
def findprime(l):
    for i in l:
        while True:
            if fi(i) == i - 1:
                break
            i -= 1
        print i
 
t = int(raw_input())
n = []
for i in range(t):
    j = long(raw_input())
    n.append(j)
 
findprime([6,1000000000000000000])