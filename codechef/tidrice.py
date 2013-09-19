t = int(raw_input())
while t > 0:
	t -= 1

	n = int(raw_input())
	m = {}

	for i in range(0, n):
		[s, v] = raw_input().split()

		vc = 1
		if v == '-':
			vc = -1
		m[s] = vc 

	ans = 0
	for k in m.values():
		ans += k
	
	print ans
