// https://app.codility.com/programmers/task/leader_slice_inc/
// Given an array, find all its elements that can become a leader, after
// increasing by 1 all of the numbers in some segment of a given length.
//
// Linear solution used here: R - O(M), S - O(M)
// Gist of the algo:
// 1. Compute the solution for the first k-window (0..k-1)
// 2. Then in each iteration, slide the window by 1 place and recompute the
//    leader value in previous's first position (the index going out) and the
//    new window's last position (the index coming in).

package main

import (
	"fmt"
	"sort"
)

func computeLeader(
	kChunkCount map[int]int, numCount map[int]int, previousKAns map[int]bool,
	halfCount int, leader int) {
	leaderCount := 0
	leaderCount += kChunkCount[leader-1]
	leaderCount += numCount[leader]
	if leaderCount >= halfCount {
		previousKAns[leader] = true
	} else if _, ok := previousKAns[leader]; ok {
		delete(previousKAns, leader)
	}
}

func Solution(k int, m int, arr []int) []int {
	n := len(arr)

	numCount := make(map[int]int)
	var num int
	// Process arr entried k..n-1 as we'll start considering our k-chunks from
	// 0..k-1
	for i := k; i < n; i++ {
		num = arr[i]
		if _, ok := numCount[num]; !ok {
			numCount[num] = 0
		}
		numCount[num]++
	}

	// Process the first k-chunk starting from 0...k-1
	kChunkCount := make(map[int]int)
	previousKAns := make(map[int]bool)
	halfCount := n/2 + 1
	for i := 0; i < k; i++ {
		num = arr[i]
		if _, ok := kChunkCount[num]; !ok {
			kChunkCount[num] = 0
		}
		kChunkCount[num]++

		computeLeader(kChunkCount, numCount, previousKAns, halfCount, num+1)
	}

	ans := make(map[int]bool)
	if len(previousKAns) == 1 {
		for ansKey := range previousKAns {
			ans[ansKey] = true
		}
	}

	// Now start evaluating each k-chunk for being a candidate in the final
	// answer. For each chunk, we discard the first entry from the previous
	// chunk and add it back to the global count, and, we discard the last
	// entry of the current chunk from the global count and add it to the
	// k-chunk count.
	for begin := 1; begin <= n-k; begin++ {
		// Discard previous beginning.
		kChunkCount[arr[begin-1]]--
		numCount[arr[begin-1]]++
		// Add new end.
		kChunkCount[arr[begin+k-1]]++
		numCount[arr[begin+k-1]]--

		// Recompute the two ends for the current k-chunk, starting with the
		// previous beginning.
		num = arr[begin-1]
		computeLeader(kChunkCount, numCount, previousKAns, halfCount, num+1)
		computeLeader(kChunkCount, numCount, previousKAns, halfCount, num)

		// Then the new end.
		num = arr[begin+k-1]
		computeLeader(kChunkCount, numCount, previousKAns, halfCount, num+1)
		computeLeader(kChunkCount, numCount, previousKAns, halfCount, num)

		if len(previousKAns) == 1 {
			for ansKey := range previousKAns {
				ans[ansKey] = true
			}
		}
	}

	keys := make([]int, 0, len(ans))
	for ansKey := range ans {
		keys = append(keys, ansKey)
	}
	sort.Ints(keys)

	return keys
}

func main() {
	fmt.Println(Solution(3, 5, []int{2, 1, 3, 1, 2, 2, 3}))
	fmt.Println(Solution(4, 2, []int{1, 2, 2, 1, 2}))
	fmt.Println(Solution(5, 2, []int{1, 2, 2, 1, 2}))
	fmt.Println(Solution(5, 2, []int{1, 1, 1, 1, 1}))
	fmt.Println(Solution(5, 2, []int{2, 2, 2, 2, 2}))
	fmt.Println(Solution(1, 2, []int{1}))
	fmt.Println(Solution(1, 2, []int{2}))
	fmt.Println(Solution(1, 5, []int{1, 2, 3, 4, 5}))
}
