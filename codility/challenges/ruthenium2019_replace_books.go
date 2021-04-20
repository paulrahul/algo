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

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

type MaxSameNums struct {
	nums map[int]bool
}

func computeRange(
	arr []int, l int, kDeficit int,
	maxSame [][]MaxSameNums, ans [][]int, freq map[int]int) {

	begin := 0
	end := l - 1
	// Compute the first k chunk.
	freq[arr[begin]] = 1
	mx := 1
	var num int
	for i := 1; i <= end; i++ {
		num = arr[i]
		freq[num]++
		mx = max(mx, freq[num])
	}

	maxSame[begin][end] = MaxSameNums{map[int]bool{}}
	for i := 0; i <= end; i++ {
		num = arr[i]
		if freq[num] == mx {
			maxSame[begin][end].nums[num] = true
		}
	}

	n := len(arr)
	k := l - kDeficit
	mxCombination := min(l, mx+k)
	ans[begin][end] = max(mxCombination, k+1)

	// Compute the rest of the k chunks by sliding the window by 1 each time.
	for begin := 1; begin <= n-l; begin++ {
		end := begin + l - 1

		freq[arr[begin-1]]--
		num = arr[end]
		freq[num]++

		candidateFreq := []int{freq[arr[begin-1]], freq[arr[end]]}
		candidates := []int{arr[begin-1], arr[end]}
		for c := range maxSame[begin-1][end-1].nums {
			candidateFreq = append(candidateFreq, freq[c])
			candidates = append(candidates, c)
		}

		mx = max(candidateFreq...)
		maxSame[begin][end] = MaxSameNums{map[int]bool{}}
		for _, c := range candidates {
			if freq[c] == mx {
				maxSame[begin][end].nums[num] = true
			}
		}
		mxCombination = min(l, mx+k)
		ans[begin][end] = max(mxCombination, k+1)
	}
}

func Solution(arr []int, k int) int {
	n := len(arr)

	if k >= n-1 {
		// For both k = n or k = n - 1, we can make the entire array the same.
		return n
	}

	maxSame := make([][]MaxSameNums, n)
	ans := make([][]int, n)
	for i := 0; i < n; i++ {
		maxSame[i] = make([]MaxSameNums, n)
		ans[i] = make([]int, n)
	}

	var freq map[int]int
	// Now keep computing larger chunks iteratively.
	for l := k + 2; l <= n; l++ {
		freq = make(map[int]int)
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
