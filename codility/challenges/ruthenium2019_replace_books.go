/*
Solution for https://app.codility.com/programmers/challenges/ruthenium2019/

R - O(N^3)
S - O(N^2)

*/

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
	n := len(arr)

	numIndices := make(map[int][]int)
	for i, num := range arr { // O(N)
		numIndices[num] = append(numIndices[num], i)
	}

	// Now find the best solution for each unique number in the original array.
	// i.e. for each number, what is the max. continous sequence that we can
	// get with at most k replacements. We will use a greedy approach iterating
	// over every possible starting gap sequence.
	ans := 1
	for num := range numIndices { // O(M)
		indices := numIndices[num]
		l := len(indices)

		var currentGap int
		var currentGapDelta int
		for begin := range indices { // O(N)
			numUsed := 0
			total := 0
			terminated := false
			for i := begin; !terminated && i < l && numUsed <= k; i++ { // O(N)
				// Consider the most of the current gap.
				if i == 0 {
					currentGap = indices[i]
					total++ // For the one occurrence of num

					if currentGap <= k-numUsed {
						currentGapDelta = currentGap
					} else {
						currentGapDelta = k - numUsed
						terminated = true
					}
				} else {
					currentGap = indices[i] - indices[i-1] - 1

					if currentGap <= k-numUsed {
						if total == 0 {
							total += 2 // Since the edges have not been considered earlier.
						} else {
							total++ // Only the second edge will be added.
						}
						currentGapDelta = currentGap
					} else {
						if total == 0 {
							total++
						}
						// The entire gap cannot be used. So we will use the
						// max possible as we are being greedy.
						currentGapDelta = k - numUsed
						terminated = true
					}
				}
				total += currentGapDelta
				numUsed += currentGapDelta
			} // for i

			// Consider the trailing gap too.
			if !terminated {
				currentGap = n - 1 - indices[l-1]
				if currentGap <= k-numUsed {
					currentGapDelta = currentGap
				} else {
					currentGapDelta = k - numUsed
					terminated = true
				}
				total += currentGapDelta
				numUsed += currentGapDelta
			}

			ans = max(ans, total)
		} // for begin
	} // for num - total O(M * N * N)

	return ans
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
		{[]int{1, 2, 3, 2, 3, 1}, 1},
		{[]int{1}, 1},
		{[]int{1, 2, 2, 1}, 1},
		{[]int{1, 2, 3, 2, 1}, 1},
		{[]int{1, 2, 3, 2, 1}, 2},
		{[]int{1, 2, 3, 2, 1}, 3},
	}

	for _, v := range inp {
		fmt.Printf("%v: %d\n", v, Solution(v.arr, v.k))
	}
}
