from math import log10

def check(s):
	if s[0] == '0':
		return 0
	n = int(s)
	if n == 0:
		return 0
	elif n < 10:
		return 1
	elif n <= 26:
		return 1
	return 0

def count(num):
	if num == 0:
		return 0
	n = str(num)

	nd = int(log10(int(n)) + 1)
	cnt = [0] * nd
	
	cnt[nd - 1] = check(n[nd - 1:]) 
	if nd > 1:
		cnt[nd - 2] = check(n[nd - 2:]) + (check(n[nd - 2:nd - 1]) * cnt[nd - 1])

	for i in range(nd - 3, -1, -1):
		cnt[i] = (check(n[i:i + 1]) * cnt[i + 1]) + (check(n[i:i + 2]) * cnt[i + 2])
		# print i, cnt[i]

	return cnt[0]

n = int(raw_input())
while n != 0:
	print count(n)
	n = int(raw_input())
