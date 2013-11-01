t = int(raw_input())

while t > 0:
	t -= 1
	n = int(raw_input())

	s = n / 7

	while s >= 0:
		if s > 0:
			f = n - (s * 7)
		else:
			f = n

		if f % 4 == 0:
			break
		s -= 1


	if s < 0:
		print -1
	else:
		print s * 7
	
