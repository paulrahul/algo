n = int(raw_input())
num = 0
for i in range(0, n):
    t = int(raw_input())
    num += t

print "%.1f" % (num / float(2))