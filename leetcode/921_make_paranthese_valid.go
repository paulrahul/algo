func minAddToMakeValid(s string) int {
	nOB := 0
	nCB := 0

	n := len(s)
	for i := 0; i < n; i++ {
		if s[i] == '(' {
			nOB += 1
		} else {
			if nOB > 0 {
				nOB -= 1
			} else {
				nCB += 1
			}
		}
	}

	return nOB + nCB
}