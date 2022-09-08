// abcbea

func isPalindrome(s string, l, r int) bool {
	if l > r {
		return false
	}

	if l < 0 || r >= len(s) {
		return false
	}

	for {
		if l >= r {
			return true
		}

		if s[l] != s[r] {
			break
		}

		l += 1
		r -= 1
	}

	return false
}

func validPalindrome(s string) bool {
	l := len(s)

	i := 0
	j := l - 1
	for {
		if i >= j {
			break
		}

		if s[i] != s[j] {
			// Continue with either of these conditions:
			// 1. s[i] == s[j - 1], OR
			// 2. s[i + 1] == s[j]

			isPal := isPalindrome(s, i, j-1) || isPalindrome(s, i+1, j)
			return isPal
		}

		i += 1
		j -= 1
	}

	if i >= j {
		return true
	}

	return false
}