package main

import (
	"fmt"
)

func max(x, y int) int {
	if x > y {
		return x
	}

	return y
}

func Solution(arr []int, k int) int {
	curr_start_idx := 0
	next_start_idx := 1
	ans := 1
	used_k := 0

	n := len(arr)

	// Left to right.
	i := 1
	for i < n {
		if arr[i] != arr[curr_start_idx] {
			if used_k == 0 {
				next_start_idx = i
			}

			if used_k < k {
				used_k++
			} else {
				ans = max(ans, i - curr_start_idx)
				curr_start_idx = next_start_idx
				i = next_start_idx
				used_k = 0

				// Check if there are enough remaining elements to exceed ans
				if n - i <= ans {
					break
				}				
			}
		}
		i++
	}

	// Check the trailing bit.
	ans = max(ans, i - curr_start_idx)

	// Now do the same but right to left.
	curr_start_idx = n - 1
	next_start_idx = n - 2
	used_k = 0

	i = n - 2
	for i >= 0 {
		if arr[i] != arr[curr_start_idx] {
			if used_k == 0 {
				next_start_idx = i
			}

			if used_k < k {
				used_k++
			} else {
				ans = max(ans, curr_start_idx - i)
				curr_start_idx = next_start_idx
				i = next_start_idx
				used_k = 0

				// Check if there are enough remaining elements to exceed ans
				if i + 1 <= ans {
					break
				}				
			}
		}
		i--
	}

	// Check the trailing bit.
	ans = max(ans, curr_start_idx - i)

	return ans
}

func main() {
	inp := []struct {
		arr []int
		k int
	}{
		{[]int{1, 1, 3, 4, 3, 3, 4}, 2},
		{[]int{4, 5, 5, 4, 2, 2, 4}, 0},
		{[]int{1, 3, 3, 2}, 2},
		{[]int{1}, 2},
		{[]int{1, 1, 1, 1}, 2},
		{[]int{1, 2, 2, 2}, 2},
		{[]int{1, 2, 2, 2}, 0},
		{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2},
	}

	for _, v := range inp {
		fmt.Printf("%v: %d\n", v, Solution(v.arr, v.k))
	}
}