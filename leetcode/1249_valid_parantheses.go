package main

import (
	"fmt"
	"strings"
)

func minRemoveToMakeValid(s string) string {
	n := len(s)
	isInvalid := make([]bool, n)

	// Right to left check with close bracket.
	nCB := 0
	for i := n - 1; i >= 0; i-- {
		if s[i] == '(' {
			if nCB == 0 {
				isInvalid[i] = true
			} else {
				nCB -= 1
			}
		} else if s[i] == ')' {
			nCB += 1
		}
	}

	// Left to right check with open bracket.
	nOB := 0
	for i := 0; i < n; i++ {
		if s[i] == ')' {
			if nOB == 0 {
				isInvalid[i] = true
			} else {
				nOB -= 1
			}
		} else if s[i] == '(' {
			nOB += 1
		}
	}

	var ret strings.Builder
	for i := 0; i < n; i++ {
		if !isInvalid[i] {
			ret.WriteByte(s[i])
		}
	}
	return ret.String()
}

func main() {
	fmt.Println(minRemoveToMakeValid("abc"))
	fmt.Println(minRemoveToMakeValid("lee(t(c)o)de)"))
	fmt.Println(minRemoveToMakeValid("a)b(c)d"))
	fmt.Println(minRemoveToMakeValid("))(("))
}
