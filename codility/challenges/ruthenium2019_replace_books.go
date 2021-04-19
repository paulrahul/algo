package main

import (
	"fmt"
)

func max(nums ...int) int {
	mx := -1
	for _, x := range nums {
		if x > mx {
			mx = x
		}
	}

	return mx
}

type MaxSameNums struct {
	nums []int
}

func computeRange(
	arr []int, k int, kDeficit int,
	maxSame [][]MaxSameNums, ans [][]int, freq map[int]int) {

	begin := 0
	end := k - 1
	// Compute the first k chunk.
	maxSame[begin][end] = MaxSameNums{[]int{arr[begin]}}
	freq[arr[begin]] = 1
	mx := 1
	var num int
	for i := 1; i < k; i++ {
		num = arr[i]
		if _, ok := freq[num]; !ok {
			freq[num] = 0
		}
		freq[num]++
		mx = max(mx, freq[num])
	}

	for i := 0; i < k; i++ {
		num = arr[i]
		if freq[num] == mx {
			maxSame[begin][end].nums = append(maxSame[begin][end].nums, num)
		}
	}

	n := len(arr)
	if mx >= kDeficit {
		ans[begin][end] = k + kDeficit
	} else {
		ans[begin][end] = k + 1
	}

	// Compute the rest of the k chunks by sliding the window by 1 each time.
	for begin := 1; begin <= n-k; begin++ {
		end := begin + k - 1
		freq[arr[begin-1]]--
		num = arr[end]
		if _, ok := freq[num]; !ok {
			freq[num] = 0
		}
		freq[num]++

		candidates := []int{freq[arr[begin-1]], freq[arr[end]]}
		for _, c := range maxSame[begin-1][end-1].nums {
			candidates = append(candidates, c)
		}

		mx = max(candidates...)
		maxSame[begin][end] = MaxSameNums{[]int{}}
		for _, c := range candidates {
			if freq[c] == mx {
				maxSame[begin][end].nums = append(maxSame[begin][end].nums, c)
			}
		}

		if mx >= kDeficit {
			ans[begin][end] = k + kDeficit
		} else {
			ans[begin][end] = k + 1
		}
	}
}

func Solution(arr []int, k int) int {
	n := len(arr)

	if n <= k+1 {
		return n
	}

	maxSame := make([][]MaxSameNums, n)
	ans := make([][]int, n)
	for i := 0; i < n; i++ {
		maxSame[i] = make([]MaxSameNums, n)
		ans[i] = make([]int, n)
	}

	freq := make(map[int]int)

	// Now keep computing larger chunks iteratively.
	for l := k + 2; l <= n; l++ {
		computeRange(arr, l, l-k, maxSame, ans, freq)
	}

	return ans[0][n-1]
}

func main() {
	inp := []struct {
		arr []int
		k   int
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
