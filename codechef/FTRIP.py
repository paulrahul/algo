def c(n, k):
	if n < k:
		return 0
	if n == k:
		return 1
		
	if n <= 0 or k <= 0:
		return 0
	
	num = 1
	while n > k:
		num *= n
		n -= 1
	
	den = 1
	while k > 1:
		den *= k
		k -= 1
	
	return num / den

def find_prob(s, n, m, k):
	if s == n:
		return 1
	
	av_spots = n - 1
	if av_spots < k:
		return 0

	m -= 1
	lim = (m, av_spots)[av_spots < m]
	
	sum = 0
	i = k
	while i <= lim:
		sum += c(lim, i) * c(s - 1, i) * c(s - 1 - i, n - i)
		i += 1
		
	print ("%.6f", (1 / sum))
	
t = int(raw_input())
while t > 0:
	s = int(raw_input())
	n = int(raw_input())
	m = int(raw_input())
	k = int(raw_input())
	
	find_prob(s, n, m, k)