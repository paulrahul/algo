package main

import (
	"fmt"
	"sort"
)

func dump(kChunkCount map[int]int, numCount map[int]int, begin int, end int, num int, halfCount int, leaderCount int) {
	fmt.Printf("kChunkCount: %v\n", kChunkCount)
	fmt.Printf("numCount: %v\n", numCount)
	fmt.Printf("leadercount %d against halfcount %d in range [%d, %d] for num %d\n\n", leaderCount, halfCount, begin, end, num)
}

func Solution(k int, m int, arr []int) []int {
	// fmt.Println(arr)
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
	var leaderCount int
	halfCount := n/2 + 1
	var leader int
	for i := 0; i < k; i++ {
		num = arr[i]
		if _, ok := kChunkCount[num]; !ok {
			kChunkCount[num] = 0
		}
		kChunkCount[num]++

		leaderCount = 0
		leaderCount += kChunkCount[num]
		leaderCount += numCount[num+1]
		dump(kChunkCount, numCount, 0, k-1, num, halfCount, leaderCount)
		if leaderCount >= halfCount {
			leader = num + 1
			previousKAns[leader] = true
		}
	}

	ans := make(map[int]bool)
	if len(previousKAns) == 1 {
		fmt.Printf("Leader %d for range [%d, %d]\n", leader, 0, k-1)
		ans[leader] = true
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
		leaderCount = 0
		leaderCount += kChunkCount[num]
		leaderCount += numCount[num+1]
		dump(kChunkCount, numCount, begin, begin+k-1, num, halfCount, leaderCount)
		if leaderCount >= halfCount {
			leader = num + 1
			previousKAns[leader] = true
		} else if _, ok := previousKAns[num+1]; ok {
			delete(previousKAns, num+1)
		}

		// Then the new end.
		num = arr[begin+k-1]
		leaderCount = 0
		leaderCount += kChunkCount[num]
		leaderCount += numCount[num+1]
		dump(kChunkCount, numCount, begin, begin+k-1, num, halfCount, leaderCount)
		if leaderCount >= halfCount {
			leader = num + 1
			previousKAns[leader] = true
		} else if _, ok := previousKAns[num+1]; ok {
			delete(previousKAns, num+1)
		}

		if len(previousKAns) == 1 {
			fmt.Printf("Leader %d for range [%d, %d]\n", leader, begin, begin+k-1)
			ans[leader] = true
		}
	}

	keys := make([]int, 0, len(ans))
	for k := range ans {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	return keys
}

func main() {
	fmt.Println(Solution(3, 5, []int{2, 1, 3, 1, 2, 2, 3}))
	// fmt.Println(Solution(4, 2, []int{1, 2, 2, 1, 2}))
	// fmt.Println(Solution(5, 2, []int{1, 2, 2, 1, 2}))
	// fmt.Println(Solution(5, 2, []int{1, 1, 1, 1, 1}))
	// fmt.Println(Solution(5, 2, []int{2, 2, 2, 2, 2}))
	// fmt.Println(Solution(1, 2, []int{1}))
	// fmt.Println(Solution(1, 2, []int{2}))
}
