def gcd(a, b):
	if b > a:
		t = a
		a = b
		b = t

	while b > 0:
		t = a % b
		a = b
		b = t

	return a


t = int(raw_input())
while t > 0:
	t -= 1
	
	inp = [int(x) for x in raw_input().split()]
	
	n = inp[0]
	g = inp[1]
	
	for i in range(2, n + 1):
		g = gcd(g, inp[i])

	s = ""
	for i in range(1, n):
		s += str(inp[i] / g) + " "

	s += str(inp[n] / g)
	print s
