package main

import "fmt"

func PrintBits(n int) {
	if n == 0 {
		return
	}

	PrintBits(n / 2)
	if n%2 != 0 {
		fmt.Print("1")
	} else {
		fmt.Print("0")
	}
}

func countBits(n int) []int {
	ans := make([]int, n+1)

	ans[0] = 0

	if n > 0 {
		ans[1] = 1
	}

	lastPow := 1
	var diff int
	for i := 2; i <= n; i++ {
		if i/lastPow == 2 {
			// Next pow
			ans[i] = 1
			lastPow = i
			continue
		}

		diff = i - lastPow
		ans[i] = ans[lastPow] + ans[diff]
	}

	return ans
}

func main() {
	n := 2
	ans := countBits(n)

	for i := 0; i < n; i++ {
		fmt.Printf("%d -> ", i)
		PrintBits(i)
		fmt.Printf(" (%d)", ans[i])
		fmt.Println()
	}
}
