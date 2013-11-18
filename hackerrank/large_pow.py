# Hackerrank November 20/20 - Large Powers
# Modular exponentiation. O(logE) runtime. Timing out on last 5 test cases.

def mypow(a, b):
    mod = 10 ** 9 + 7
    r = 1
    while b > 0:
        if b % 2 == 1:
            r = (r * a) % mod
        b >>= 1
        a = (a * a) % mod
    return r

t = int(raw_input())
while t > 0:
    t -= 1
    [a, b] = [int(x) for x in raw_input().split()]
    print mypow(a, b)
