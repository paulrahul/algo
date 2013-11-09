mod = 10 ** 9 + 7 

# O(logE)
def mypow(e):
 	base = 2
	result = 1
	while e > 0:
		if e % 2 == 1:
			result = (result * base) % mod
		e >>= 1
		base = (base * base) % mod

	return result


t = int(raw_input())
while t > 0:
	t -= 1
	n = int(raw_input())
	ans = mypow(n) - 1
	print ans
