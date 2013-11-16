def calc_num(arr, n):
    lim = 2 ** n
    ans = 0
    for i in xrange(0, lim):
        j = 0
        x = i
        s = 0
        while x > 0:
            if x & 1:
                s += arr[j]
            x >>= 1
            j += 1
        ans += s
    return ans

n = int(raw_input())
arr = []
for i in range(0, n):
    t = int(raw_input())
    arr.append(t)

num = calc_num(arr, n)
den = 2 ** n
#print num, den
print "%.1f" % (num / float(den))
