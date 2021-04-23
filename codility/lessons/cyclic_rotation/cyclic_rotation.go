package main

import "fmt"

func Solution(arr []int, k int) []int {
	n := len(arr)
	if n == 0 {
		return []int{}
	}

	k = k % n

	ans := make([]int, n)
	i := 0
	for j := n - k; j < n; j++ {
		ans[i] = arr[j]
		i++
	}

	for j := 0; j < n-k; j++ {
		ans[i] = arr[j]
		i++
	}

	return ans
}

func main() {
	fmt.Println(Solution([]int{3, 8, 9, 7, 6}, 3))
	fmt.Println(Solution([]int{0, 0, 0}, 1))
	fmt.Println(Solution([]int{1, 2, 3, 4}, 4))
	fmt.Println(Solution([]int{3, 8, 9, 7, 6}, 14))
}
