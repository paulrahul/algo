c = {}

m = 1
ans = 1
lim = 10 ** 6
for i in range(2, lim):
	l = 0
	n = i
	while n != 1:
		if c.has_key(n):
			l += c[n]
			break

		l += 1
		if n % 2 == 0:
			n /= 2
		else:
			n = 3 * n + 1

	c[i] = l
	if l > m:
		m = l
		ans = i

print ans
